#pragma once

#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    void setup_ui();
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
};