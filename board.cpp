#include "board.h"
#include <iostream>
#include <cmath>
#include <QVector>

Board::Board()
{
    N = 0;
}

void Board::n_queens(int n)
{
    QVector<int> queens = QVector<int>();
    backtrack(queens,0,n);
}

void Board::backtrack(QVector<int>& queens, int current_row, int N)
{
    if(is_solution(queens, N))
    {
        print_solution(queens,N);
    }
    else
    {
        QVector<int> candidates = QVector<int>();
        if(construct_candidates(queens,current_row,N,candidates))
        {
            for(int i=0; i < candidates.size(); ++i)
            {
                queens.push_back(candidates[i]);
                backtrack(queens,current_row + 1,N);
                queens.pop_back();
            }
        }
    }
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

void Board::print_solution(const QVector<int>& queens, int N)
{
    static int k = 0;
    int arr_num[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    char arr_alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::cout<<++k<<". ";
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(queens[i] == j)
            {
                std::cout<<"("<<arr_alph[j]<<arr_num[i]<<") ";
            }
        }
    }
    std::cout<<"\n";

}
