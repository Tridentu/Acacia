#include <QApplication>
#include <QAction>
#include <KLocalizedString>
#include <KActionCollection>
#include <KStandardAction>
#include "acaciawindow.h"

AcaciaWindow::AcaciaWindow(QWidget *parent) : KXmlGuiWindow(parent) {
 setupActions();
}

void AcaciaWindow::setupActions(){
  KStandardAction::quit(qApp, &QCoreApplication::quit, actionCollection());
  setupGUI(Default, "Acaciaui.rc");
}
