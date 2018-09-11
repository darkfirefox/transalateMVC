#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "historymodel.h"
#include "translatemodel.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/translateMVC.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    QGuiApplication * application = SailfishApp::application(argc,argv);
    QQuickView * view = SailfishApp :: createView();
    qmlRegisterType<HistoryModel>("MyHistory", 1, 0, "HistoryModel");
    qmlRegisterType<TranslateModel>("MyTranslate", 1, 0, "TransalteModel");
    view->setSource (SailfishApp::pathTo( "qml/translateMVC.qml"));
    view->show();
    return application->exec();
    //return SailfishApp::main(argc, argv);
}
