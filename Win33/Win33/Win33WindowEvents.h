#pragma once

#include "Win33Event.h"
#include "Win33Point.h"
#include "Win33Size.h"

namespace Win33 {
    
    namespace WindowEvents {
        
        class CloseData : public CancellableEventData {
        public:
            CloseData( )
            :
            CancellableEventData( )
            { }
            CloseData            ( const CloseData&  other ) = default;
            CloseData            (       CloseData&& other ) = default;
            CloseData& operator= ( const CloseData&  other ) = default;
            CloseData& operator= (       CloseData&& other ) = default;
            ~CloseData           ( )                         = default;
        };
        using CloseHandler = std::function<void( CloseData& )>;
        
        class ResizeData : public EventData {
        public:
            ResizeData( const Size& size )
            :
            mSize( size )
            { }
            ResizeData            ( )                          = delete;
            ResizeData            ( const ResizeData&  other ) = default;
            ResizeData            (       ResizeData&& other ) = default;
            ResizeData& operator= ( const ResizeData&  other ) = default;
            ResizeData& operator= (       ResizeData&& other ) = default;
            ~ResizeData           ( )                          = default;
            
            const Size& getSize( ) const {
                return mSize;
            }
            
        private:
            Size mSize;
        };
        using ResizeHandler = std::function<void( ResizeData& )>;
        
        class MoveData : public EventData {
        public:
            MoveData( const Point& position )
            :
            mPosition( position )
            { }
            MoveData            ( )                        = delete;
            MoveData            ( const MoveData&  other ) = default;
            MoveData            (       MoveData&& other ) = default;
            MoveData& operator= ( const MoveData&  other ) = default;
            MoveData& operator= (       MoveData&& other ) = default;
            ~MoveData           ( )                        = default;
            
            const Point& getPosition( ) const {
                return mPosition;
            }
            
        private:
            Point mPosition;
        };
        using MoveHandler = std::function<void( MoveData& )>;
        
        class LeftClickData : public EventData {
        public:
            LeftClickData( const Point& position )
            :
            mPosition( position )
            { }
            LeftClickData            ( )                             = delete;
            LeftClickData            ( const LeftClickData&  other ) = default;
            LeftClickData            (       LeftClickData&& other ) = default;
            LeftClickData& operator= ( const LeftClickData&  other ) = default;
            LeftClickData& operator= (       LeftClickData&& other ) = default;
            ~LeftClickData           ( )                             = default;
            
            const Point& getPosition( ) const {
                return mPosition;
            }
            
        private:
            Point mPosition;
        };
        using LeftClickHandler  = std::function<void( LeftClickData& )>;
        
        class RightClickData : public EventData {
        public:
            RightClickData( const Point& position )
            :
            mPosition( position )
            { }
            RightClickData            ( )                              = delete;
            RightClickData            ( const RightClickData&  other ) = default;
            RightClickData            (       RightClickData&& other ) = default;
            RightClickData& operator= ( const RightClickData&  other ) = default;
            RightClickData& operator= (       RightClickData&& other ) = default;
            ~RightClickData           ( )                              = default;
            
            const Point& getPosition( ) const {
                return mPosition;
            }
            
        private:
            Point mPosition;
        };
        using RightClickHandler = std::function<void( RightClickData& )>;
        
        using Close      = Win33::CancellableEvent<CloseHandler>;
        using Resize     = Win33::Event<ResizeHandler>;
        using Move       = Win33::Event<MoveHandler>;
        using LeftClick  = Win33::Event<LeftClickHandler>;
        using RightClick = Win33::Event<RightClickHandler>;
    };
};