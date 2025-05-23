#pragma once

#include "menu/facade.hpp"
#include "output_line.hpp"

#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    Facade *facade;
    OutputLine *output;
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private:
    void setup_ui();

    void setup_signals();
private slots:
    void calculate();

    void clear();

    void clear_memory();

    void add_memory();

    void subsract_memory();

    void get_memory();
};