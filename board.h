#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QString>

class Board
{
public:
    int N;
    Board();
    bool construct_candidates(const QVector<int>&, int row, int N, QVector<int>&);
    bool is_safe_square(const QVector<int>&, int row, int col);
    bool is_solution(const QVector<int>&, int N);
    QString get_solution(const QVector<int>&, int N);

};

#endif // BOARD_H
