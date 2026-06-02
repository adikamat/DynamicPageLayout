import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_8)
    color: "brown"
    width: Constants.mediumWidgetWidth
    height: Constants.mediumWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "8"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
