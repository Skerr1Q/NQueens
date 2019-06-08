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

QString Board::print_solution(const QVector<int>& queens, int N)
{
    QString solution;
    int arr_num[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    char arr_alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(queens[i] == j)
            {
                solution += "(" + (QString)arr_alph[j] + (QString)arr_num[i] + ") ";
            }
        }
    }
    solution += "\n";

    return solution;

}
