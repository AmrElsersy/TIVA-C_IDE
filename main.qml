import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.3

ApplicationWindow {
    visible: true
    width: 1280
    height: 900
    title: qsTr("Hello World")

    FileDialog {
        id:dialog
        selectFolder: false;    selectMultiple: false;
        nameFilters: [ "files (*.txt *.cpp *.c *.h)" ]
    }

    GridLayout {
        anchors.top: header.bottom
        anchors.fill: parent
        id: grid
        rows:2
        columns:4
        rowSpacing: 0; columnSpacing: 0;


        TivaToolBar{
            id:toolBar

            Layout.row: 0
            Layout.column: 0
            Layout.rowSpan: 1
            Layout.columnSpan: 4
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 70
        }

        DirectoryView {
            id : dirView

            Layout.row: 1
            Layout.column: 0
            Layout.fillHeight: true
            Layout.columnSpan:  1
            Layout.preferredWidth: 300
        }

        TabEditor{
            id : tabWidget

            Layout.row: 1
            Layout.column: 1
            Layout.columnSpan: 3
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    Connections {
        target: dirView
        function onAddTab(titleTab,textContent) {tabWidget.newTab(titleTab,textContent);}
    }
    Connections {
        target: Controller
        function onAddTab(titleTab,textContent) {tabWidget.newTab(titleTab,textContent);}
    }
    Connections {
        target: toolBar
        onSaveFile: {dialog.open();}
    }
    Connections {
        target: dialog
        onAccepted : {Controller.saveFile(dialog.fileUrl,tabWidget.currentText);}
//        onAccepted :{ console.log("currentText",tabWidget.currentText); }
    }

}
