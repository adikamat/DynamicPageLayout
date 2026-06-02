import QtQuick

Item {
    Keys.onPressed: {
        switch(event.key) {
        case Qt.Key_T:
            ClusterState.toggleWidgetFocus()
            break;
        case Qt.Key_Right:
            ClusterState.changeFocusWidgetNext()
            break;
        case Qt.Key_Left:
            ClusterState.changeFocusWidgetPrev()
            break;
        default:
            break;
        }
    }
}
