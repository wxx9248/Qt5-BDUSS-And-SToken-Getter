#include "mainwindow.hpp"

#include <QApplication>
#include <QTextCodec>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

int main(int argc, char *argv[])
{
    QTextCodec *textCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(textCodec);

    QCoreApplication::setOrganizationDomain("httydbar.com");
    QCoreApplication::setOrganizationName(u8"驯龙高手吧");
    QCoreApplication::setApplicationName(u8"BDUSS和SToken获取器");
    QCoreApplication::setApplicationVersion("1.0.0");

    QApplication application(argc, argv);

    MainWindow mainWindow(QUrl("https://tieba.baidu.com"));

    mainWindow.show();
    return application.exec();
}
