#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <board.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void backtrack(QVector<int>& queens, int current_row, int N);

private slots:
    void on_spinBox_board_valueChanged(int arg1);

    void on_pushButton_perm_clicked();

private:
    Ui::MainWindow *ui;
    Board board;
};

#endif // MAINWINDOW_H
