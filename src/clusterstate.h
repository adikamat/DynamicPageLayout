#ifndef CLUSTERSTATE_H
#define CLUSTERSTATE_H

#include <qul/singleton.h>
#include <qul/property.h>
#include <qul/signal.h>

class ClusterState : public Qul::Singleton<ClusterState>
{
public:

    Qul::Signal<void()> widgetLayoutChanged;

    Qul::Property<uint8_t> pageIndex{1}; // 1-based index

    Qul::Property<bool> widgetFocusEnabled{true};
    Qul::Property<int8_t> widgetFocusIndex; // Must match with WidgetManager enums

    void toggleWidgetFocus();
    void changeFocusWidgetPrev();
    void changeFocusWidgetNext();
    void changeFocusWidgetUp();
    void changeFocusWidgetDown();

    void changePagePrev();
    void changePageNext();

    void loadNewLayout();

    friend class Qul::Singleton<ClusterState>;

private:
    // Track the index of current focused widget from available widget list
    int indexInAvailableWidgetList;

    ClusterState();                                  // Private Constructor
    ClusterState(const ClusterState &);              // Non copy-constructible
    ClusterState &operator=(const ClusterState &);   // Non copyable

    void changePage(uint8_t newPageIdx);
    void setNewWidgetFocus(int newWidgetIndex);
};

#endif // CLUSTERSTATE_H
