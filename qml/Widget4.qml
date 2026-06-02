import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_4)
    color: "yellow"
    width: Constants.smallWidgetWidth
    height: Constants.smallWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "4"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
