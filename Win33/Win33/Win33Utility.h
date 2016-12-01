#pragma once

namespace Win33 {
    
    namespace Utility {
        
        //forcibly reconstunct and object over itself.
        //this is used to stealthily update a property when necessary
        template<class T, class... Args>
        void mutate( T* property, Args... args ) {
            *property = T( args... );
        }
        
    };
    
};