import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4


TabView {
    anchors.fill: parent
    Tab {
        title: "ray2"
        Rectangle { color:"red" ; anchors.fill: parent;}

    }
    Tab {
        title: "directory"
        DirectoryView {}
    }


}
