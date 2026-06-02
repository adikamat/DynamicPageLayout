import QtQuick
import QtQuick.Layouts

Item {
    id: root

    width: 200
    height: 200

    function getX(index: int) : int {
        switch(index) {
        case 0:
        case 1:
            return root.width / 2;
        case 2:
        case 3:
        default:
            return 0;
        }
    }

    function getY(index: int) : int {
        switch(index) {
        case 0:
        case 2:
            return 0;
        case 1:
        case 3:
        default:
            return root.height / 2;
        }
    }

    Widget1 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_1)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_1)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_1))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget2 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_2)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_2)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_2))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget3 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_3)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_3)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_3))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget4 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_4)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_4)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_4))
                 && (myPageNum === ClusterState.pageIndex)
        x: switch(myGridIndex) {
           case 0:
           case 1:
               return root.width / 2;
           case 2:
           case 3:
           default:
               return 0;
           }
        y: switch(myGridIndex) {
           case 0:
           case 2:
               return 0;
           case 1:
           case 3:
           default:
               return root.height / 2;
           }
    }

    Widget5 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_5)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_5)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_5))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget6 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_6)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_6)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_6))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget7 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_7)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_7)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_7))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget8 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_8)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_8)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_8))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }

    Widget9 {
        property int myPageNum: WidgetManager2.widgetPageNum(WidgetManager2.WIDGET_9)
        property int myGridIndex: WidgetManager2.widgetGridIndex(WidgetManager2.WIDGET_9)

        visible: (WidgetManager2.visibleWidgets & (0x01 << WidgetManager2.WIDGET_9))
                 && (myPageNum === ClusterState.pageIndex)
        x: root.getX(myGridIndex)
        y: root.getY(myGridIndex)
    }
}
