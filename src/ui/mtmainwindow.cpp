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

#include "mtmainwindow.h"
#include "network/MTNetworkManagerFactory.h"
#include "common/mtglobal.h"
#include <QApplication>
MtMainWindow::MtMainWindow(QWidget *parent)
    : QMainWindow(parent),isDraggingWindow(false)
{
    initProperty();
    initUI();
    initSystemTray();
    initConnections();
}

MtMainWindow::~MtMainWindow()
{
    QSettings settings;
    settings.beginGroup("Property");
    settings.setValue("geometry",this->saveGeometry());
    settings.endGroup();
}

void MtMainWindow::initUI()
{
    /*!
        init Header
      */
    m_HeaderWidget=new MtHeaderWidget(this);
    m_HeaderWidget->setMainWindowPointer(this);
    /*!
        init left
      */
    m_declarativeViewLeft=new QDeclarativeView(horizontalSpliter);
    m_declarativeViewLeft->engine()->setNetworkAccessManagerFactory(new MTNetworkManagerFactory());
    //connect(m_declarativeViewLeft,SIGNAL(sceneResized(QSize)),this,SLOT(resizeDockWidget(QSize)));
    m_declarativeViewLeft->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    m_declarativeViewLeft->setSource(QUrl("./qml/mtlaiControl.qml"));
    m_declarativeViewLeft->setFixedWidth(292);
    m_mtContextManager=new MtContextManager(m_declarativeViewLeft->rootContext(),this);
    /*!
        init right
      */
    m_stackedWidget=new MtStackWidget(this);
    /*!
        set Layout
      */
    verticalSpliter=new QSplitter(this);
    horizontalSpliter=new QSplitter(this);
    horizontalSpliter->addWidget(m_declarativeViewLeft);
    horizontalSpliter->addWidget(m_stackedWidget);
    horizontalSpliter->setHandleWidth(1);
    verticalSpliter->setStyleSheet("QSplitter::handle { background-color: black }");
    verticalSpliter->setOrientation(Qt::Vertical);
    verticalSpliter->setHandleWidth(1);
    verticalSpliter->addWidget(m_HeaderWidget);
    verticalSpliter->addWidget(horizontalSpliter);
    this->setCentralWidget(verticalSpliter);
    //设置属性
    //this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);
    setWindowFlags(Qt::CustomizeWindowHint);
}

void MtMainWindow::initSystemTray()
{
    QMenu *menu = new QMenu(this);
    whetherToShowControlAction=menu->addAction(tr("Hide ControlBar"),this,SLOT(whetherShowControl ()));
    menu->addSeparator();
    actionHide = menu->addAction(tr("Hide"),this,SLOT(hide()));
    actionShow = menu->addAction(tr("Show"),this,SLOT(show()));
    menu->addSeparator();
    menu->addAction(tr("Exit"),qApp,SLOT(quit()));

    systemIcon = new QSystemTrayIcon(QIcon(":/Resources/icon.ico"),this);
    connect(systemIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(manualActive(QSystemTrayIcon::ActivationReason)));
    systemIcon->setContextMenu(menu);
    systemIcon->show();
}



void MtMainWindow::manualActive(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void MtMainWindow::initProperty()
{
    QSettings settings;
    settings.beginGroup("Property");
    this->restoreGeometry(settings.value("geometry").toByteArray());
    settings.endGroup();
}

void MtMainWindow::whetherShowControl()
{
    if(m_declarativeViewLeft->isVisible())
    {
        whetherToShowControlAction->setText(tr("Show ControlBar"));
        m_declarativeViewLeft->hide();
}
    else
    {
        whetherToShowControlAction->setText(tr("Hide ControlBar"));
        m_declarativeViewLeft->show();
    }
}


void MtMainWindow::initConnections()
{
    connect(MTGLOBAL::mtContext,SIGNAL(hideControlSignal()),this,SLOT(whetherShowControl()));
    connect(MTGLOBAL::mtContext,SIGNAL(loadNewAppSignal(QString,QString)),m_stackedWidget,SLOT(loadNewApp(QString,QString)));
}

void MtMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (isDraggingWindow)
    {

        //只对标题栏范围内的鼠标事件进行处理
        QPoint newpos = e->globalPos();
        QPoint upleft = pos0 + newpos - last;
        move(upleft);
    }
}

void MtMainWindow::mousePressEvent(QMouseEvent *e)
{
    QPoint temp = e->pos();
    const int pos_min_x = m_HeaderWidget->pos().x();
    const int pos_max_x = pos_min_x + m_HeaderWidget->width();
    const int pos_min_y = m_HeaderWidget->pos().y();
    const int pos_max_y = pos_min_y + m_HeaderWidget->height();
    if ( temp.x()>pos_min_x && temp.x()<pos_max_x && temp.y()>pos_min_y && temp.y()<pos_max_y )
       {
            isDraggingWindow=true;
           //只对标题栏范围内的鼠标事件进行处理。
           last = e->globalPos();
           pos0 = e->globalPos() - e->pos();
       }
}

void MtMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    isDraggingWindow=false;
}

void MtMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    QPoint temp = e->pos();
    const int pos_min_x = m_HeaderWidget->pos().x();
    const int pos_max_x = pos_min_x + m_HeaderWidget->width();
    const int pos_min_y = m_HeaderWidget->pos().y();
    const int pos_max_y = pos_min_y + m_HeaderWidget->height();
    if ( temp.x()>pos_min_x && temp.x()<pos_max_x && temp.y()>pos_min_y && temp.y()<pos_max_y )
       {
           m_HeaderWidget->getControlWidget()->showNormalOrMax();
       }
}
