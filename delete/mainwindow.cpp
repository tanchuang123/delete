#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QCoreApplication>
#include <QtDebug>
#include <QFileInfo>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(deleteExe()));
    timer->start(10000);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::deleteExe()
{
  QString file_all_path= qApp->applicationFilePath();
  QString  file=QCoreApplication::applicationDirPath();

  QString m_FilePath = file_all_path ;

     int first = m_FilePath.lastIndexOf ("/"); //从后面查找"/"位置
//     int first = m_FilePath.indexOf ("/"); //从后面查找"/"位置
      for(int i=0;i<file_all_path.size();i++)
      {


         if( file_all_path.at(i)=="/")
         {
             j++;
         }

      }

      qDebug()<<j<<"j";
      for(int i=0;i<file_all_path.size();i++)
      {
          if(file_all_path.at(i)=="/")
          {
              add++;
              if(add==(j-3+1))
              {
                  qDebug()<<add;
                   cutStr = file_all_path.mid(i);
                  qDebug()<<cutStr;
                   break;
              }
          }
      }



      qDebug()<<needStrPath<<cutStr.size();
//     QString title = m_FilePath.right (m_FilePath.length ()-first-1); //从右边截取
     needStrPath = m_FilePath.left (m_FilePath.length ()-cutStr.size()); //从左边截取
     QString deletePath=needStrPath+("/delete");
     qDebug()<<first;
     qDebug()<<file_all_path;
     qDebug()<<needStrPath;
     qDebug()<<deletePath;
     QFile file(deletePath);
     if (file.exists())
     {
         if(file.remove())
         {
             qDebug()<<QStringLiteral("销毁成功");
         }
    }
}
