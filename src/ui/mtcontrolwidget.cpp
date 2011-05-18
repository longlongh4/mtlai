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

#include "mtcontrolwidget.h"
#include <QIcon>
#include <QCoreApplication>
#include "ui/mtmainwindow.h"

MtControlWidget::MtControlWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedHeight(25);
    minSizePushButton=new QPushButton(tr("minimize"),this);
    maxSizePushButton=new QPushButton(this);
    closePushButton=new QPushButton(tr("close"),this);
    minSizePushButton->setFixedHeight(23);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(minSizePushButton);
    layout->addWidget(maxSizePushButton);
    layout->addWidget(closePushButton);
    setLayout(layout);
}

void MtControlWidget::setMainWindowPointer(MtMainWindow *pointer)
{
    mainWindowPointer=pointer;
    if(mainWindowPointer->isMaximized())
    {
        maxSizePushButton->setText(tr("normal"));
    }
    else
    {
        maxSizePushButton->setText(tr("maximiz"));
    }
    connect(minSizePushButton,SIGNAL(clicked()),mainWindowPointer,SLOT(showMinimized()));
    connect(maxSizePushButton,SIGNAL(clicked()),this,SLOT(showNormalOrMax()));
    connect(closePushButton,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void MtControlWidget::showNormalOrMax()
{
    if(mainWindowPointer->isMaximized())
    {
        maxSizePushButton->setText(tr("maximiz"));
        mainWindowPointer->showNormal();
    }
    else
    {
        maxSizePushButton->setText(tr("normal"));
        mainWindowPointer->showMaximized();
    }
}

MtControlWidget::~MtControlWidget()
{

}
