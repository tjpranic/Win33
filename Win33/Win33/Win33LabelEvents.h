#pragma once

#include "Win33Event.h"

namespace Win33 {
    
    namespace LabelEvents {
        
        class ClickData : public EventData {
        public:
            ClickData            ( )                         = default;
            ClickData            ( const ClickData&  other ) = default;
            ClickData            (       ClickData&& other ) = default;
            ClickData& operator= ( const ClickData&  other ) = default;
            ClickData& operator= (       ClickData&& other ) = default;
            ~ClickData           ( )                         = default;
        };
        using ClickHandler = std::function<void( ClickData& )>;
        
        using Click = Win33::Event<ClickHandler>;
        
    };
    
};