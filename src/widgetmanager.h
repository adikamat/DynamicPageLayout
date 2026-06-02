#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include "qul/singleton.h"
#include <qul/property.h>

#include <string>
#include <vector>

struct Widget{
    std::string source;
    int rowSpan{1};
    int colSpan{1};
};

struct WidgetManager : public Qul::Singleton<WidgetManager>
{
public:
    enum WidgetSize {
        SIZE_S = 0,
        SIZE_M,
        SIZE_L
    };
    enum WidgetName {
        WIDGET_NA = -1,
        WIDGET_1 = 0,
        WIDGET_2,
        WIDGET_3,
        WIDGET_4,
        WIDGET_5,
        WIDGET_6,
        WIDGET_7,
        WIDGET_8,
        WIDGET_9
    };
    struct PageWidget {
        WidgetName widget;
        WidgetSize size;
        uint8_t page_index;
        uint8_t grid_index;
        std::string qmlName;

        bool operator==(const struct PageWidget &other) {
            return this->widget == other.widget;
        }
    };

    Qul::Property<std::string> slot1;
    Qul::Property<std::string> slot2;
    Qul::Property<std::string> slot3;
    Qul::Property<std::string> slot4;

    void loadNewLayout();
    void loadPage(uint8_t pgIdx);

    void resetSlots();
    void setSlot(uint8_t gridIdx, const std::string &qmlName);

    const PageWidget& widgetAtIndex(uint8_t index);
    uint8_t getLastWidgetIndexToFocusInPage(uint8_t pgIdx);
    const PageWidget& setLastWidgetInPage();
    uint8_t getFirstWidgetIndexToFocusInPage(uint8_t pgIdx);
    const PageWidget& setFirstWidgetInPage();

    int numAvailableWidgets();
    int numAvailablePages();

    friend class Qul::Singleton<WidgetManager>;

private:
    WidgetManager();
    WidgetManager(const WidgetManager &);
    WidgetManager &operator=(const WidgetManager &);

    void triggerSlotBindings();

    uint8_t numPages;
    std::vector<PageWidget> availableWidgets;
    std::vector<uint8_t> lastWidgetIndexToFocus;
    std::vector<uint8_t> firstWidgetIndexToFocus;
};

#endif // WIDGETMANAGER_H
