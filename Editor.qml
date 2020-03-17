import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.4

Tab {
    id:tab

    TextArea {
        id:textArea
        anchors.fill: parent
        style: TextAreaStyle {
            backgroundColor: "#222831"
            textColor: "#eeeeee"
            selectionColor: "#b55400"
            selectedTextColor: "#eeeeee"
            font: { font.family = "Helvetica"; font.pointSize = 13;}
        }
//        textMargin: 30
        function TextContent(content)
        {
            textArea.text  = content
        }
    }
}
