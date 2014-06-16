#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(prnFile != ui->filePath->text())
        ui->filePath->setText(prnFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::debug(QString msg)
{
    qDebug()<<msg;
}

// Check file
bool MainWindow::fileExist(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    switch(file.exists())
    {
    case true:
        debug("(fileExist) Plik '" + filename + "' istnieje.");
        break;
    case false:
        debug("(fileExist) Plik '" + filename + "' nie istnieje.");
        break;
    }

    return file.exists();
}

void MainWindow::on_chooseFileButton_clicked()
{
    prnFile = QFileDialog::getOpenFileName(this, tr("Wybierz plik"), QApplication::applicationDirPath(), tr("plik PRN (*.prn)"));

    ui->printButton->setEnabled(fileExist(prnFile));

}

void MainWindow::on_printButton_clicked()
{
    QString printerPath = ui->printerPath->text();

    QProcess proc;
    QStringList args = QStringList()
        << "/K"
        << QString("COPY /B %1 %2" ).arg(prnFile).arg( printerPath);
    proc.start("cmd.exe", args);

    //debug(args.);
}
