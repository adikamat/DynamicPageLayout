import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_7)
    color: "purple"
    width: Constants.smallWidgetWidth
    height: Constants.smallWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "7"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
