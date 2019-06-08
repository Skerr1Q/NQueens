#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_board_valueChanged(int arg1)
{
    board.N = arg1;
}

void MainWindow::on_pushButton_perm_clicked()
{
    ui->textEdit->clear();
    QVector<int> queens = QVector<int>();
    backtrack(queens,0,board.N);
}

void MainWindow::backtrack(QVector<int>& queens, int current_row, int N)
{
    if(board.is_solution(queens, N))
    {
        ui->textEdit->append(board.print_solution(queens,N));
    }
    else
    {
        QVector<int> candidates = QVector<int>();
        if(board.construct_candidates(queens,current_row,N,candidates))
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
