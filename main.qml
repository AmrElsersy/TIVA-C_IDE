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

    header:
        ToolBar {
        anchors.top: parent.top
        width: parent.width
        height: 60
        background: Rectangle {
            color: "#222831"
        }

        RowLayout {
            id : rowLayout
            anchors.fill: parent
            ToolButton {
                id : open
                width:300;height: parent.height
                icon.width: 50; icon.height: parent.height;icon.color: "white"
                icon.source: "icons/open.png"
                onClicked: console.log("ray2");
            }
            Button{
                icon.source: "icons/open.png"
                icon.width: 40; icon.height: 40
            }
//            Image {
//                source: "icons/open.png"
//                width: 30
//                height: 30
//            }

            ToolButton {
                id : save
                width:300;height: parent.height
                icon.width: 50; icon.height: parent.height;icon.color: "white"
                icon.source: "icons/save.png"
                onClicked: console.log("ray2");
                anchors.left: open.right
            }
            ToolButton {
                id : burn
                width:300;height: parent.height
                icon.width: 50; icon.height: parent.height;icon.color: "white"
                icon.source: "icons/memory.png"
                onClicked: console.log("ray2");
                anchors.left: save.right
            }

        }
    }


    GridLayout {
        anchors.top: header.bottom
        anchors.fill: parent
        id: grid
        rows:1
        columns:2
        rowSpacing: 0; columnSpacing: 0;
        DirectoryView {
            id : dirView
            Layout.row: 0
            Layout.column: 0
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width/4
        }
        TabEditor{
            id : tabWidget
            Layout.row: 0
            Layout.column: 1
            Layout.fillHeight: true
            anchors.left: dirView.right
            Layout.preferredWidth: 3*parent.width/4

        }
    }

    Connections {
        target: dirView
        function onAddTab(titleTab,textContent) {console.log("signalllllllll");  tabWidget.newTab(titleTab,textContent);}
    }
}
