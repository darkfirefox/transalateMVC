import QtQuick 2.0
import Sailfish.Silica 1.0
import MyHistory 1.0

Page {
    id: page

    SilicaListView {

        anchors.fill: parent

        model: HistoryModel {
            id: dmodel
        }

        header: PageHeader {
            id: header
            title: "History"
        }

        delegate: ListItem {
            id: listItem
            menu: contextMenu
            ListView.onRemove: animateRemoval(listItem)
            function remove() {
                remorseAction("Deleting", function() { dmodel.deleteRow(index) })
            }
            width: parent.width
            height: Theme.itemSizeMedium
            Column{
                anchors{
                    fill:parent
                    leftMargin: Theme.horizontalPageMargin
                    rightMargin: Theme.horizontalPageMargin
                    topMargin: Theme.paddingLarge
                }
                Row{
                    anchors.right: parent.right
                    anchors.left: parent.left

                    height: childrenRect.height
                    Label{
                        width: parent.width/8
                        horizontalAlignment: "AlignLeft"
                        text: langF
                    }
                    Label{
                        width: 7*parent.width/8
                        horizontalAlignment: Text.AlignRight
                        text: textF
                    }
                }
                Row{
                    anchors.right: parent.right
                    anchors.left: parent.left

                    height: childrenRect.height
                    Label{
                        width: parent.width/8
                        horizontalAlignment: "AlignLeft"
                        text: langT
                    }
                    Label{
                        width: 7*parent.width/8
                        horizontalAlignment: Text.AlignRight
                        text: textT
                    }
                }
            }
            Component {
                id: contextMenu
                ContextMenu {
                    MenuItem {
                        text: "Remove"
                        onClicked: remove()
                    }
                }
            }
        }

    }
}
