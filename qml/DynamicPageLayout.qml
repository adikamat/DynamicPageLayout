import QtQuick
import QtQuick.Controls
import QtQuickUltralite.Layers

ApplicationScreens {
    Screen {
        width: 800
        height: 480
        ItemLayer {
            width: 800
            height: 480

            Rectangle {
                anchors.fill: parent
                color: "grey"
            }

            PageView {
                x: 20
                y: 20
                width: 200
                height: 200
            }

            // PageView_Impl2 {
            //     id: impl2
            //     x: 400
            //     y: 20
            // }

            Item {
                anchors.fill: parent
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
                    case Qt.Key_Up:
                        ClusterState.changeFocusWidgetUp()
                        break;
                    case Qt.Key_Down:
                        ClusterState.changeFocusWidgetDown()
                        break;
                    default:
                        break;
                    }
                }
            }

            Switch {
                anchors.bottom: btns.top
                anchors.right:parent.right
                anchors.margins: 10
                checked: ClusterState.widgetFocusEnabled
                text: "Widget Focus"

                onToggledChanged: {
                    ClusterState.toggleWidgetFocus()
                }
            }

            Row {
                id: btns
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 10

                Button {
                    id: btnNewLayout

                    text: "New Layout"
                    onClicked: {
                        ClusterState.loadNewLayout()
                    }
                }

                Button {
                    id: btnPrv

                    text: "Prev Widget"
                    onClicked: {
                        ClusterState.changeFocusWidgetPrev()
                    }
                }
                Button {
                    id: btnNxt

                    text: "Next Widget"
                    onClicked: {
                        ClusterState.changeFocusWidgetNext()
                    }
                }
            }
        }
    }
}
