#pragma once

#include "Event.hpp"
#include "HyperEngine/Core/KeyCodes.hpp"

namespace HyperEngine
{
    class KeyPressedEvent: public Event
    {
    public:
        KeyPressedEvent(const KeyCode KeyCode, bool isRepeat=false): m_KeyCode(KeyCode), m_IsRepeat(isRepeat) {}
        virtual ~KeyPressedEvent() = default;
        KeyCode GetKeyCode() const { return m_KeyCode; }
        bool GetIsRepeat() const { return m_IsRepeat; }
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        KeyCode m_KeyCode;
        bool m_IsRepeat;
    };

    class KeyReleasedEvent: public Event
    {
    public:
        KeyReleasedEvent(const KeyCode KeyCode): m_KeyCode(KeyCode) {}
        virtual ~KeyReleasedEvent() = default;
        KeyCode GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        EVENT_CLASS_TYPE(KeyReleased)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
    private:
        KeyCode m_KeyCode;
    };

    class KeyTypedEvent: public Event
    {
    public:
        KeyTypedEvent(const KeyCode KeyCode): m_KeyCode(KeyCode) {}
        virtual ~KeyTypedEvent() = default;
        KeyCode GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        EVENT_CLASS_TYPE(KeyTyped)
        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}
    private:
        KeyCode m_KeyCode;
    };

}