#pragma once

#include "Event.hpp"
#include "hepch.hpp"

namespace HyperEngine 
{

    class WindowCloseEvent: public Event
    {
    public:
        WindowCloseEvent() = default;
        ~WindowCloseEvent() = default;
        EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent: " <<  " (closed = " << m_IsClosed << ")";
			return ss.str();
		}
    private:
        bool m_IsClosed = false;
    };

    class WindowResizeEvent: public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height):m_Width(width), m_Height(height) {};
        ~WindowResizeEvent() = default;
        EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}
    private:
        unsigned int m_Width, m_Height;
    };

    class WindowFocusEvent: public Event
    {
    public:
        WindowFocusEvent() = default;
        ~WindowFocusEvent() = default;
        EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent: " << "Success Called !";
			return ss.str();
		}
    };

    class WindowLostFocusEvent: public Event
    {
    public:
        WindowLostFocusEvent() = default;
        ~WindowLostFocusEvent() = default;
        EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowLostFocusEvent: " << "Success Called !";
			return ss.str();
		}
    };

    class WindowMovedEvent: public Event
    {
    public:
        WindowMovedEvent() = default;
        ~WindowMovedEvent() = default;
        EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: " << "Success Called !";
			return ss.str();
		}
    };

    class AppTickEvent: public Event
    {
    public:
        AppTickEvent() = default;
        ~AppTickEvent() = default;
        EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent: " << "Success Called !";
			return ss.str();
		}
    };

    class AppUpdateEvent: public Event
    {
    public:
        AppUpdateEvent() = default;
        ~AppUpdateEvent() = default;
        EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent: " << "Success Called !";
			return ss.str();
		}
    };

    class AppRenderEvent: public Event
    {
    public:
        AppRenderEvent() = default;
        ~AppRenderEvent() = default;
        EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent: " << "Success Called !";
			return ss.str();
		}
    };
}