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

#ifndef MTSINATWITTERDECIPHER_H
#define MTSINATWITTERDECIPHER_H

#include <QList>
#include <QObject>
#include <QByteArray>
#include <QXmlStreamReader>
#include "StateTypes.h"

class MtSinaTwitterDecipher : public QObject
{
    Q_OBJECT
public:
    static MtSinaTwitterDecipher *instance();
    QList<STATETYPES::Status*> getStatus(const QByteArray &xml);
    QList<STATETYPES::User*> getUser(const QByteArray &xml);
    QList<STATETYPES::Comment*> getComment(const QByteArray &xml);
    QList<STATETYPES::DirectMessage*> getDirectMessage(const QByteArray &xml);

signals:

public slots:
private:
    //读取一个Status
    STATETYPES::Status* getOneStatus(QXmlStreamReader &xmlReader);
    //读取一个user
    STATETYPES::User* getOneUser(QXmlStreamReader &xmlReader);

    MtSinaTwitterDecipher(QObject *parent = 0);
    static MtSinaTwitterDecipher *m_instance;
};

#endif // MTSINATWITTERDECIPHER_H
