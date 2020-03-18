import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4

Rectangle{
    ToolBar {
        id:toolBar
        anchors.fill: parent
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
            ToolButton{
                icon.source: "icons/open.png"
                icon.width: 40; icon.height: 40
                width: icon.width; height: icon.height
            }

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
}
