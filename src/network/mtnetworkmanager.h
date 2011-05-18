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

#ifndef MTNETWORKMANAGER_H
#define MTNETWORKMANAGER_H
#include <QtDeclarative/QDeclarativeNetworkAccessManagerFactory>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkDiskCache>
#include <QDir>
#include <QDesktopServices>
#include "common/mtglobal.h"

class MTNetworkManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    enum CacheType
    {
        NeedCookieJar,
        NoCookieJar
    };

    MTNetworkManager(QObject *parent = 0,CacheType cacheType = NeedCookieJar)
            :QNetworkAccessManager(parent)
    {
        QNetworkDiskCache   *diskCache = new QNetworkDiskCache(this);
        diskCache->setCacheDirectory(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));
        this->setCache(diskCache);

        if (cacheType == NeedCookieJar){
            this->setCookieJar(MTGLOBAL::globalCookieJar);
            MTGLOBAL::globalCookieJar->setParent(0);
        }
    }
protected:
    QNetworkReply *createRequest( Operation op, const QNetworkRequest & req, QIODevice * outgoingData = 0)
    {
        QNetworkRequest request = req;
        request.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute,true);
        request.setAttribute(QNetworkRequest::CacheLoadControlAttribute,QNetworkRequest::PreferCache);

        return QNetworkAccessManager::createRequest(op,request,outgoingData);
    }
};

#endif // MTNETWORKMANAGER_H
