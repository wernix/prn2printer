#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString prnFile;

private slots:
    void on_chooseFileButton_clicked();

    void on_printButton_clicked();

    bool fileExist(QString);

    void debug(QString);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
