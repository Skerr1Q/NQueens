#include "board.h"
#include <iostream>
#include <cmath>
#include <QVector>

Board::Board()
{
    N = 0;
}

bool Board::construct_candidates(const QVector<int>& queens, int row, int N, QVector<int>& candidates)
{
    for(int i=0; i<N; ++i)
    {
        if(is_safe_square(queens,row,i))
        {
            candidates.push_back(i);
        }
    }
    return candidates.size() > 0;
}

bool Board::is_safe_square(const QVector<int>& queens, int row, int col)
{
    for(int i=0; i<queens.size(); ++i)
    {
        if(i == row || queens[i] == col)
            return false;

        if(abs(i - row) == abs(queens[i] - col))
            return false;
    }
    return true;
}

bool Board::is_solution(const QVector<int>& queens, int N)
{
    return queens.size() == N;
}

QString Board::get_solution(const QVector<int>& queens, int N)
{
    QString solution;
    char c = 'a';
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(queens[i] == j)
            {
                solution += QString("(") + (c++) + QString::number(j+1) + QString(") ");
            }
        }
    }
    solution += "\n";

    return solution;

}
