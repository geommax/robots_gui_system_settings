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
    // Build a simple navigation button list
    QList<QPushButton*> navButtons = {
        ui->basicSettingBtn,
        ui->languageSettingBtn,
        ui->distributionModeBtn,
        ui->advertisingSettingBtn,
        ui->versionSettingBtn,
        ui->networkSettingBtn,
    };

    // Connect each button's clicked signal to update the selected visual state
    for (QPushButton* b : navButtons) {
        if (!b) continue;
        // capture a copy of the list so the lambda can iterate it safely
        QList<QPushButton*> copy = navButtons;
        connect(b, &QPushButton::clicked, this, [b, copy]() {
            for (QPushButton* other : copy) {
                if (!other) continue;
                if (other == b) other->setStyleSheet(BUTTON_PRESSED_STYLE);
                else other->setStyleSheet(BUTTON_RELEASED_STYLE);
            }
        });
    }

    // Set a sensible initial selection: basic settings
    if (ui->basicSettingBtn) {
        for (QPushButton* other : navButtons) if (other) other->setStyleSheet(BUTTON_RELEASED_STYLE);
        ui->basicSettingBtn->setStyleSheet(BUTTON_PRESSED_STYLE);
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
