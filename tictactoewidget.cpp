#include "tictactoewidget.h"


TicTacToeWidget::TicTacToeWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);
    m_currentPlayer = Player::Invalid;
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            QPushButton *button = new QPushButton(" ");
            gridLayout->addWidget(button, row, column);
            m_board.append(button);
            mapper->setMapping(button,m_board.count() - 1);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
        }
    }
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleButtonClick(int)));
}


void TicTacToeWidget::setCurrentPlayer(Player p){
    if(m_currentPlayer == p){
        return;
    }
    m_currentPlayer = p;
    emit currentPlayerChanged(p);
}

void TicTacToeWidget::initNewGame()
{
    for(QPushButton *button: m_board){
        button->setText(" ");
    }
    setCurrentPlayer(Player::Player1);
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition()
{
    Player result = Player::Invalid;
    // check horizontals
    for(int row = 0; row < 3; ++row) {
        result = checkLineWinCondition(row * 3,
                                          row * 3 + 1,
                                          row * 3 + 2);
        if (result != Player::Invalid) {
            return result;
        }
    }
    // check verticals
    for(int column = 0; column < 3; ++column) {
         result = checkLineWinCondition(column,
                                           3 + column,
                                           6 + column);
        if (result != Player::Invalid) {
            return result;
        }
    }
    // check diagonals
    result = checkLineWinCondition(0, 4, 8);
    if (result != Player::Invalid) {
        return result;
    }
    result = checkLineWinCondition(2, 4, 6);
    if (result != Player::Invalid) {
        return result;
    }
    // check if there are unoccupied fields left
    for(QPushButton *button: m_board) {
        if(button->text() == " ") {
            return Player::Invalid;
        }
    }
    return Player::Draw;

}

TicTacToeWidget::Player TicTacToeWidget::checkLineWinCondition(int index1, int index2, int index3)
{
    if((m_board[index1]->text() == m_board[index2]->text()) && (m_board[index2]->text()== m_board[index3]->text())){
        if(m_board[index1]->text() != " "){
            return m_board[index1]->text() == "X" ? Player::Player1 : Player::Player2;
        }
    }
    return  Player::Invalid;
}

void TicTacToeWidget::handleButtonClick(int index)
{
    if(m_currentPlayer == Player::Invalid){
        return; // game is not started
    }
    if(index < 0 || index >= m_board.size()){
        return; // out of the bounds check
    }
    QPushButton *button = m_board[index];
    if(button->text() != " ") return; //invalid move
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    Player winner = checkWinCondition();
    if(winner == Player::Invalid){
        setCurrentPlayer(currentPlayer() == Player::Player1 ? Player::Player2 : Player::Player1);
        return;
    } else {
        emit gameOver(winner);
    }

}
