import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 400
    height: 400
    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }

    }
}
