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

#ifndef MTDATABASECONNECTION_H
#define MTDATABASECONNECTION_H
#include <QtSql>
#include "plugins/mtplugininterface.h"
#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
//数据库连接模块
void initPluginDatabase();

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(":memory:");
        if (!db.open()) {
            qDebug()<<"can not open exec database file!";
            return false;
        }
        initPluginDatabase();
        return true;
}

void initPluginDatabase()
{
    QSqlQuery query;
    query.exec("CREATE TABLE PLUGINTABLE (title TEXT,name TEXT,type TEXT,author TEXT,icon TEXT,contact TEXT)");
    query.prepare("INSERT INTO PLUGINTABLE (title,name,type,author,icon,contact)"
                  "VALUES (:title,:name,:type,:author,:icon,:contact)");
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
                    qDebug()<<interface->getPluginInfo().name;
                    qDebug()<<"plugin load ok\n";
                    query.bindValue(":title",interface->getPluginInfo().title);
                    query.bindValue(":name",interface->getPluginInfo().name);
                    query.bindValue(":type",interface->getPluginInfo().type);
                    query.bindValue(":author",interface->getPluginInfo().author);
                    query.bindValue(":icon",interface->getPluginInfo().icon);
                    query.bindValue(":contact",interface->getPluginInfo().contact);
                    if(!query.exec())
                    {
                        qDebug()<<query.lastError();
                    }
                }
                else{
                    qDebug()<<"plugin not load.\n";
                }
            delete plugin;
            }
            else
            {
                qDebug()<<"something wrong with plugin system";
            }
        }
    }
    else
    {
        qDebug()<<"can not open the plugin folder";
    }

}
#endif // MTDATABASECONNECTION_H
