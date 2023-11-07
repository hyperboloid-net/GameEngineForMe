#pragma once

#include "HyperEngine/Core/MouseCodes.hpp"
#include "Event.hpp"

namespace  HyperEngine
{
    class MouseButtonPressedEvent: public Event
    {
    public:
        MouseButtonPressedEvent(const MouseCode mouse_button): m_MouseCode(mouse_button) {}
        virtual ~MouseButtonPressedEvent() = default;
        MouseCode GetMouseButton() const { return m_MouseCode; }
        EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseCode;
			return ss.str();
		}
    private:
        MouseCode m_MouseCode;
    };

    class MouseButtonReleasedEvent: public Event
    {
    public:
        MouseButtonReleasedEvent(const MouseCode mouse_button): m_MouseCode(mouse_button) {}
        virtual ~MouseButtonReleasedEvent() = default;
        MouseCode GetMouseButton() const { return m_MouseCode; }
        EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseCode;
			return ss.str();
		}
    private:
        MouseCode m_MouseCode;
    };

    class MouseMovedEvent: public Event
    {
    public:
        MouseMovedEvent(const float x, const float y): m_MouseX(x), m_MouseY(y) {}
        float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
        EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent: public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
    };

    class MouseScrollingEvent: public Event
    {
    public:
        MouseScrollingEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollingEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolling)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
    };

}