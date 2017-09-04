#pragma once

#include <vector>
#include <algorithm>

#include "ComparableFunction.h"

namespace Win33 {
    
    class EventData {
    public:
        EventData            ( )                         = default;
        EventData            ( const EventData&  other ) = default;
        EventData            (       EventData&& other ) = default;
        EventData& operator= ( const EventData&  other ) = default;
        EventData& operator= (       EventData&& other ) = default;
        ~EventData           ( )                         = default;
    };
    
    template<class Signature>
    class EventHandler : public ComparableFunction<Signature> {
    public:
        using FunctionSignature = Signature;
        
        template<class Lambda>
        EventHandler( const Lambda& lambda )
        :
        ComparableFunction<Signature>( lambda )
        { }
    };
    
    template
    <
        class Handler,
        typename = typename std::enable_if<std::is_same<Handler, EventHandler<typename Handler::FunctionSignature>>::value>::type
    >
    class Event {
    friend class Application;
    public:
        Event            ( )                     = default;
        Event            ( const Event&  other ) = delete;
        Event            (       Event&& other ) = default;
        Event& operator= ( const Event&  other ) = delete;
        Event& operator= (       Event&& other ) = default;
        ~Event           ( )                     = default;
        
        void operator+=( const Handler& handler ) {
            const auto iterator = std::find( mEventHandlers.begin( ), mEventHandlers.end( ), handler );
            if( iterator != mEventHandlers.end( ) ) {
                throw std::runtime_error( "Handler already added to event." );
            }
            mEventHandlers.push_back( handler );
        }
        void operator-=( const Handler& handler ) {
            const auto iterator = std::find( mEventHandlers.begin( ), mEventHandlers.end( ), handler );
            if( iterator == mEventHandlers.end( ) ) {
                throw std::runtime_error( "Handler does not exist on event." );
            }
            mEventHandlers.erase( iterator );
        }
        
    protected:
        template<
            class Data,
            typename = typename std::enable_if<std::is_base_of<EventData, Data>::value>::type
        >
        void trigger( Data& data ) const {
            for( auto iterator = mEventHandlers.begin( ); iterator != mEventHandlers.end( ); ++iterator ) {
                const auto& handler = *iterator;
                handler( data );
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
    
    template
    <
        class Handler,
        typename = typename std::enable_if<std::is_same<Handler, EventHandler<typename Handler::FunctionSignature>>::value>::type
    >
    class CancellableEvent : public Event<Handler> {
    friend class Application;
    public: 
        CancellableEvent            ( )                                = default;
        CancellableEvent            ( const CancellableEvent&  other ) = delete;
        CancellableEvent            (       CancellableEvent&& other ) = default;
        CancellableEvent& operator= ( const CancellableEvent&  other ) = delete;
        CancellableEvent& operator= (       CancellableEvent&& other ) = default;
        ~CancellableEvent           ( )                                = default;
        
    protected:
        template
        <
            class Data,
            typename = typename std::enable_if<std::is_base_of<CancellableEventData, Data>::value>::type
        >
        void trigger( Data& data ) const {
            for( auto iterator = mEventHandlers.rbegin( ); iterator != mEventHandlers.rend( ); ++iterator ) {
                const auto& handler = *iterator;
                handler( data );
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