/***********************************************************************
The contents of this file are subject to the Mozilla Public License
Version 1.1 (the "License"); you may not use this file except in
compliance with the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

The Initial Developer of the Original Code is Hailong Geng.

name: Hailong Geng
email: longlongh4@gmail.com
address: Building C2, No. 2 Yikuang Street, Nangang District, Harbin, China
website:www.mtlai.com   www.mtday.com
***************************************************************************/

#ifndef MTMAINWINDOW_H
#define MTMAINWINDOW_H

#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeNetworkAccessManagerFactory>
#include <QtDeclarative/QDeclarativeEngine>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QSettings>
#include <QMouseEvent>
#include <QWidget>
#include <QPoint>
#include <QHBoxLayout>
#include <QSplitter>
#include <QMainWindow>
#include "ui/mtstackwidget.h"
#include "control/mtcontextmanager.h"
#include "ui/mtheaderwidget.h"


class MTNetworkManagerFactory;

/*!
  \if english
      The main window of Mtlai.
  \else
      Mtlai�������档
  \endif
*/
class MtMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MtMainWindow(QWidget *parent = 0);
    ~MtMainWindow();
private slots:
    void manualActive(QSystemTrayIcon::ActivationReason reason);
    void whetherShowControl();//�Ƿ���ʾ������
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent ( QMouseEvent *e);
private:
    void initUI();  //��ʼ��������
    void initProperty();    //��ʼ������
    void initSystemTray();  //��ʼ������ͼ��
    void initConnections(); //��ʼ������

    QSystemTrayIcon     *systemIcon;//����ͼ��
    QAction     *actionShow;//��ʾ
    QAction     *actionHide;//����
    QSplitter   *horizontalSpliter;//����ָ���
    QSplitter   *verticalSpliter;//����ָ���
    QAction     *whetherToShowControlAction;//�Ƿ���ʾ������
    QDeclarativeView    *m_declarativeViewLeft;//�������Ľ�����
    MtStackWidget *m_stackedWidget;//widget����
    MtContextManager *m_mtContextManager;//QML context������
    MtHeaderWidget *m_HeaderWidget;
    QPoint last,pos0;
    bool isDraggingWindow;
};

#endif // MTMAINWINDOW_H
