#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QSignalMapper>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    enum class Player {
        Invalid, Player1, Player2, Draw
    };
    Q_ENUM(Player)

    Player currentPlayer() const{ return m_currentPlayer; }
    void setCurrentPlayer(Player P);
    void initNewGame();

private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;

signals:
    void currentPlayerChanged(Player);
    void gameOver(Player);

public slots:
    void hanndleButtonClick(int index);
};

#endif // TICTACTOEWIDGET_H
