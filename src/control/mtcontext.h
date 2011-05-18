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

#ifndef MTCONTEXT_H
#define MTCONTEXT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtDeclarative/QDeclarativeContext>
#include <QSqlTableModel>
//Mtlai×ó²à¿ØÖÆÀ¸µÄContext

class MtContext : public QObject
{
    Q_OBJECT
public:
    explicit MtContext(QObject *parent = 0);
    Q_INVOKABLE void hideControl();//Òþ²Ø¿ØÖÆÀ¸
    Q_INVOKABLE void loadNewApp(QString newAppName,QString type);
signals:
    void loadNewAppSignal(QString newAppName,QString type);
    void hideControlSignal();
public slots:

};

#endif // MTCONTEXT_H
