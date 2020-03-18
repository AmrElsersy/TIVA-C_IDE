import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    visible: true
    width: 1300
    height: 1000
    title: qsTr("Hello World")

    GridLayout {
        anchors.top: header.bottom
        anchors.fill: parent
        id: grid
        rows:2
        columns:4
        rowSpacing: 0; columnSpacing: 0;


        TIVA_ToolBar{
            id:toolBar

            Layout.row: 0
            Layout.column: 0
            Layout.rowSpan: 1
            Layout.columnSpan: 4
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 100
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

//            Layout.preferredWidth:  parent.height *3/4
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
}
