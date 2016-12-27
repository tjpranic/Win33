#pragma once

#include <functional>
#include <vector>
#include <algorithm>

namespace Win33 {
    
    class Application;
    
    class EventData {
    public:
        EventData            ( )                         = default;
        EventData            ( const EventData&  other ) = default;
        EventData            (       EventData&& other ) = default;
        EventData& operator= ( const EventData&  other ) = default;
        EventData& operator= (       EventData&& other ) = default;
        ~EventData           ( )                         = default;
    };
    
    template<class H>
    class Event {
    friend class Application;
    public:
        Event            ( )                     = default;
        Event            ( const Event&  other ) = delete;
        Event            (       Event&& other ) = default;
        Event& operator= ( const Event&  other ) = delete;
        Event& operator= (       Event&& other ) = default;
        ~Event           ( )                     = default;
        
        void addHandler( const H& handler ) {
            mEventHandlers.push_back( handler );
        }
        void removeHandler( const H& handler ) {
            mEventHandlers.erase(
                std::remove_if( mEventHandlers.begin( ), mEventHandlers.end( ), [&]( const H& h ) {
                    return handler.target<H>( ) == h.target<H>( );
                } )
            );
        }
        
        void operator+=( const H& handler ) {
            addHandler( handler );
        }
        void operator-=( const H& handler ) {
            removeHandler( handler );
        }
        
    protected:
        template<class D, typename = std::enable_if<std::is_base_of<EventData, D>::value>::type>
        void handle( D& data ) {
            //iterate in the order of latest added to first added
            for( auto& h = mEventHandlers.rbegin( ); h != mEventHandlers.rend( ); ++h ) {
                ( *h )( data );
                //this is to stop certain events (ones that erase event handlers) from triggering a crash
                if( mEventHandlers.empty( ) ) {
                    break;
                }
            }
        }
        
        std::vector<H> mEventHandlers;
    };
    
    class CancellableEventData : public EventData {
    public:
        CancellableEventData( )
        :
        mCancelled( false )
        { }
        CancellableEventData            ( const CancellableEventData&  other ) = default;
        CancellableEventData            (       CancellableEventData&& other ) = default;
        CancellableEventData& operator= ( const CancellableEventData&  other ) = default;
        CancellableEventData& operator= (       CancellableEventData&& other ) = default;
        ~CancellableEventData           ( )                                    = default;
        
        bool getCancelled( ) const {
            return mCancelled;
        }
        void setCancelled( bool cancelled ) {
            mCancelled = cancelled;
        }
        
    protected:
        bool mCancelled;
    };
    
    template<class H>
    class CancellableEvent : public Event<H> {
    friend class Application;
    public: 
        CancellableEvent            ( )                                = default;
        CancellableEvent            ( const CancellableEvent&  other ) = delete;
        CancellableEvent            (       CancellableEvent&& other ) = default;
        CancellableEvent& operator= ( const CancellableEvent&  other ) = delete;
        CancellableEvent& operator= (       CancellableEvent&& other ) = default;
        ~CancellableEvent           ( )                                = default;
        
    protected:
        template<class D, typename = std::enable_if<std::is_base_of<CancellableEventData, D>::value>::type>
        void handle( D& data ) {
            for( auto& h = mEventHandlers.rbegin( ); h != mEventHandlers.rend( ); ++h ) {
                ( *h )( data );
                //this is to stop certain events (ones that erase event handlers) from triggering a crash
                if( mEventHandlers.empty( ) ) {
                    break;
                }
                //stop propagating if event gets cancelled
                if( data.getCancelled( ) ) {
                    break;
                }
            }
        }
    };
    
};