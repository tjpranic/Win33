#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace CheckBoxEvents {
        
        class CheckData {
        public:
            CheckData( bool checked )
            :
            mChecked( checked )
            { }
            ~CheckData( ) = default;
            
            bool isChecked( ) const {
                return mChecked;
            }
            
        private:
            bool mChecked;
        };
        typedef std::function<void( CheckData& )> CheckHandler;
        
        typedef Win33::Event<CheckHandler> Check;
    };
    
};