#pragma once

#include "Event.h"
#include "Point.h"
#include "Size.h"
#include "Keys.h"

namespace Win33 {
    
    namespace WindowEvents {
        
        class CloseData : public CancellableEventData {
        public:
            CloseData            ( )                         = default;
            CloseData            ( const CloseData&  other ) = default;
            CloseData            (       CloseData&& other ) = default;
            CloseData& operator= ( const CloseData&  other ) = default;
            CloseData& operator= (       CloseData&& other ) = default;
            ~CloseData           ( )                         = default;
        };
        
        using CloseHandler = EventHandler<void( CloseData& )>;
        
        using Close = CancellableEvent<CloseHandler>;
        
        class DestroyData : public EventData {
        public:
            DestroyData            ( )                           = default;
            DestroyData            ( const DestroyData&  other ) = default;
            DestroyData            (       DestroyData&& other ) = default;
            DestroyData& operator= ( const DestroyData&  other ) = default;
            DestroyData& operator= (       DestroyData&& other ) = default;
            ~DestroyData           ( )                           = default;
        };
        
        using DestroyHandler = EventHandler<void( DestroyData& )>;
        
        using Destroy = Event<DestroyHandler>;
        
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
        
        using ResizeHandler = EventHandler<void( ResizeData& )>;
        
        using Resize = Event<ResizeHandler>;
        
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
        
        using MoveHandler = EventHandler<void( MoveData& )>;
        
        using Move = Event<MoveHandler>;
        
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
        
        using LeftClickHandler  = EventHandler<void( LeftClickData& )>;
        
        using LeftClick = Event<LeftClickHandler>;
        
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
        
        using RightClickHandler = EventHandler<void( RightClickData& )>;
        
        using RightClick = Event<RightClickHandler>;
        
        class KeyDownData : public EventData {
        public:
            KeyDownData( Key key )
            :
            mKey( key )
            { }
            KeyDownData            ( )                           = delete;
            KeyDownData            ( const KeyDownData&  other ) = default;
            KeyDownData            (       KeyDownData&& other ) = default;
            KeyDownData& operator= ( const KeyDownData&  other ) = default;
            KeyDownData& operator= (       KeyDownData&& other ) = default;
            ~KeyDownData           ( )                           = default;
            
            Key getKey( ) const {
                return mKey;
            }
            
        private:
            Key mKey;
        };
        
        using KeyDownHandler = EventHandler<void( KeyDownData& )>;
        
        using KeyDown = Event<KeyDownHandler>;
        
        class KeyUpData : public EventData {
        public:
            KeyUpData( Key key )
            :
            mKey( key )
            { }
            KeyUpData            ( )                         = delete;
            KeyUpData            ( const KeyUpData&  other ) = default;
            KeyUpData            (       KeyUpData&& other ) = default;
            KeyUpData& operator= ( const KeyUpData&  other ) = default;
            KeyUpData& operator= (       KeyUpData&& other ) = default;
            ~KeyUpData           ( )                         = default;
            
            Key getKey( ) const {
                return mKey;
            }
            
        private:
            Key mKey;
        };
        
        using KeyUpHandler = EventHandler<void( KeyUpData& )>;
        
        using KeyUp = Event<KeyUpHandler>;
        
    };
};