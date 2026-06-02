#ifndef WIDGETMANAGER2_H
#define WIDGETMANAGER2_H

#include <platform/platform.h>
#include <qul/singleton.h>
#include <qul/property.h>

#include <vector>

class WidgetManager2 : public Qul::Singleton<WidgetManager2>
{
public:
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
        WIDGET_9,
        WIDGET_GAUGE
    };
    struct PageWidget {
        enum WidgetName widget;
        uint8_t pg_idx;
        uint8_t grid_index;

        bool operator==(const struct PageWidget &other) {
            return this->widget == other.widget;
        }
    };

    Qul::Property<uint32_t> visibleWidgets;

    bool isWidgetVisible(int widget);
    int widgetPageNum(int widget);
    int widgetGridIndex(int widget);

    PageWidget widgetAtIndex(uint8_t index);

    int numAvailableWidgets();

    void loadNewLayout();

    friend class Qul::Singleton<WidgetManager2>;

private:
    WidgetManager2();                                    // Private constructor
    WidgetManager2(const WidgetManager2 &);              // Non copy-constructible
    WidgetManager2 &operator=(const WidgetManager2 &);   // Non copyable

    void updateWidgetVisibility();

    std::vector<PageWidget> availableWidgets;
};

#endif // WIDGETMANAGER2_H
