import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 240
    height: 380
    title: qsTr("Logs from Mars")
    ListModel {
        id: logModel

        ListElement {
            date: "123"
            title: "Blah"
            log: "Blah"
        }
    }
    ColumnLayout {
        TextField {
            id: title
            Layout.fillWidth: true
            placeholderText: qsTr("Title")
        }
        TextArea {
            id: log
        }
        Button {
            id: saveButton
            objectName: "saveButton"
            text: qsTr("Save Log")
        }

        TableView {
            Layout.fillWidth: true
            TableViewColumn {
                role: "date"
                title: "Date"
                width: 120
            }
            TableViewColumn {
                role: "title"
                title: "Title"
                width: 120
            }
            TableViewColumn {
                role: "log"
                title: "Log"
                width: 120
            }
            model: logModel
        }
   }
}
