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

#include "mtheaderwidget.h"
#include <QLinearGradient>
#include <QPalette>
#include <QSpacerItem>
MtHeaderWidget::MtHeaderWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedHeight(25);
    setAutoFillBackground(true);
    QLinearGradient linerGradient;
    linerGradient.setColorAt(0,QColor("#7b7b7b"));
    linerGradient.setColorAt(0.4,QColor("#707070"));
    linerGradient.setColorAt(0.6,QColor("#505050"));
    linerGradient.setColorAt(1,QColor("#787878"));
    QPalette p(this->palette());
    p.setBrush(QPalette::Window,QBrush(linerGradient));
    this->setPalette(p);

    controlWidget=new MtControlWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(this);
    QSpacerItem *horizontalSpacer=new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addSpacerItem(horizontalSpacer);
    layout->addWidget(controlWidget);
    layout->setMargin(0);
    setLayout(layout);
}

void MtHeaderWidget::setMainWindowPointer(MtMainWindow *pointer)
{
    controlWidget->setMainWindowPointer(pointer);
}

MtControlWidget *MtHeaderWidget::getControlWidget() const
{
    return controlWidget;
}

MtHeaderWidget::~MtHeaderWidget()
{

}
