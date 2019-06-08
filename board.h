#ifndef BOARD_H
#define BOARD_H

#include <QVector>

class Board
{
    int N;
public:
    Board();
    void n_queens(int n);
    void backtrack(QVector<int>&, int current_row, int N);
    bool construct_candidates(const QVector<int>&, int row, int N, QVector<int>&);
    bool is_safe_square(const QVector<int>&, int row, int col);
    bool is_solution(const QVector<int>&, int N);
    void print_solution(const QVector<int>&, int N);

};

#endif // BOARD_H
