import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_2)
    color: "blue"
    width: Constants.smallWidgetWidth
    height: Constants.smallWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "2"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
