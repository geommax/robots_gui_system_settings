#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "headers/style_sheet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_basicSettingBtn_clicked();
    void on_languageSettingBtn_clicked();
    void on_networkSettingBtn_clicked();
    void on_advertisingSettingBtn_clicked();
    void on_distributionModeBtn_clicked();
    void on_versionSettingBtn_clicked();


private:
    void attachAllBtnsToPressAnimation();

private:
    Ui::MainWindow *ui;
    
};
#endif // MAINWINDOW_H
