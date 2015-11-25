import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    Label {
        id: label
        anchors.centerIn: parent
        text: fh.isEnabled()?qsTr("Firefox as default:\nEnabled"):qsTr("Firefox as default:\nDisabled")
        font.pixelSize: 20
    }
}
