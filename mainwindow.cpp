#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <qdebug.h>

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

void MainWindow::openGeorge() {

    QStringList fileNames;

    fDialog = new  QFileDialog(this,"Open a file...","/home");
    if (fDialog->exec() )
        fileNames = fDialog->selectedFiles();


    if (! fileNames.empty() ) {
        QString csv = fileNames[0];

        QFile inFile(csv);

        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray data = inFile.readAll();
        inFile.close();

        QJsonParseError errorPtr;
        QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
        if (doc.isNull()) {
            qDebug() << "Parse failed";
        }
        QJsonObject rootObj = doc.object();
        QVector<QPointF> listPoints;
        QJsonArray ptsArray = rootObj.value("booking").toArray();
        qDebug() << "There are " << ptsArray.size() << "sets of points in the json file";
        foreach(const QJsonValue & val, ptsArray){
            double x=val.toObject().value("x").toDouble();
            double y=val.toObject().value("y").toDouble();
            listPoints.append(QPointF(x,y));
        }

        qDebug() << "Finished parsing, heres the data";
        for(auto pt: listPoints) {
            qDebug() << pt.x() << "," << pt.y();
        }



    }
}

void MainWindow::openRaika() {

    QStringList fileNames;

    fDialog = new  QFileDialog(this,"Open a file...");
    if (fDialog->exec() )
        fileNames = fDialog->selectedFiles();

    if (! fileNames.empty() ) {
        QString csv = fileNames[0];
    }
}


// private Methods
void MainWindow::init() {


}
