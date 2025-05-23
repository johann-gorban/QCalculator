#include "mainwindow.hpp"

#include <QUiLoader>
#include <QFile>
#include <QString>

#include <QCoreApplication>
#include <QDir>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->setup_ui();
    this->setWindowTitle("Calculator");
}

void MainWindow::setup_ui() {
    QString ui_path = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../forms/mainwindow.ui");

    QFile ui_form(ui_path);

    if (!ui_form.open(QFile::ReadOnly)) {
        std::cout << "Error: cannot open file" << std::endl;
    }
    else {
        QUiLoader ui_loader;
        QWidget *CentralWidget = ui_loader.load(&ui_form, this);
        ui_form.close();

        this->setLayout(CentralWidget->layout());
    }
}

MainWindow::~MainWindow() {

}

void MainWindow::calculate(const QString &) {
}

void MainWindow::clear() {
}

void MainWindow::clear_memory() {
}

void MainWindow::add_memory(const QString &) {
}

void MainWindow::subsract_memory(const QString &) {
}

const QString MainWindow::get_memory(const QString &) {
    return {};
}
