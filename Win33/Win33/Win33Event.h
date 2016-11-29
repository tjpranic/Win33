#pragma once

#include <functional>
#include <vector>
#include <algorithm>

#include <Windows.h>

#define WM_IDLE ( WM_USER + 0x01 )

namespace Win33 {
    
    class Application;
    
    namespace Events {
        typedef std::function<void( )> Handler;
    };
    namespace WindowEvents {
        typedef std::function<void( )> Handler;
    };
    namespace ButtonEvents {
        typedef std::function<void( )> Handler;
    };
    namespace CheckBoxEvents {
        typedef std::function<void( )> Handler;
    };
    namespace LabelEvents {
        typedef std::function<void( )> Handler;
    };
    namespace RadioButtonEvents {
        typedef std::function<void( )> Handler;
    };
    namespace MenuEvents {
        typedef std::function<void( )> Handler;
    };
    namespace TrayIconEvents {
        typedef std::function<void( )> Handler;
    }
    
    template<class H = Events::Handler>
    class Event {
    public:
        Event( )
        :
        mEventHandlers( )
        { }
        Event( const Event&  other ) = delete;
        Event(       Event&& other )
        :
        mEventHandlers( std::move( other.mEventHandlers ) )
        { }
        Event& operator=( const Event&  other ) = delete;
        Event& operator=(       Event&& other ) {
            mEventHandlers = std::move( other.mEventHandlers );
            return *this;
        }
        ~Event( ) = default;
        
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
        
        //*
        void handle( ) {
            for( auto& h = mEventHandlers.begin( ); h != mEventHandlers.end( ); ++h ) {
                ( *h )( );
            }
        }
        //*
        template<class D>
        void handle( D& data ) {
            for( auto& h = mEventHandlers.begin( ); h != mEventHandlers.end( ); ++h ) {
                ( *h )( data );
            }
        }
        
    private:
        std::vector<H> mEventHandlers;
    };
    
};