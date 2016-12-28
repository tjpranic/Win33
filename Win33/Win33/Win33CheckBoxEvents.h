#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace CheckBoxEvents {
        
        class CheckData : public EventData {
        public:
            CheckData( bool checked )
            :
            mChecked( checked )
            { }
            CheckData            ( )                         = delete;
            CheckData            ( const CheckData&  other ) = default;
            CheckData            (       CheckData&& other ) = default;
            CheckData& operator= ( const CheckData&  other ) = default;
            CheckData& operator= (       CheckData&& other ) = default;
            ~CheckData           ( )                         = default;
            
            bool isChecked( ) const {
                return mChecked;
            }
            
        private:
            bool mChecked;
        };
        using CheckHandler = std::function<void( CheckData& )>;
        
        using Check = Win33::Event<CheckData, CheckHandler>;
        
    };
    
};