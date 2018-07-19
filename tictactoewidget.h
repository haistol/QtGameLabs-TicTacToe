#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
private:
    QVector<QPushButton*> m_board;

signals:

public slots:
};

#endif // TICTACTOEWIDGET_H
