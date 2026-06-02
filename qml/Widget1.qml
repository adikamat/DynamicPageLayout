import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_1)
    color: "red"
    width: Constants.mediumWidgetWidth
    height: Constants.mediumWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "1"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
