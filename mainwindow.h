#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void cswap(QChar& a, QChar& b);
    ~MainWindow();


private slots:
    void setup();
    void flip();
    void next();
    void prev();
    void reset();
    void checkAnswer();

private:
    Ui::MainWindow *ui;
    QList<QString> study;
    QList<QString> studya;
    QList<QString> quizc;
    QList<QChar> quiza;
    QList<int> visited;
    QList<int> indexes;
};

#endif // MAINWINDOW_H
