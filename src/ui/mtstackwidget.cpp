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

#include "mtstackwidget.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>

MtStackWidget::MtStackWidget(QWidget *parent) :
    QStackedWidget(parent),maxNumberToRun(3)
{
    pluginManager=new MtPluginManager(this);
    initStackWidget();
}

void MtStackWidget::initStackWidget()
{

}

void MtStackWidget::loadNewApp(QString newAppName, QString newType)
{
    for(QQueue<PluginNode>::iterator it=pluginQueue.begin();it!=pluginQueue.end();it++)
    {
        if(it->pluginInstance->getPluginInfo().name==newAppName)
        {
            this->setCurrentWidget(it->pluginInstance->getPluginWidget());
            return;
        }
    }
    if(pluginQueue.size()==maxNumberToRun)
    {
        this->removeWidget(pluginQueue.first().pluginInstance->getPluginWidget());
        pluginQueue.first().pluginInstance->deletePluginWidget();
        delete pluginQueue.first().pluginInstance;
        pluginQueue.dequeue();
    }
    PluginNode tmpNode;
    tmpNode.pluginInstance=pluginManager->loadPlugin(newAppName);
    pluginQueue.enqueue(tmpNode);
    QWidget *tmpWidget=tmpNode.pluginInstance->getPluginWidget(this);
    this->addWidget(tmpWidget);
    this->setCurrentWidget(tmpWidget);
    return;
}

void MtStackWidget::setMaxNumberToRun(int max)
{
    maxNumberToRun=max;
}

int MtStackWidget::getMaxNumberToRun()
{
    return maxNumberToRun;
}
