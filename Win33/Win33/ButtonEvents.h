#pragma once

#include "Event.h"

namespace Win33 {
    
    namespace ButtonEvents {
        
        class ClickData : public EventData {
        public:
            ClickData            ( )                         = default;
            ClickData            ( const ClickData&  other ) = default;
            ClickData            (       ClickData&& other ) = default;
            ClickData& operator= ( const ClickData&  other ) = default;
            ClickData& operator= (       ClickData&& other ) = default;
            ~ClickData           ( )                         = default;
        };
        
        using ClickHandler = EventHandler<void( ClickData& )>;
        
        using Click = Event<ClickHandler>;
        
    };
    
};