import QtQuick 2.0
import Sailfish.Silica 1.0
import com.example 1.0

Page {
    id: page

    SilicaListView {

        anchors.fill: parent

        model: DemoModel {
            id: dmodel
        }

        header: PageHeader {
            id: header
            title: "Unusual animals"
        }

        delegate: BackgroundItem {
            Label {
                x: Theme.horizontalPageMargin
                text: name
            }
            onClicked: dmodel.activate(index)
        }

    }
}
