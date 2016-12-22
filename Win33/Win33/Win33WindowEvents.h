#pragma once

#include "Win33Event.h"
#include "Win33Point.h"
#include "Win33Size.h"

namespace Win33 {
    
    namespace WindowEvents {
        
        class ResizeData {
        public:
            ResizeData( const Size& size )
            :
            mSize( size )
            { }
            ~ResizeData( ) = default;
            
            const Size& getSize( ) const {
                return mSize;
            }
            
        private:
            Size mSize;
        };
        typedef std::function<void( ResizeData& )> ResizeHandler;
        
        class MoveData {
        public:
            MoveData( const Point& position )
            :
            mPosition( position )
            { }
            ~MoveData( ) = default;
            
            const Point& getPosition( ) const {
                return mPosition;
            }
            
        private:
            Point mPosition;
        };
        typedef std::function<void( MoveData& )> MoveHandler;
        
        class ClickData {
        public:
            ClickData( const Point& position )
            :
            mPosition( position )
            { }
            ~ClickData( ) = default;
            
            const Point& getPosition( ) const {
                return mPosition;
            }
            
        private:
            Point mPosition;
        };
        typedef std::function<void( ClickData& )> ClickHandler;
        
        typedef Win33::Event<>              Close;
        typedef Win33::Event<ResizeHandler> Resize;
        typedef Win33::Event<MoveHandler>   Move;
        typedef Win33::Event<ClickHandler>  LeftClick;
        typedef Win33::Event<ClickHandler>  RightClick;
    };
};