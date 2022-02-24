#ifndef ACACIAWINDOW_H
#define ACACIAWINDOW_H

#include <KXmlGuiWindow>

class AcaciaWindow : public KXmlGuiWindow {
public:
    explicit AcaciaWindow(QWidget *parent = nullptr);
private:
    void setupActions();
};

#endif
