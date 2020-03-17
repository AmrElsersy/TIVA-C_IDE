import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4


TabView {
    // may be will be benifit      {currentIndex, currentItem ,count}
    id: tabView
    MouseArea
    {
        anchors.fill: parent
        onClicked: {
            tabView.newTab("222");
        }
    }

    Component.onCompleted: tabView.newTab("ray2","");

    function newTab(titleTab,textContent)
    {
        var componentEditor = Qt.createComponent("Editor.qml");
        var ray2 = componentEditor.createObject(tabView, {title:titleTab , text:textContent});
    }
}
