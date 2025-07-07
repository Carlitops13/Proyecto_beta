#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    QLabel *label = new QLabel("Andrea");
    label -> show();
    label -> resize(200,100);
    label -> setWindowTitle("Mi ventana Lubswer Cambio");

    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Proyecto_Alfa_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
