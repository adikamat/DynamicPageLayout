import QtQuick
import QtQuick.Layouts

GridLayout {
    id: root

    property alias slot1Source: slot1.source
    property alias slot2Source: slot2.source
    property alias slot3Source: slot3.source
    property alias slot4Source: slot4.source

    property int slot1RowSpan: 1
    property int slot2RowSpan: 1
    property int slot3RowSpan: 1
    property int slot4RowSpan: 1

    property int slot1ColumnSpan: 1
    property int slot2ColumnSpan: 1
    property int slot3ColumnSpan: 1
    property int slot4ColumnSpan: 1

    rowSpacing: 0
    columnSpacing: 0
    columns: 2
    rows: 2

    function reset() {
        slot1.source = ""
        slot2.source = ""
        slot3.source = ""
        slot4.source = ""

        root.slot1ColumnSpan = 1
        root.slot2ColumnSpan = 1
        root.slot3ColumnSpan = 1
        root.slot4ColumnSpan = 1

        root.slot1RowSpan = 1
        root.slot2RowSpan = 1
        root.slot3RowSpan = 1
        root.slot4RowSpan = 1
    }

    // function loadNewPage() {
    //     root.slot1RowSpan = WidgetManager.slot1.rowSpan
    //     root.slot1ColumnSpan = WidgetManager.slot1.colSpan

    //     root.slot2RowSpan = WidgetManager.slot2.rowSpan
    //     root.slot2ColumnSpan = WidgetManager.slot2.colSpan

    //     root.slot3RowSpan = WidgetManager.slot3.rowSpan
    //     root.slot3ColumnSpan = WidgetManager.slot3.colSpan

    //     root.slot4RowSpan = WidgetManager.slot4.rowSpan
    //     root.slot4ColumnSpan = WidgetManager.slot4.colSpan

    //     root.slot1Source = WidgetManager.slot1.source
    //     root.slot2Source = WidgetManager.slot2.source
    //     root.slot3Source = WidgetManager.slot3.source
    //     root.slot4Source = WidgetManager.slot4.source
    // }

    Loader {
        id: slot3

        //width: (root.width - root.rowSpacing) / 4
        //height: (root.height - root.columnSpacing) / 4
        source: WidgetManager.slot3.source
        Layout.rowSpan: WidgetManager.slot3.rowSpan //root.slot3RowSpan
        Layout.columnSpan: WidgetManager.slot3.colSpan //root.slot3ColumnSpan
    }

    Loader {
        id: slot1

        //width: (root.width - root.rowSpacing) / 4
        //height: (root.height - root.columnSpacing) / 4
        source: WidgetManager.slot1.source
        Layout.rowSpan: WidgetManager.slot1.rowSpan //root.slot1RowSpan
        Layout.columnSpan: WidgetManager.slot1.colSpan //root.slot1ColumnSpan
    }

    Loader {
        id: slot4

        //width: (root.width - root.rowSpacing) / 4
        //height: (root.height - root.columnSpacing) / 4
        source: WidgetManager.slot4.source
        Layout.rowSpan: WidgetManager.slot4.rowSpan //root.slot4RowSpan
        Layout.columnSpan: WidgetManager.slot4.colSpan //root.slot4ColumnSpan
    }

    Loader {
        id: slot2

        //width: (root.width - root.rowSpacing) / 4
        //height: (root.height - root.columnSpacing) / 4
        source: WidgetManager.slot2.source
        Layout.rowSpan: WidgetManager.slot2.rowSpan //root.slot2RowSpan
        Layout.columnSpan: WidgetManager.slot2.colSpan //root.slot2ColumnSpan
    }

    // ClusterState.onWidgetLayoutChanged: {
    //     reset()
    //     WidgetManager.loadPage(ClusterState.pageIndex)
    //     loadNewPage()
    // }

    // ClusterState.onPageIndexChanged: {
    //     reset()
    //     WidgetManager.loadPage(ClusterState.pageIndex)
    //     loadNewPage()
    // }

    // Component.onCompleted: {
    //     loadNewPage()
    // }

}
