import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_9)
    color: "fuchsia"
    width: Constants.largelWidgetWidth
    height: Constants.largeWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "9"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
