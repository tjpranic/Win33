#pragma once

namespace Win33 {

    //allows enum classes to make use of typical bitfield operations
    template<class T, typename = std::enable_if<std::is_enum<T>::value>::type>
    inline T operator|( T lhs, T rhs ) {
        using U = std::underlying_type<T>::type;
        return static_cast<T>( static_cast<U>( lhs ) | static_cast<U>( rhs ) );
    }
    template<class T, typename = std::enable_if<std::is_enum<T>::value>::type>
    inline T& operator|=( T& lhs, T rhs ) {
        using U = std::underlying_type<T>::type;
        lhs = static_cast<T>( static_cast<U>( lhs ) | static_cast<U>( rhs ) );
        return lhs;
    }
    template<class T, typename = std::enable_if<std::is_enum<T>::value>::type>
    inline T operator&( T lhs, T rhs ) {
        using U = std::underlying_type<T>::type;
        return static_cast<T>( static_cast<U>( lhs ) & static_cast<U>( rhs ) );
    }
    template<class T, typename = std::enable_if<std::is_enum<T>::value>::type>
    inline T& operator&=( T& lhs, T rhs ) {
        using U = std::underlying_type<T>::type;
        lhs = static_cast<T>( static_cast<U>( lhs ) & static_cast<U>( rhs ) );
        return lhs;
    }
    template<class T, typename = std::enable_if<std::is_enum<T>::value>::type>
    inline T operator~( T lhs ) {
        using U = std::underlying_type<T>::type;
        return static_cast<T>( ~static_cast<U>( lhs ) );
    }

    //for use with enum classes with the same underlying type, but different enum class type
    template
    <
        class T,
        class Y,
        typename = std::enable_if<std::is_enum<T>::value>::type,
        typename = std::enable_if<std::is_enum<Y>::value>::type,
        typename = std::enable_if<std::is_same<std::underlying_type<T>::type, std::underlying_type<Y>::type>::value>::type
    >
    inline T operator|( T lhs, Y rhs ) {
        using U = std::underlying_type<T>::type;
        using V = std::underlying_type<Y>::type;
        return static_cast<T>( static_cast<U>( lhs ) | static_cast<V>( rhs ) );
    }
    template
    <
        class T,
        class Y,
        typename = std::enable_if<std::is_enum<T>::value>::type,
        typename = std::enable_if<std::is_enum<Y>::value>::type,
        typename = std::enable_if<std::is_same<std::underlying_type<T>::type, std::underlying_type<Y>::type>::value>::type
    >
    inline Y operator&( T lhs, Y rhs ) {
        using U = std::underlying_type<T>::type;
        using V = std::underlying_type<Y>::type;
        return static_cast<Y>( static_cast<U>( lhs ) & static_cast<V>( rhs ) );
    }

}