#include "widgetmanager2.h"

#include <algorithm>

WidgetManager2::WidgetManager2() {
    // Page 1 widgets
    availableWidgets.push_back({WIDGET_2, 1, 0});
    availableWidgets.push_back({WIDGET_4, 1, 1});
    availableWidgets.push_back({WIDGET_5, 1, 2});

    // Page 2 widgets
    availableWidgets.push_back({WIDGET_6, 2, 0});
    availableWidgets.push_back({WIDGET_7, 2, 1});
    availableWidgets.push_back({WIDGET_8, 2, 2});

    // Page 3 widgets
    availableWidgets.push_back({WIDGET_9, 3, 2});

    updateWidgetVisibility();
}

void WidgetManager2::updateWidgetVisibility()
{
    uint32_t w = 0x0;
    for(auto &i : availableWidgets)
    {
        w |= (0x01 << i.widget);
    }
    visibleWidgets.setValue(w);
}

bool WidgetManager2::isWidgetVisible(int widget)
{
    struct PageWidget w{static_cast<WidgetName>(widget), 0, 0};
    if(std::find(availableWidgets.begin(),
                 availableWidgets.end(),
                 w) != availableWidgets.end())
    {
        return true;
    }
    else
        return false;
}

int WidgetManager2::widgetPageNum(int widget)
{
    struct PageWidget w{static_cast<WidgetName>(widget), 0, 0};
    auto it = std::find(availableWidgets.begin(),
                        availableWidgets.end(),
                        w);
    if(it != availableWidgets.end())
    {
        return it->pg_idx;
    }
    else
        return -1;
}

int WidgetManager2::widgetGridIndex(int widget)
{
    struct PageWidget w{static_cast<WidgetName>(widget), 0, 0};
    auto it = std::find(availableWidgets.begin(),
                        availableWidgets.end(),
                        w);
    if(it != availableWidgets.end())
    {
        return it->grid_index;
    }
    else
        return -1;
}

WidgetManager2::PageWidget WidgetManager2::widgetAtIndex(uint8_t index)
{
    if(index < availableWidgets.size())
    {
        return availableWidgets.at(index);
    }
    else
        return PageWidget{WIDGET_NA, 0, 0};
}

int WidgetManager2::numAvailableWidgets()
{
    return availableWidgets.size();
}

void WidgetManager2::loadNewLayout()
{
    availableWidgets.clear();

    // Page 1 widgets
    availableWidgets.push_back({WIDGET_1, 1, 0});
    availableWidgets.push_back({WIDGET_3, 1, 2});
    availableWidgets.push_back({WIDGET_4, 1, 3});

    // Page 2 widgets
    availableWidgets.push_back({WIDGET_5, 2, 0});
    availableWidgets.push_back({WIDGET_8, 2, 2});

    // Page 3 widgets
    availableWidgets.push_back({WIDGET_9, 3, 2});

    updateWidgetVisibility();
}
