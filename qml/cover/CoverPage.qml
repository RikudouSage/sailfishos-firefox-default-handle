import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    Label {
        id: label
        anchors.centerIn: parent
        text: qsTr("Firefox as default")
        font.pixelSize: 20
    }
    Timer {
        running: true
        interval: 500
        onTriggered: {
            if(fh.isEnabled()) {
                label.text = qsTr("Firefox as default:\nEnabled");
            } else {
                label.text = qsTr("Firefox as default:\nDisabled");
            }
        }
        repeat: true
    }
}
