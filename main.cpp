#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QFont>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load and set SF Pro Text from resources as the default app font, with debug
    const char* fontPath = ":/new/fonts/SF-Pro-Text-Regular.otf";
    qDebug() << "Trying to load font from resource path:" << fontPath << ", exists?" << QFile::exists(fontPath);

    auto trySetAppFontFromId = [&](int id) -> bool {
        if (id == -1) return false;
        const QStringList families = QFontDatabase::applicationFontFamilies(id);
        qDebug() << "Loaded fontId:" << id << ", families:" << families;
        if (families.isEmpty()) return false;
        QFont defaultFont(families.at(0), 10);
        a.setFont(defaultFont);
        qDebug() << "Application font set to:" << a.font().family();
        return true;
    };

    int fontId = QFontDatabase::addApplicationFont(fontPath);
    if (!trySetAppFontFromId(fontId)) {
        qDebug() << "addApplicationFont() failed, falling back to addApplicationFontFromData";
        QFile f(fontPath);
        if (f.open(QIODevice::ReadOnly)) {
            const QByteArray bytes = f.readAll();
            f.close();
            fontId = QFontDatabase::addApplicationFontFromData(bytes);
            if (!trySetAppFontFromId(fontId)) {
                qDebug() << "addApplicationFontFromData failed as well.";
            }
        } else {
            qDebug() << "Could not open font resource for reading:" << fontPath;
        }
    }
    MainWindow w;
    qDebug() << "MainWindow font family:" << w.font().family();
    if (auto btn = w.findChild<QPushButton*>("basicSettingBtn")) {
        qDebug() << "basicSettingBtn font family:" << btn->font().family();
    }
    w.show();
    return a.exec();
}
