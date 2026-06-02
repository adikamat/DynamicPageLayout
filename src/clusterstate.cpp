#include "clusterstate.h"
#include "widgetmanager2.h"
#include "widgetmanager.h"

#define MAX_PAGES 3

auto numWidgets = []()
{
    return WidgetManager::instance().numAvailableWidgets();
};

auto numPages = []()
{
    return WidgetManager::instance().numAvailablePages();
};

ClusterState::ClusterState() {
    setNewWidgetFocus(indexInAvailableWidgetList);
}

void ClusterState::changePage(uint8_t newPageIdx)
{
    WidgetManager::instance().loadPage(newPageIdx);
    pageIndex.setValue(newPageIdx);
}

void ClusterState::setNewWidgetFocus(int newWidgetIndex)
{
    auto &pw = WidgetManager::instance().widgetAtIndex(newWidgetIndex);
    if(pw.widget != WidgetManager::WIDGET_NA)
    {
        indexInAvailableWidgetList = newWidgetIndex;
        widgetFocusIndex.setValue(pw.widget);
        if(pw.page_index != pageIndex.value())
        {
            changePage(pw.page_index);
        }
    }
    else
    {
        Qul::PlatformInterface::log("Invalid Index for available widgets: %d\r\n", newWidgetIndex);
    }
}

void ClusterState::toggleWidgetFocus()
{
    if(widgetFocusEnabled.value())
    {
        widgetFocusIndex.setValue(-1);
        widgetFocusEnabled.setValue(false);
    }
    else
    {
        setNewWidgetFocus(indexInAvailableWidgetList);
        widgetFocusEnabled.setValue(true);
    }
}

void ClusterState::changeFocusWidgetPrev()
{
    if(widgetFocusEnabled.value())
    {
        int newWidgetIdx = (indexInAvailableWidgetList == 0)
                               ? (numWidgets() - 1)
                               : (indexInAvailableWidgetList - 1);

        setNewWidgetFocus(newWidgetIdx);
    }
}

void ClusterState::changeFocusWidgetNext()
{
    if(widgetFocusEnabled.value())
    {
        int newWidgetIdx = (indexInAvailableWidgetList == (numWidgets() - 1))
                               ? 0
                               : (indexInAvailableWidgetList + 1);

        setNewWidgetFocus(newWidgetIdx);
    }
}

void ClusterState::changeFocusWidgetUp()
{
    if(widgetFocusEnabled.value())
    {
        auto &current_pw = WidgetManager::instance().widgetAtIndex(indexInAvailableWidgetList);
        if(current_pw.size == WidgetManager::SIZE_M
            || current_pw.size == WidgetManager::SIZE_L
            || (current_pw.size == WidgetManager::SIZE_S
                && (current_pw.grid_index == 0 || current_pw.grid_index == 2)))
        {
            // Change to previous page
            // Get the widget to focus in previous page
            if(pageIndex.value() > 1)
            {
                uint8_t prevPageIndex = pageIndex.value() - 1;
                int newWidgetIdx = WidgetManager::instance().getLastWidgetIndexToFocusInPage(prevPageIndex);
                setNewWidgetFocus(newWidgetIdx);
            }
        }
        else
        {
            // Stay in current page
            int newWidgetIdx = indexInAvailableWidgetList - 1;
            setNewWidgetFocus(newWidgetIdx);
        }
    }
}

void ClusterState::changeFocusWidgetDown()
{
    if(widgetFocusEnabled.value())
    {
        auto &current_pw = WidgetManager::instance().widgetAtIndex(indexInAvailableWidgetList);
        if(current_pw.size == WidgetManager::SIZE_M
            || current_pw.size == WidgetManager::SIZE_L
            || (current_pw.size == WidgetManager::SIZE_S
                && (current_pw.grid_index == 1 || current_pw.grid_index == 3)))
        {
            // Change to next page
            // Get the widget to focus in next page
            if(pageIndex.value() < numPages())
            {
                uint8_t nextPageIndex = pageIndex.value() + 1;
                int newWidgetIdx = WidgetManager::instance().getFirstWidgetIndexToFocusInPage(nextPageIndex);
                setNewWidgetFocus(newWidgetIdx);
            }
        }
        else
        {
            int newWidgetIdx = indexInAvailableWidgetList + 1;
            setNewWidgetFocus(newWidgetIdx);
        }
    }
}

void ClusterState::changePagePrev()
{
    int currPage = pageIndex.value();
    int prevPage = (currPage == 1) ? MAX_PAGES : (currPage - 1);
    // TODO: Get the first widget index in previous page and update widget focus
    pageIndex.setValue(prevPage);
}

void ClusterState::changePageNext()
{
    int currPage = pageIndex.value();
    int nextPage = (currPage == MAX_PAGES) ? 0 : (currPage + 1);
    // TODO: Get the first widget index in next page and update widget focus
    pageIndex.setValue(nextPage);
}

void ClusterState::loadNewLayout()
{
    indexInAvailableWidgetList = 0;
    WidgetManager::instance().loadNewLayout();
    setNewWidgetFocus(indexInAvailableWidgetList);
    WidgetManager::instance().loadPage(pageIndex.value());
}

