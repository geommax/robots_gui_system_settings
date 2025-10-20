#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    attachAllBtnsToPressAnimation();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::attachAllBtnsToPressAnimation()
{
    struct ButtonInfo {
        QPushButton* btn;
        QString originalStyle;
    };
    QList<ButtonInfo> buttons = {
        {ui->basicSettingBtn, ui->basicSettingBtn->styleSheet()},
        {ui->languageSettingBtn, ui->languageSettingBtn->styleSheet()},
        {ui->distributionModeBtn, ui->distributionModeBtn->styleSheet()},
        {ui->advertisingSettingBtn, ui->advertisingSettingBtn->styleSheet()},
        {ui->versionSettingBtn, ui->versionSettingBtn->styleSheet()},
        {ui->networkSettingBtn, ui->networkSettingBtn->styleSheet()},
    };

    for (const ButtonInfo& info : buttons) {
        if (!info.btn) continue;

        connect(info.btn, &QPushButton::pressed, this, [btn=info.btn]() {
            btn->setStyleSheet(BUTTON_PRESSED_STYLE);
        });

        connect(info.btn, &QPushButton::released, this, [btn=info.btn]() {
            btn->setStyleSheet(BUTTON_RELEASED_STYLE);
        });
    }
}

void MainWindow::on_basicSettingBtn_clicked()
{
    qDebug() << "basicSettingBtn clicked";
    if (ui && ui->stackedWidget) {
        ui->stackedWidget->setCurrentWidget(ui->basicPageWidget);
    }

}

void MainWindow::on_languageSettingBtn_clicked()
{
    qDebug() << "languageSettingBtn clicked";
    if (ui && ui->stackedWidget) {
        ui->stackedWidget->setCurrentWidget(ui->languagePageWidget);
    }
}

void MainWindow::on_networkSettingBtn_clicked()
{
    qDebug() << "networkSettingBtn clicked";
    if (ui && ui->stackedWidget) {
        ui->stackedWidget->setCurrentWidget(ui->networkPageWidget);
    }
}

void MainWindow::on_advertisingSettingBtn_clicked()
{
    qDebug() << "advertisingSettingBtn clicked";
}

void MainWindow::on_distributionModeBtn_clicked()
{
    qDebug() << "distributionModeBtn clicked";
    if (ui && ui->stackedWidget) {
        ui->stackedWidget->setCurrentWidget(ui->distributionModePageWidget);
    }
}

void MainWindow::on_versionSettingBtn_clicked()
{
    qDebug() << "versionSettingBtn clicked";
}
