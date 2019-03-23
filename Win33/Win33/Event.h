#pragma once

#include <algorithm>
#include <functional>
#include <vector>

#include "ComparableFunction.h"
#include "Error.h"

namespace Win33 {

    template<class Signature>
    class EventHandler : public ComparableFunction<Signature> {
    public:
        template<class Lambda>
        EventHandler( const Lambda& lambda )
        :
        ComparableFunction<Signature>( lambda )
        { }
    };

    template<class EventHandler>
    class Event {
    public:
        using Handler = EventHandler;

        Event            ( )                     = default;
        Event            ( const Event&  other ) = delete;
        Event            (       Event&& other ) = default;
        Event& operator= ( const Event&  other ) = delete;
        Event& operator= (       Event&& other ) = default;
        ~Event           ( )                     = default;

        void operator+=( const EventHandler& handler ) {
            const auto iterator = std::find( mEventHandlers.begin( ), mEventHandlers.end( ), handler );
            if( iterator != mEventHandlers.end( ) ) {
                throw EXCEPTION( L"Handler already added to event." );
            }
            mEventHandlers.push_back( handler );
        }
        void operator-=( const EventHandler& handler ) {
            const auto iterator = std::find( mEventHandlers.begin( ), mEventHandlers.end( ), handler );
            if( iterator == mEventHandlers.end( ) ) {
                throw EXCEPTION( L"Handler does not exist on event." );
            }
            mEventHandlers.erase( iterator );
        }

    protected:
        template<class... Data>
        void trigger( Data... data ) const {
            for( auto iterator = mEventHandlers.begin( ); iterator != mEventHandlers.end( ); ++iterator ) {
                const auto& handler = *iterator;
                handler( data... );
                if( mEventHandlers.empty( ) ) {
                    break;
                }
            }
        }

        std::vector<EventHandler> mEventHandlers;
    };

}

#define DECLARE_EVENT( name, signature, triggerer )                        \
    class name : public ::Win33::Event<::Win33::EventHandler<signature>> { \
    friend class triggerer;                                                \
    public:                                                                \
        name            ( )                    = default;                  \
        name            ( const name&  other ) = delete;                   \
        name            (       name&& other ) = default;                  \
        name& operator= ( const name&  other ) = delete;                   \
        name& operator= (       name&& other ) = default;                  \
        ~name           ( )                    = default;                  \
    };