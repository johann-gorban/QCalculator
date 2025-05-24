#include "mainwindow.hpp"

#include <QUiLoader>
#include <QFile>
#include <QString>
#include <QLayout>
#include <QVBoxLayout>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->setup_ui();
    this->setup_slots();

    this->setWindowTitle("Calculator");

    this->_facade = new Facade();
}

void MainWindow::setup_ui() {
    QString ui_path = ":/gui/forms/mainwindow.ui";

    QFile ui_form(ui_path);

    if (!ui_form.open(QFile::ReadOnly)) {
        std::cout << "Error: cannot open file" << std::endl;
    }
    else {
        QUiLoader ui_loader;
        
        this->_central_widget = ui_loader.load(&ui_form, this);
        this->_output = new OutputLine();

        this->setup_keyboard();

        QVBoxLayout *main_layout = new QVBoxLayout(this);
        main_layout->addWidget(this->_output);
        main_layout->addWidget(this->_central_widget);
        
        this->setLayout(main_layout);
        ui_form.close();
    }
}

void MainWindow::setup_keyboard() {
    this->_buttons["0"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber0");
    this->_buttons["1"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber1");
    this->_buttons["2"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber2");
    this->_buttons["3"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber3");
    this->_buttons["4"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber4");
    this->_buttons["5"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber5");
    this->_buttons["6"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber6");
    this->_buttons["7"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber7");
    this->_buttons["8"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber8");
    this->_buttons["9"] = this->_central_widget->findChild<QPushButton*>("ButtonNumber9");

    this->_buttons["("] = this->_central_widget->findChild<QPushButton*>("ButtonLeftParenthesis");
    this->_buttons[")"] = this->_central_widget->findChild<QPushButton*>("ButtonRightParenthesis");
    this->_buttons["float_point"] = this->_central_widget->findChild<QPushButton*>("ButtonFloatPoint");

    this->_buttons["add"] = this->_central_widget->findChild<QPushButton*>("ButtonAdd");
    this->_buttons["sub"] = this->_central_widget->findChild<QPushButton*>("ButtonSubstract");
    this->_buttons["mul"] = this->_central_widget->findChild<QPushButton*>("ButtonMultiply");
    this->_buttons["div"] = this->_central_widget->findChild<QPushButton*>("ButtonDivide");
    this->_buttons["pow"] = this->_central_widget->findChild<QPushButton*>("ButtonPower");

    this->_buttons["sqrt"] = this->_central_widget->findChild<QPushButton*>("ButtonSqrt");

    this->_buttons["Calculate"] = this->_central_widget->findChild<QPushButton*>("ButtonProcess");
    this->_buttons["ClearInput"] = this->_central_widget->findChild<QPushButton*>("ButtonClearInput");
}

void MainWindow::setup_slots() {
    QObject::connect(this->_buttons["Calculate"], &QPushButton::clicked, this, &MainWindow::calculate);
    QObject::connect(this->_buttons["ClearInput"], &QPushButton::clicked, this, &MainWindow::clear);

    QObject::connect(this->_buttons["0"], &QPushButton::clicked, this, [this]() { this->_output->insert("0"); });
    QObject::connect(this->_buttons["1"], &QPushButton::clicked, this, [this]() { this->_output->insert("1"); });
    QObject::connect(this->_buttons["2"], &QPushButton::clicked, this, [this]() { this->_output->insert("2"); });
    QObject::connect(this->_buttons["3"], &QPushButton::clicked, this, [this]() { this->_output->insert("3"); });
    QObject::connect(this->_buttons["4"], &QPushButton::clicked, this, [this]() { this->_output->insert("4"); });
    QObject::connect(this->_buttons["5"], &QPushButton::clicked, this, [this]() { this->_output->insert("5"); });
    QObject::connect(this->_buttons["6"], &QPushButton::clicked, this, [this]() { this->_output->insert("6"); });
    QObject::connect(this->_buttons["7"], &QPushButton::clicked, this, [this]() { this->_output->insert("7"); });
    QObject::connect(this->_buttons["8"], &QPushButton::clicked, this, [this]() { this->_output->insert("8"); });
    QObject::connect(this->_buttons["9"], &QPushButton::clicked, this, [this]() { this->_output->insert("9"); });
    QObject::connect(this->_buttons["float_point"], &QPushButton::clicked, this, [this]() { this->_output->insert("."); });

    QObject::connect(this->_buttons["("], &QPushButton::clicked, this, [this]() { this->_output->insert("("); });
    QObject::connect(this->_buttons[")"], &QPushButton::clicked, this, [this]() { this->_output->insert(")"); });

    QObject::connect(this->_buttons["add"] , &QPushButton::clicked, this, [this]() { this->_output->insert("+"); });
    QObject::connect(this->_buttons["sub"] , &QPushButton::clicked, this, [this]() { this->_output->insert("-"); });
    QObject::connect(this->_buttons["mul"] , &QPushButton::clicked, this, [this]() { this->_output->insert("*"); });
    QObject::connect(this->_buttons["div"] , &QPushButton::clicked, this, [this]() { this->_output->insert("/"); });
    QObject::connect(this->_buttons["pow"] , &QPushButton::clicked, this, [this]() { this->_output->insert("^"); });

    QObject::connect(this->_buttons["sqrt"] , &QPushButton::clicked, this, [this]() { this->_output->insert_function("sqrt"); });
}

void MainWindow::calculate() {
    QString display_data = this->_output->get_content();
    if (!this->_output->is_answer()) {
        display_data = QString::fromStdString(this->_facade->calculate(display_data.toStdString()));
    }
    this->_output->set_answer(display_data);
}

void MainWindow::clear() {
    this->_output->clear();
}

void MainWindow::clear_memory() {
    this->_facade->memory_clear();
}

void MainWindow::add_memory() {
    QString display_data = this->_output->get_content();
    this->_facade->memory_add(display_data.toStdString());
}

void MainWindow::subsract_memory() {
    QString display_data = this->_output->get_content();
    this->_facade->memory_substract(display_data.toStdString());
}

void MainWindow::get_memory() {
    QString memory_data = QString::fromStdString(this->_facade->memory_read());
    this->_output->set_answer(memory_data);
}
