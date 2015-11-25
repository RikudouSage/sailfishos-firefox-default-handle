import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    SilicaFlickable {
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                id: enableitem
                text: qsTr("Enable Firefox")
                visible: !fh.isEnabled()
                onClicked: {
                    fh.enable();
                    enableitem.visible = false;
                    disableitem.visible = true;
                }
            }

            MenuItem {
                id: disableitem
                text: qsTr("Disable Firefox")
                visible: fh.isEnabled()
                onClicked: {
                    fh.disable();
                    enableitem.visible = true;
                    disableitem.visible = false;
                }
            }
        }

        contentHeight: column.height

        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
            PageHeader {
                title: qsTr("Firefox as default browser")
            }
            Label {
                width: screen.width - 30
                x: 20
                text: qsTr("You can enable Firefox as default browser. This action involves: enabling adb, moving default http handler and copying new handlers. All original files are backed up and can be restored easily.")
                wrapMode: Text.Wrap
            }
            Label {
                width: screen.width - 30
                x: 20
                wrapMode: Text.Wrap
                text: qsTr("IMPORTANT: Do not delete this app without disabling!!! If you do so, you cannot restore to original url handler.")
            }
        }
    }
}


