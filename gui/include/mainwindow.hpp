#pragma once

#include "menu/facade.hpp"
#include "output_line.hpp"

#include <QWidget>
#include <QPushButton>

#include <QMap>
#include <QString>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    QWidget *_central_widget;
    Facade *_facade;
    OutputLine *_output;
    QMap<QString, QPushButton *> _buttons;
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow() = default;
private:
    void setup_ui();

    void setup_keyboard();

    void setup_slots();
private slots:
    void calculate();

    void clear();

    void clear_memory();

    void add_memory();

    void subsract_memory();

    void get_memory();
};