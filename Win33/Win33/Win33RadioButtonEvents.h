#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace RadioButtonEvents {
        
        class SelectData : public EventData {
        public:
            SelectData( bool selected )
            :
            mSelected( selected )
            { }
            SelectData            ( )                          = delete;
            SelectData            ( const SelectData&  other ) = default;
            SelectData            (       SelectData&& other ) = default;
            SelectData& operator= ( const SelectData&  other ) = default;
            SelectData& operator= (       SelectData&& other ) = default;
            ~SelectData           ( )                          = default;
            
            bool isSelected( ) const {
                return mSelected;
            }
            
        private:
            bool mSelected;
        };
        using SelectHandler = std::function<void( SelectData& )>;
        
        using Select = Win33::Event<SelectHandler, SelectData>;
        
    };
    
};