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
    
    template
    <
        class Handler, //event handlers are a std::function that takes an event data reference
        class Data,    //event datas are derived from EventData marker class
        typename = typename std::enable_if<std::is_same<Handler, std::function<void( Data& )>>::value>::type,
        typename = typename std::enable_if<std::is_base_of<EventData, Data>::value>::type
    >
    class Event {
    friend class Application;
    public:
        Event            ( )                     = default;
        Event            ( const Event&  other ) = delete;
        Event            (       Event&& other ) = delete;
        Event& operator= ( const Event&  other ) = delete;
        Event& operator= (       Event&& other ) = delete;
        ~Event           ( )                     = default;
        
        void operator+=( const Handler& handler ) {
            mEventHandlers.push_back( handler );
        }
        void operator-=( const Handler& handler ) {
            mEventHandlers.erase(
                std::remove_if( mEventHandlers.begin( ), mEventHandlers.end( ), [&]( const H& h ) {
                    return handler.target<H>( ) == h.target<H>( );
                } )
            );
        }
        
    protected:
        void fire( Data& data ) {
            //iterate in the order of last added to first added
            for( auto& h = mEventHandlers.rbegin( ); h != mEventHandlers.rend( ); ++h ) {
                ( *h )( data );
                //this is to stop events that erase event handlers from triggering a crash
                if( mEventHandlers.empty( ) ) {
                    break;
                }
            }
        }
        
        std::vector<Handler> mEventHandlers;
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
    
    template<class Handler, class Data>
    class CancellableEvent : public Event<Handler, Data> {
    friend class Application;
    public: 
        CancellableEvent            ( )                                = default;
        CancellableEvent            ( const CancellableEvent&  other ) = delete;
        CancellableEvent            (       CancellableEvent&& other ) = delete;
        CancellableEvent& operator= ( const CancellableEvent&  other ) = delete;
        CancellableEvent& operator= (       CancellableEvent&& other ) = delete;
        ~CancellableEvent           ( )                                = default;
        
    protected:
        void fire( Data& data ) {
            for( auto& h = mEventHandlers.rbegin( ); h != mEventHandlers.rend( ); ++h ) {
                ( *h )( data );
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