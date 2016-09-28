#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QDockWidget>

#include "usercore.h"
#include "helper/singleton.h"

namespace Ui {
class DisplayWidget;
}

class USERCORE_EXPORT DisplayWidget : public QDockWidget, public Singleton<DisplayWidget>
{
    Q_OBJECT
    Q_INTERFACES(AbstractSingleton)

    Q_CLASSINFO("guiModule", "true")
    Q_CLASSINFO("dependsOn", "GuiManager")

public:
    Q_INVOKABLE explicit DisplayWidget(QWidget *parent = 0);
    ~DisplayWidget();
    void setText(QString const& text);

protected:
    bool postInit();
    bool preDestroy();

private:
    Ui::DisplayWidget *ui;

    int const _maxListItemsCount = 5;
};

#endif // DISPLAYWIDGET_H
