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

#ifndef MTPLUGININTERFACE_H
#define MTPLUGININTERFACE_H
#include <QWidget>
#include <QtPlugin>
//²å¼þ½Ó¿Ú
struct MtPluginInfo
{
    QString title;
    QString name;
    QString type;
    QString author;
    QString icon;
    QString contact;
};

class MtPluginInterface
{
public:
    virtual ~MtPluginInterface() {}
    virtual QWidget* getPluginWidget(QWidget *parent=0) =0;
    virtual MtPluginInfo getPluginInfo() const=0;
    virtual void deletePluginWidget() =0;
};

Q_DECLARE_INTERFACE(MtPluginInterface,"com.mtlai.interface/1.0");
#endif // MTPLUGININTERFACE_H
