import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0

Item {
    id: tabWidget
    anchors.fill: parent
    default property alias content: stack.children
    property int current: 0

    onCurrentChanged: {setOpacities(); console.log(current);}
    Component.onCompleted: setOpacities()

    function setOpacities() {
        for (var i = 0; i < stack.children.length; ++i) {
            stack.children[i].opacity = (i == current ? 1 : 0)
        }
    }

    Row {
        id: header

        Repeater {
            id : repeater
            model: stack.children.length
            delegate : Rectangle {
                width: tabWidget.width / stack.children.length;
                height: 36 ;
                color: "#393e46"
                border.color: "#eeeeee"
                border.width: 2

//                BorderImage {
//                    anchors { fill: parent; leftMargin: 2; topMargin: 5; rightMargin: 1 }
//                    border { left: 7; right: 7 }
//                    source: "tab.png"
//                    visible: tabWidget.current == index
//                }
                Text {
                    anchors.centerIn: parent
                    text: stack.children[index].objectName
                    elide: Text.ElideRight
                    font.bold: tabWidget.current == index
                    color: "#eeeeee"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: tabWidget.current = index
                }
            }
        }
    }

    Item {
        id: stack
        width: tabWidget.width
        anchors.top: header.bottom; anchors.bottom: tabWidget.bottom

        Rectangle {
            objectName:  "tab1"
            color :"blue"
            anchors.fill: parent
        }
        Rectangle {
            objectName: "tab2"
            color :"red"
            anchors.fill: parent
        }

        function createTab()
        {

        }
    }

}
