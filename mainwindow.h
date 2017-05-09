#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTextEdit * txt;
    bool flag;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCreate_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionFont_triggered();

    void on_actionDate_and_Time_triggered();

    void on_actionSelect_all_triggered();

    void on_actionDelete_triggered();

    void on_actionCopy_triggered();

    void on_actionBack_triggered();

    void on_actionCut_2_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
