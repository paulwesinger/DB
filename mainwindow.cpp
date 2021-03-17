#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialog() {

    qDebug("Operation timed out or an error occurred for port");

    QStringList fileNames;

    fDialog = new  QFileDialog(this,"Open a file...");
    if (fDialog->exec() )
        fileNames = fDialog->selectedFiles();
}

// private Methods
void MainWindow::init() {

    //connect(ui->loadButton,&QPushButton::click,this,&MainWindow::openialog);
}
