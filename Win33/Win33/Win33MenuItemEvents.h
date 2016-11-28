#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace MenuItemEvents {
        
        class ClickData {
        public:
            ClickData( bool checked )
            :
            mChecked( checked )
            { }
            ~ClickData( ) = default;
            
            bool isChecked( ) const {
                return mChecked;
            }
            
        private:
            bool mChecked;
        };
        typedef std::function<void( ClickData& )> ClickHandler;
        
        typedef Event<ClickHandler> Click;
    };
    
};