import QtQuick
import QtQuick.Layouts

Item {
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

    Item {
        Layout.fillHeight: true
        Layout.fillWidth: true

        Layout.preferredWidth: (slot3.source === "") ? 0 : root.width / 2
        Layout.preferredHeight: (slot3.source === "") ? 0 : root.height / 2

        Loader {
            id: slot3
            anchors.fill: parent
        }
    }

    Item {
        Layout.fillHeight: true

        Layout.preferredWidth: (slot1.source === "") ? 0 : root.width / 2
        Layout.preferredHeight: (slot1.source === "") ? 0 : root.height / 2

        Loader {
            id: slot1
            anchors.fill: parent
        }
    }

    Item {
        Layout.preferredWidth: (slot4.source === "") ? 0 : root.width / 2
        Layout.preferredHeight: (slot4.source === "") ? 0 : root.height / 2
        Loader {
            id: slot4
            anchors.fill: parent
        }
    }

    Item {
        Layout.preferredWidth: (slot2.source === "") ? 0 : root.width / 2
        Layout.preferredHeight: (slot2.source === "") ? 0 : root.height / 2
        Loader {
            id: slot2
            anchors.fill: parent
        }
    }
}
