import QtQuick 2.0
import Sailfish.Silica 1.0
import MyTranslate 1.0

Page {
    id: page
    allowedOrientations: Orientation.All

    TransalteModel{
        id: transalte
        onPageChanged: {
            pageStack.push(Qt.resolvedUrl(transalte.page));
        }
    }
    SilicaFlickable {
        anchors.fill: parent
        PullDownMenu {
            MenuItem {
                text: qsTr("Show history")
                onClicked: transalte.historyPage();
            }
        }
        Column{
            anchors{
                fill:parent
                leftMargin: Theme.horizontalPageMargin
                rightMargin: Theme.horizontalPageMargin
            }
            ComboBox{
                label:"From"
                menu: ContextMenu{
                    Repeater{
                        model:transalte.combolist1
                        delegate: MenuItem{
                            text: transalte.combolist1[index]
                        }
                    }
                }
                currentIndex: transalte.cbCount1
                onCurrentIndexChanged: transalte.cbCount1=currentIndex;
            }
            ComboBox{
                label:"To"
                menu: ContextMenu{
                    Repeater{
                        model:transalte.combolist2
                        delegate: MenuItem{
                            text: transalte.combolist2[index]
                        }
                    }
                }
                currentIndex: transalte.cbCount2
                onCurrentIndexChanged: transalte.cbCount2=currentIndex
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
