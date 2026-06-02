import QtQuick

Row {
    spacing: 0

    Column {
        spacing: 0

        Loader {
            id: slot3
            source: WidgetManager.slot3
        }

        Loader {
            id: slot4
            source: WidgetManager.slot4
        }
    }

    Column {
        spacing: 0

        Loader {
            id: slot1
            source: WidgetManager.slot1
        }

        Loader {
            id: slot2
            source: WidgetManager.slot2
        }
    }
}
