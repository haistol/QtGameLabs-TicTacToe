#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tictactoewidget.h"

#include <QLabel>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setLabelBold(QLabel *label, bool isBold);

private slots:
    void updateNameLabels();
    void startNewGame();
    void handleGameOver(TicTacToeWidget::Player winner);
};

#endif // MAINWINDOW_H
