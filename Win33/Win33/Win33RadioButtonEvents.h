#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace RadioButtonEvents {
        
        class SelectData {
        public:
            SelectData( bool selected )
            :
            mSelected( selected )
            { }
            ~SelectData( ) = default;
            
            bool isSelected( ) const {
                return mSelected;
            }
            
        private:
            bool mSelected;
        };
        typedef std::function<void( SelectData& )> SelectHandler;
        
        typedef Win33::Event<SelectHandler> Select;
        
    };
    
};