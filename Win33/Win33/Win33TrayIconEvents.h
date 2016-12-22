#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace TrayIconEvents {
        
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
        
        typedef Win33::Event<ClickHandler> LeftClick;
        typedef Win33::Event<ClickHandler> RightClick;
        
    };
    
};