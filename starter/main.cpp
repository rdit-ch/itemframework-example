#include <QApplication>
#include "helper/startup_helper.h"
#include "usercore.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("Example Organisation");
    QApplication::setOrganizationDomain("example.com");
    QApplication::setApplicationName("Example Application");
    QApplication::setApplicationDisplayName("Example Application 1.0");
    QApplication::setApplicationVersion("1.0.2.1-abcdefa");

    StartupHelper::ensureCoreGetsLinked();
    LinkerHelper::ensureUserCoreGetsLinked();

    return a.exec();
}
