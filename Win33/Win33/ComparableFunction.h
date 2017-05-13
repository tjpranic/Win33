#pragma once

#include <functional>

namespace Win33 {
    
    template<class T>
    class ComparableFunction;
    
    template<class R, class... Args>
    class ComparableFunction<R( Args... )> {
    private:
        int generateID( ) {
            static int id = 0; return id++;
        }
        
    public:
        ComparableFunction( const std::function<R( Args... )>& function )
        :
        mID       ( generateID( ) ),
        mFunction ( function )
        { }
        template<class Lambda>
        ComparableFunction( const Lambda& lambda )
        :
        mID       ( generateID( ) ),
        mFunction ( lambda )
        { }
        ComparableFunction( )
        :
        mID       ( -1 ),
        mFunction ( )
        { }
        ComparableFunction            ( const ComparableFunction&  other ) = default;
        ComparableFunction            (       ComparableFunction&& other ) = default;
        ComparableFunction& operator= ( const ComparableFunction&  other ) = default;
        ComparableFunction& operator= (       ComparableFunction&& other ) = default;
        ~ComparableFunction           ( )                                  = default;
        
        R operator( )( Args... args ) const {
            return mFunction( args... );
        }
        R operator( )( Args... args ) {
            return mFunction( args... );
        }
        
        bool operator==( const ComparableFunction& other ) const {
            return mID == other.mID;
        }
        bool operator!=( const ComparableFunction& other ) const {
            return !( *this == other );
        }
        
        operator bool( ) const {
            return static_cast<bool>( mFunction );
        }
        
    private:
        int                         mID;
        std::function<R( Args... )> mFunction;
    };
    
};