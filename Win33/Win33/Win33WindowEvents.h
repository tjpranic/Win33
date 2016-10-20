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
        
        typedef Event<>              Idle;
        typedef Event<>              Close;
        typedef Event<ResizeHandler> Resize;
        typedef Event<MoveHandler>   Move;
    };
};