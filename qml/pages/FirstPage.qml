import QtQuick 2.0
import Sailfish.Silica 1.0
import MyTranslate 1.0

Page {
    id: page
    allowedOrientations: Orientation.All

    TransalteModel{
        id: transalte
    }

    SilicaFlickable {
        anchors.fill: parent
        PullDownMenu {
            MenuItem {
                text: qsTr("Show history")
                onClicked: pageStack.push(Qt.resolvedUrl("HistoryPage.qml"))
            }
        }
        Column{
            anchors{
                fill:parent
                leftMargin: Theme.horizontalPageMargin
                rightMargin: Theme.horizontalPageMargin
            }
            Row{
                Text{
                    text:transalte.langFrom
                    font.family: "Helvetica"
                    color:"blue"
                    font.pointSize: 48
                }
                Text{
                    text:transalte.langTo
                    color:"green"
                    font.family: "Helvetica"
                    font.pointSize: 48
                }
            }
            Button{
                text: "swap"
                onClicked: transalte.swap()
            }

            TextField{
                text:transalte.sourceText
                onTextChanged:transalte.sourceText=text;
            }
            Text{
                id:tr
                text:transalte.translatedText
                color: "red"
            }


            Button{
                text: "Translate"
                onClicked: {
                    transalte.translate()
                }
            }
        }
    }
}
