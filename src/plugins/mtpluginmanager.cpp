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

#include "mtpluginmanager.h"
#include <QPluginLoader>
#include <QVariant>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>

MtPluginManager::MtPluginManager(QObject *parent) :
        QObject(parent)
{

}
MtPluginInterface * MtPluginManager::loadPlugin(QString name)
{
    QDir pluginsDir(qApp->applicationDirPath());
    if(pluginsDir.cd("plugins"))
    {
        MtPluginInterface  *interface=NULL;
        foreach(QString fileName,pluginsDir.entryList(QDir::Files)){
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
            QObject* plugin = pluginLoader.instance();
            if(plugin){
                interface = qobject_cast<MtPluginInterface *>(plugin);
                if(interface){
                    if(interface->getPluginInfo().name==name)
                    return interface;
                }
                else{
                    qDebug()<<"plugin not load.\n";
                    return NULL;
                }
            }
            else
            {
                qDebug()<<"something wrong with plugin system";
                return NULL;
            }
        }
    }
    else
    {
        qDebug()<<"can not open the plugin folder";
        return NULL;
    }
}

