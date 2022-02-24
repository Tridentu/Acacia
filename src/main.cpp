#include <cstdlib>
#include <QApplication>
#include <QCommandLineParser>
#include <KAboutData>
#include <KLocalizedString>
#include "acaciawindow.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("Acacia");

    KAboutData aboutData(
            QStringLiteral("Acacia"),
            i18n("Acacia PM"),
            QStringLiteral("0.2"),
            i18n("The GUI version of the Caravel Package Manager."),
            KAboutLicense::GPL,
            i18n("(c) 2022"),
            i18n("This app is not intended as a replacement for Discover."),
            QStringLiteral("https://tridentu.github.io/acacia"),
            QStringLiteral("tridentuorg@protonmail.com")
    );
    KAboutData::setApplicationData(aboutData);

    QCommandLineParser parser;

    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    AcaciaWindow *window = new AcaciaWindow();
    window->show();

    return app.exec();


}
