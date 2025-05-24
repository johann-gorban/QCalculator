#pragma once

#include "menu/facade.hpp"
#include "OutputLine.hpp"

#include <QWidget>
#include <QPushButton>
#include <QMap>
#include <QString>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    QWidget *centralWidget;
    Facade *facade;
    OutputLine *outputDisplay;
    QMap<QString, QPushButton *> buttons;
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private:
    void setupUI();

    void setupKeyboard();

    void setupSlots();
private slots:
    void calculate();

    void clear();

    void clearMemory();

    void addMemory();

    void subsractMemory();

    void getMemory();
};