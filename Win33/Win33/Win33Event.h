#pragma once

#include <functional>
#include <vector>
#include <algorithm>

namespace Win33 {
    
    class Application;
    
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
        
    private:
        template<class D>
        void handle( D& data ) {
            for( auto& h = mEventHandlers.begin( ); h != mEventHandlers.end( ); ++h ) {
                ( *h )( data );
                //this is to stop close events (which erase event handlers) from triggering a crash
                if( mEventHandlers.empty( ) ) { break; }
            }
        }
        
        std::vector<H> mEventHandlers;
    };
    
};