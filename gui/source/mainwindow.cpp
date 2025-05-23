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
    QString ui_path = ":/gui/forms/mainwindow.ui";

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

void MainWindow::calculate() {
    // Get expression from OutputLine
    // Calculate it, if it is an answer
    // If not, do not touch (optimization)

    // Then get the answer
    // Set text to it as answer
}

void MainWindow::clear() {
    // Just clearoutput (set to zero as answer)
}

void MainWindow::clear_memory() {
    // Clear memory using facade
}

void MainWindow::add_memory() {
    // Get value from outputline
    // Convert to double
    // Call facade method
}

void MainWindow::subsract_memory() {
    // Get value from outputline
    // Convert to double
    // Call facade method
}

void MainWindow::get_memory() {
    // Call facade method
    // Convert to string
    // Set value as answer
}
