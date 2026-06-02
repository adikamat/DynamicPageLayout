#include "widgetmanager.h"

#define MAX_GRID_ID 4

static WidgetManager::PageWidget unknownWidget{WidgetManager::WIDGET_NA, WidgetManager::SIZE_S, 0, 0, ""};

WidgetManager::WidgetManager()
{
    loadNewLayout();
    loadPage(1);
}

void WidgetManager::triggerSlotBindings()
{
    slot1.syncBinding();
    slot2.syncBinding();
    slot3.syncBinding();
    slot4.syncBinding();
}

void WidgetManager::loadNewLayout()
{
    static int counter = 0;

    availableWidgets.clear();

    switch(counter) {
    case 0:
        // Page 1 widgets
        availableWidgets.push_back({WIDGET_1, SIZE_M, 1, 0, "Widget1.qml"});
        availableWidgets.push_back({WIDGET_3, SIZE_S, 1, 2, "Widget3.qml"});
        availableWidgets.push_back({WIDGET_4, SIZE_S, 1, 3, "Widget4.qml"});

        // Page 2 widgets
        availableWidgets.push_back({WIDGET_5, SIZE_M, 2, 0, "Widget5.qml"});
        availableWidgets.push_back({WIDGET_8, SIZE_M, 2, 2, "Widget8.qml"});

        // Page 3 widgets
        availableWidgets.push_back({WIDGET_9, SIZE_L, 3, 2, "Widget9.qml"});

        numPages = 3;

        break;

    case 1:
        // Page 1 widgets
        availableWidgets.push_back({WIDGET_2, SIZE_S, 1, 0, "Widget2.qml"});
        availableWidgets.push_back({WIDGET_4, SIZE_S, 1, 1, "Widget4.qml"});
        availableWidgets.push_back({WIDGET_5, SIZE_M, 1, 2, "Widget5.qml"});

        // Page 2 widgets
        availableWidgets.push_back({WIDGET_6, SIZE_S, 2, 0, "Widget6.qml"});
        availableWidgets.push_back({WIDGET_7, SIZE_S, 2, 1, "Widget7.qml"});
        availableWidgets.push_back({WIDGET_8, SIZE_M, 2, 2, "Widget8.qml"});

        // Page 3 widgets
        availableWidgets.push_back({WIDGET_9, SIZE_L, 3, 2, "Widget9.qml"});

        numPages = 3;

        break;

    case 2:
        // Page 1 widgets
        availableWidgets.push_back({WIDGET_1, SIZE_M, 1, 0, "Widget1.qml"});
        availableWidgets.push_back({WIDGET_2, SIZE_S, 1, 2, "Widget2.qml"});
        availableWidgets.push_back({WIDGET_3, SIZE_S, 1, 3, "Widget3.qml"});

        // Page 2 widgets
        availableWidgets.push_back({WIDGET_4, SIZE_S, 2, 0, "Widget4.qml"});
        availableWidgets.push_back({WIDGET_6, SIZE_S, 2, 1, "Widget6.qml"});
        availableWidgets.push_back({WIDGET_5, SIZE_M, 2, 2, "Widget5.qml"});

        // Page 3 widgets
        //availableWidgets.push_back({WIDGET_8, SIZE_M, 3, 0, "Widget8.qml"});
        //availableWidgets.push_back({WIDGET_7, SIZE_S, 3, 2, "Widget7.qml"});

        numPages = 2;

        break;
    default:
        break;
    }


    setFirstWidgetInPage();
    setLastWidgetInPage();

    ++counter;
    if(counter > 2)
        counter = 0;
}

void WidgetManager::loadPage(uint8_t pgIdx)
{
    resetSlots();
    for(auto &widget : availableWidgets)
    {
        if(widget.page_index == pgIdx)
            setSlot(widget.grid_index, widget.qmlName);
    }
    triggerSlotBindings();
}

void WidgetManager::resetSlots()
{
    // Do not trigger binding - Bindings are triggered in the end
    // once all changes are done.
    slot1.setValueAndBypassBinding("");
    slot2.setValueAndBypassBinding("");
    slot3.setValueAndBypassBinding("");
    slot4.setValueAndBypassBinding("");
}

void WidgetManager::setSlot(uint8_t gridIdx, const std::string &qmlName)
{
    switch(gridIdx) {
    case 0:
        slot1.setValueAndBypassBinding(qmlName);
        break;
    case 1:
        slot2.setValueAndBypassBinding(qmlName);
        break;
    case 2:
        slot3.setValueAndBypassBinding(qmlName);
        break;
    case 3:
        slot4.setValueAndBypassBinding(qmlName);
        break;
    default:
        break;
    }
}

uint8_t WidgetManager::getFirstWidgetIndexToFocusInPage(uint8_t pgIdx)
{
    return firstWidgetIndexToFocus.at(pgIdx - 1);
}

uint8_t WidgetManager::getLastWidgetIndexToFocusInPage(uint8_t pgIdx)
{
    return lastWidgetIndexToFocus.at(pgIdx - 1);
}

const WidgetManager::PageWidget &WidgetManager::setFirstWidgetInPage()
{
    firstWidgetIndexToFocus.clear();
    // Save the widget at lowest index
    firstWidgetIndexToFocus = std::vector<uint8_t>(numPages, 4); // Initialize to a high value
    std::vector<uint8_t> min_grid_index(numPages, 4);
    for(int i = 0; i < availableWidgets.size(); ++i)
    {
        auto &widget = availableWidgets.at(i);
        if(widget.grid_index < min_grid_index.at(widget.page_index - 1))
        {
            min_grid_index.at(widget.page_index - 1) = widget.grid_index;
            firstWidgetIndexToFocus.at(widget.page_index - 1) = i;
        }
    }
}

const WidgetManager::PageWidget &WidgetManager::setLastWidgetInPage()
{
    lastWidgetIndexToFocus.clear();
    // Save the widget at highest index
    lastWidgetIndexToFocus = std::vector<uint8_t>(numPages, 4); // Initialize to a high value
    std::vector<uint8_t> max_grid_index(numPages, 0);
    for(int i = 0; i < availableWidgets.size(); ++i)
    {
        auto &widget = availableWidgets.at(i);
        if(widget.grid_index > max_grid_index.at(widget.page_index - 1))
        {
            max_grid_index.at(widget.page_index - 1) = widget.grid_index;
            lastWidgetIndexToFocus.at(widget.page_index - 1) = i;
        }
    }
}

int WidgetManager::numAvailableWidgets()
{
    return availableWidgets.size();
}

int WidgetManager::numAvailablePages()
{
    return numPages;
}

const WidgetManager::PageWidget &WidgetManager::widgetAtIndex(uint8_t index)
{
    if(index < availableWidgets.size())
    {
        return availableWidgets.at(index);
    }
    else
        return unknownWidget;
}
