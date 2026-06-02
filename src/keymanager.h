#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <qul/object.h>
#include <qul/singleton.h>
#include <qul/signal.h>
#include <qul/eventqueue.h>

struct KeyEvent : Qul::Object
{

    enum Key {
        BUTTON_UP,
        BUTTON_DOWN,
        BUTTON_LEFT,
        BUTTON_RIGHT,
        BUTTON_CENTER,
        BUTTON_UNKNOWN
    };
    enum Type { KeyPress, KeyRelease };

    Type type;
    Key key;
};

class HMIInput: public Qul::Singleton<HMIInput>, public Qul::EventQueue<KeyEvent>
{
public:

    Qul::Signal<void(int key)> pressed;
    Qul::Signal<void(int key)> released;

    void onEvent(const KeyEvent &inputEvent) override;

    friend class Qul::Singleton<HMIInput>;

private:
    HMIInput();                              // Private constructor
    HMIInput(const HMIInput &);              // Non copy-constructible
    HMIInput &operator=(const HMIInput &);   // Non copyable
};

#endif // KEYMANAGER_H
