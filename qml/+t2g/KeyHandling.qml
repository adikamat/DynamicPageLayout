import QtQuick

Item {
    HMIInput.onPressed: {
        console.log('Received event ', key)
        switch(key) {
        // case KeyEvent.BUTTON_LEFT:
        //     ClusterState.toggleWidgetFocus()
        //     break;
        case 2:
            ClusterState.changeFocusWidgetNext()
            break;
        case 3:
            ClusterState.changeFocusWidgetPrev()
            break;
        default:
            break;
        }
    }
}
