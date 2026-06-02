#include "keymanager.h"

#include <platforminterface/keys.h>

// struct KeyboardEvent
// {
//     uint64_t timestamp;
//     Qul::PlatformInterface::KeyEventType type;
//     int key;
//     unsigned int nativeScanCode;
//     unsigned int modifiers;
//     uint32_t ucs4;
//     bool autorepeat;
// };

static Qul::PlatformInterface::Key mapHWBtn2QtKey(KeyEvent::Key k)
{
    switch(k) {
    case KeyEvent::BUTTON_LEFT:
        return Qul::PlatformInterface::Key_Left;
    case KeyEvent::BUTTON_RIGHT:
        return Qul::PlatformInterface::Key_Right;
    case KeyEvent::BUTTON_UP:
        return Qul::PlatformInterface::Key_Up;
    case KeyEvent::BUTTON_DOWN:
        return Qul::PlatformInterface::Key_Down;
    default:
        return Qul::PlatformInterface::Key_Home; // Send any value that is unlikely to be handled or loead to changes in UI.
    }
}

HMIInput::HMIInput() {}

void HMIInput::onEvent(const KeyEvent &inputEvent)
{
    Qul::PlatformInterface::handleKeyEvent(Qul::Platform::getPlatformInstance()->currentTimestamp(),
                                           (inputEvent.type == KeyEvent::KeyPress) ? Qul::PlatformInterface::KeyPressEvent
                                                                                   : Qul::PlatformInterface::KeyReleaseEvent,
                                           mapHWBtn2QtKey(inputEvent.key));
}
