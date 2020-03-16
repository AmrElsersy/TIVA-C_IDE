import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Styles 1.3
import QtQuick.Controls.Styles 1.1

Rectangle {
    anchors.fill: parent
    color: "#222831"
    border.color: "#eeeeee"

    TreeView {
        model: fileSystemModel
        id : tree
        alternatingRowColors: true
        anchors.fill: parent
        anchors.margins: 20

        property string selectColor: "#b55400"
        property string lightGreyColor: "#eeeeee"
        property string darkGreyColor: "#222831"
        property string middleGreyColor: "#393e46"
        TableViewColumn{title: "File System";role: "fileName";width: parent.width ;}
        // colors
        rowDelegate: Rectangle {
            color: (styleData.selected) ? tree.selectColor : ( styleData.row % 2 == 0 ) ? tree.middleGreyColor : tree.darkGreyColor
        }
        itemDelegate: Rectangle {
            id :item
            color: (styleData.selected) ? tree.selectColor : ( styleData.row % 2 == 0 ) ? tree.middleGreyColor : tree.darkGreyColor
            Text {
                text: styleData.value
                color: (styleData.selected) ? "white" : tree.lightGreyColor
            }
        }

        onDoubleClicked:{ Controller.fileSelected(currentIndex); tree.expand(tree.currentIndex); tree.addTab();
            tree.readFile(Controller.fileSelected(currentIndex));
        }


        // TODO , expandAll is not Ray2
        Component.onCompleted:{ tree.expandAll(); tree.addTab();}
        function expandAll() {
            // rowCount just dosn't work, it is a lazy count, QFileSystem model is not ray2 and uses another thread to count the rows
            var n = 20; console.log("n=",n,fileSystemModel.columnCount());
            for (var i = 0 ; i < n; i++)
            {
                var index = tree.indexAt(i,0);
                tree.expand(index);
            }
        }
    }





}
