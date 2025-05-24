#pragma once

#include <QWidget>
#include <QLineEdit>

class OutputLine : public QWidget {
    Q_OBJECT
private:
    QLineEdit *_output_line;
    bool _is_answer;
public: 
    explicit OutputLine(QWidget *parent = nullptr);

    bool is_answer() const;

    const QString get_content() const;
public slots:
    void set_answer(const QString &text);

    void insert(const QString &text);

    void insert_function(const QString &text);

    void clear();
};