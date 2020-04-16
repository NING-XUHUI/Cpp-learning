#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "stone.h"
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

    Stone _s[32];
    int _r;//半径
    int _selectid;
    QPoint center(int row,int col);
    QPoint center(int id);
    /* 返回象棋棋盘行列对应的像素坐标 */
    void drawStone(QPainter& painter,int id);

    void paintEvent(QPaintEvent *);

    // void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool getRowCol(QPoint pt, int& row,int& col);

    bool canMove(int moveid,int row,int col ,int killid);
    bool canMove1(int moveid,int row,int col ,int killid);
    bool canMove2(int moveid,int row,int col ,int killid);
    bool canMove3(int moveid,int row,int col ,int killid);
    bool canMove4(int moveid,int row,int col ,int killid);
    bool canMove5(int moveid,int row,int col ,int killid);
    bool canMove6(int moveid,int row,int col ,int killid);
    bool canMove7(int moveid,int row,int col ,int killid);
signals:

};

#endif // BOARD_H
