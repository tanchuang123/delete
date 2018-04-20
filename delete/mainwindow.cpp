#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QCoreApplication>
#include <QtDebug>
#include <QFileInfo>
#include <QFileDialog>
#include <QFile>

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
     qDebug()<<"deletePath:"<<deletePath;
     QFile file__( "F:/work/WORK/assets");
//    F:\work\WORK\123\ AliIM2018_taobao(9.12.03C).exe
//     QDir dir(deletePath);
//     dir.rmdir(strFileName);
//     QFile file(deletePath);
     if(file__.isReadable())
     file__.setPermissions(QFile::WriteOwner);
     QFileInfo fileinfo(file__);
     deleteDirectory(fileinfo);
     qDebug()<<file__.exists()<<"file__.exists()";
//     if (file__.exists())
//     {
//         qDebug()<<file__.remove()<<"file__.remove()";
//         if(file__.remove())
//         {
//             qDebug()<<QStringLiteral("销毁成功");
//         }
//    }
//     file__.remove();
}
void MainWindow::deleteDirectory(QFileInfo fileList)
{

    if(fileList.isDir())
    {
      int childCount =0;
      QString dir = fileList.filePath();
      QDir thisDir(dir);
      childCount = thisDir.entryInfoList().count();
      QFileInfoList newFileList = thisDir.entryInfoList();
      if(childCount>2)
      {
       for(int i=0;i<childCount;i++)
       {
         if(newFileList.at(i).fileName().operator ==(".")|newFileList.at(i).fileName().operator ==(".."))
         {
         continue;
          }
         deleteDirectory(newFileList.at(i));
       }
    }
      fileList.absoluteDir().rmpath(fileList.fileName());
    }
    else if(fileList.isFile())
    {
    fileList.absoluteDir().remove(fileList.fileName());
    }
}
