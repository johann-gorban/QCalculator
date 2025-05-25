#include "MainWindow.hpp"

#include <QUiLoader>
#include <QFile>
#include <QString>
#include <QLayout>
#include <QVBoxLayout>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->setupUI();
    this->setupSlots();

    this->setWindowTitle("Calculator");

    this->facade = new Facade();
}

MainWindow::~MainWindow() {
    if (this->facade)
        delete this->facade;
}

void MainWindow::setupUI() {
    QString ui_path = ":/gui/forms/mainwindow.ui";

    QFile ui_form(ui_path);

    if (!ui_form.open(QFile::ReadOnly)) {
        std::cout << "Error: cannot open file" << std::endl;
    } else {
        QUiLoader ui_loader;
        
        this->centralWidget = ui_loader.load(&ui_form, this);
        this->outputDisplay = new OutputLine();

        this->setupKeyboard();

        QVBoxLayout *main_layout = new QVBoxLayout(this);
        main_layout->addWidget(this->outputDisplay);
        main_layout->addWidget(this->centralWidget);
        
        this->setLayout(main_layout);
        ui_form.close();
    }
}

void MainWindow::setupKeyboard() {
    this->buttons["0"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber0");
    this->buttons["1"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber1");
    this->buttons["2"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber2");
    this->buttons["3"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber3");
    this->buttons["4"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber4");
    this->buttons["5"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber5");
    this->buttons["6"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber6");
    this->buttons["7"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber7");
    this->buttons["8"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber8");
    this->buttons["9"] = this->centralWidget->findChild<QPushButton*>("ButtonNumber9");

    this->buttons["("] = this->centralWidget->findChild<QPushButton*>("ButtonLeftParenthesis");
    this->buttons[")"] = this->centralWidget->findChild<QPushButton*>("ButtonRightParenthesis");
    this->buttons["float_point"] = this->centralWidget->findChild<QPushButton*>("ButtonFloatPoint");

    this->buttons["add"] = this->centralWidget->findChild<QPushButton*>("ButtonAdd");
    this->buttons["sub"] = this->centralWidget->findChild<QPushButton*>("ButtonSubstract");
    this->buttons["mul"] = this->centralWidget->findChild<QPushButton*>("ButtonMultiply");
    this->buttons["div"] = this->centralWidget->findChild<QPushButton*>("ButtonDivide");
    this->buttons["pow"] = this->centralWidget->findChild<QPushButton*>("ButtonPower");

    this->buttons["sqrt"] = this->centralWidget->findChild<QPushButton*>("ButtonSqrt");

    this->buttons["MC"] = this->centralWidget->findChild<QPushButton*>("ButtonMemoryClear");
    this->buttons["MR"] = this->centralWidget->findChild<QPushButton*>("ButtonMemoryRead");
    this->buttons["M+"] = this->centralWidget->findChild<QPushButton*>("ButtonMemoryAdd");
    this->buttons["M-"] = this->centralWidget->findChild<QPushButton*>("ButtonMemorySubstract");

    this->buttons["Remove"] = this->centralWidget->findChild<QPushButton *>("ButtonBackspace");
    this->buttons["Calculate"] = this->centralWidget->findChild<QPushButton*>("ButtonProcess");
    this->buttons["Clear"] = this->centralWidget->findChild<QPushButton*>("ButtonClearInput");
}

void MainWindow::setupSlots() {
    QObject::connect(this->buttons["Calculate"], &QPushButton::clicked, this, &MainWindow::calculate);
    QObject::connect(this->buttons["Clear"], &QPushButton::clicked, this, &MainWindow::clear);
    QObject::connect(this->buttons["Remove"], &QPushButton::clicked, this, &MainWindow::backspace);

    QObject::connect(this->buttons["0"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("0"); });
    QObject::connect(this->buttons["1"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("1"); });
    QObject::connect(this->buttons["2"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("2"); });
    QObject::connect(this->buttons["3"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("3"); });
    QObject::connect(this->buttons["4"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("4"); });
    QObject::connect(this->buttons["5"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("5"); });
    QObject::connect(this->buttons["6"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("6"); });
    QObject::connect(this->buttons["7"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("7"); });
    QObject::connect(this->buttons["8"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("8"); });
    QObject::connect(this->buttons["9"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("9"); });
    QObject::connect(this->buttons["float_point"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("."); });

    QObject::connect(this->buttons["("], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("("); });
    QObject::connect(this->buttons[")"], &QPushButton::clicked, this, [this]() { this->outputDisplay->insert(")"); });

    QObject::connect(this->buttons["MC"], &QPushButton::clicked, this, &MainWindow::clearMemory);
    QObject::connect(this->buttons["MR"], &QPushButton::clicked, this, &MainWindow::getMemory);
    QObject::connect(this->buttons["M+"], &QPushButton::clicked, this, &MainWindow::addMemory);
    QObject::connect(this->buttons["M-"], &QPushButton::clicked, this, &MainWindow::subsractMemory);

    QObject::connect(this->buttons["add"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("+"); });
    QObject::connect(this->buttons["sub"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("-"); });
    QObject::connect(this->buttons["mul"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("*"); });
    QObject::connect(this->buttons["div"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("/"); });
    QObject::connect(this->buttons["pow"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insert("^"); });

    QObject::connect(this->buttons["sqrt"] , &QPushButton::clicked, this, [this]() { this->outputDisplay->insertFunction("sqrt"); });
}

void MainWindow::calculate() {
    QString displayData = this->outputDisplay->getContent();
    if (!this->outputDisplay->isAnswer()) {
        displayData = QString::fromStdString(this->facade->calculate(displayData.toStdString()));
    }
    this->outputDisplay->setAnswer(displayData);
}

void MainWindow::clear() {
    this->outputDisplay->clear();
}

void MainWindow::backspace() {
    this->outputDisplay->backspace();
}

void MainWindow::clearMemory() {
    this->facade->memory_clear();
}

void MainWindow::addMemory() {
    QString displayData = this->outputDisplay->getContent();
    this->facade->memory_add(displayData.toStdString());
}

void MainWindow::subsractMemory() {
    QString displayData = this->outputDisplay->getContent();
    this->facade->memory_substract(displayData.toStdString());
}

void MainWindow::getMemory() {
    QString memoryData = QString::fromStdString(this->facade->memory_read());
    this->outputDisplay->setAnswer(memoryData);
}
