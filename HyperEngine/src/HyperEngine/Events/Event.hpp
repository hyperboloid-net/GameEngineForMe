#pragma once

#include "HyperEngine/src/hepch.hpp"
#include "HyperEngine/Core/Base.hpp"



namespace HyperEngine
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled, MouseScrolling
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication   =  BIT(0),
        EventCategoryInput         =  BIT(1),
        EventCategoryKeyboard      =  BIT(2),
        EventCategoryMouse         =  BIT(3),
        EventCategoryMouseButton   =  BIT(4)
    };

    #define EVENT_CLASS_TYPE(type)                                                   \
        static EventType GetStaticType() { return EventType::type; }                 \
        virtual EventType GetEventType() const override { return GetStaticType(); }  \
        virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) \
        virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
        friend class EventDispatcher;

    public:
        virtual ~Event() = default;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) { return category & GetCategoryFlags(); }
        bool handled = false;
    };

    // TODO: message queue and multi-thread to dispatch event (not blocking)
    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event):m_Event(event) {}

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType()){
                m_Event.handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event){
        return os << event.ToString();
    }
}