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

#ifndef TWITTERONGOOGLEMAPINTERFACE_H
#define TWITTERONGOOGLEMAPINTERFACE_H

#include <QObject>
#include "mtplugininterface.h"
#include "twitterongooglemap.h"
class TwitterOnGoogleMapInterface : public QObject,public MtPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(MtPluginInterface)
public:
    explicit TwitterOnGoogleMapInterface(QObject *parent = 0);
    QWidget* getPluginWidget(QWidget *parent);
    MtPluginInfo getPluginInfo() const;
    void deletePluginWidget();
private:
    QWidget *pluginWidget;
};

#endif // TWITTERONGOOGLEMAPINTERFACE_H
