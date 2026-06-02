import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_6)
    color: "magenta"
    width: Constants.smallWidgetWidth
    height: Constants.smallWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "6"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
