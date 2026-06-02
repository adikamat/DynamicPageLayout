import QtQuick
import Constants

Rectangle {
    id: root

    property bool hasFocus: (ClusterState.widgetFocusIndex
                             === WidgetManager.WIDGET_5)
    color: "cyan"
    width: Constants.mediumWidgetWidth
    height: Constants.mediumWidgetHeight
    Text {
        anchors.centerIn: parent
        text: "5"
        color: root.hasFocus ? Constants.widgetInFocusColor : "black"
    }
}
