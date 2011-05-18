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

#ifndef MTNETWORKCOOKIEJAR_H
#define MTNETWORKCOOKIEJAR_H
#include <QtNetwork/QNetworkCookie>
#include <QtNetwork/QNetworkCookieJar>
#include <QSettings>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkDiskCache>
#include <QDir>
#include <QtNetwork/QNetworkAccessManager>

#include "mtautosaver.h"

//将cookie保存到ini文件中，并处理cookie的更新
class MTNetworkCookieJar:public QNetworkCookieJar
{
    Q_OBJECT
public:
    MTNetworkCookieJar(QObject *parent= NULL);
    ~MTNetworkCookieJar();
    QList<QNetworkCookie> cookiesForUrl(const QUrl &url) const;
    bool setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url);
    void load();//从ini文件中载入cookie
public slots:
    void save();//通过autosaver将cookie保存到ini文件中
private:
    bool        m_loaded;           //是否已经从ini文件中装载cookie
    MTAutoSaver	*m_autoSaver;       //自动保存控制器
};

#endif // MTNETWORKCOOKIEJAR_H
