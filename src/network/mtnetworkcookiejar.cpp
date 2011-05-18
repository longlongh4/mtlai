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

#include "mtnetworkcookiejar.h"



QDataStream& operator<<(QDataStream &stream,const QList<QNetworkCookie>& listCookies)
{
    stream <<quint32(listCookies.size());
    foreach(QNetworkCookie cookie,listCookies)
            stream << cookie.toRawForm();
    return stream;
}

QDataStream& operator>>(QDataStream &stream,QList<QNetworkCookie>& listCookies)
{
    listCookies.clear();
    int count;
    stream >>count;

    for (int i =0;i < count; i++){
        QByteArray byteArrary;
        stream >> byteArrary;
        QList<QNetworkCookie>  parseList= QNetworkCookie::parseCookies(byteArrary);
        if (!parseList.isEmpty()){
            foreach(QNetworkCookie cookie,parseList)
                    listCookies << cookie;
        }
        if (stream.atEnd())
                break;
    }
    return stream;
}

MTNetworkCookieJar::MTNetworkCookieJar(QObject *parent)
    :QNetworkCookieJar(parent),
    m_loaded(false),
    m_autoSaver(new MTAutoSaver(this))
{
}

MTNetworkCookieJar::~MTNetworkCookieJar()
{
    m_autoSaver->saveIfNeccessary();
}

QList<QNetworkCookie> MTNetworkCookieJar::cookiesForUrl(const QUrl &url) const
{
//    MTNetworkCookieJar *cookiesJar = const_cast<MTNetworkCookieJar *>(this);
//    if (!m_loaded)
//        cookiesJar->load();

    return QNetworkCookieJar::cookiesForUrl(url);
}

bool MTNetworkCookieJar::setCookiesFromUrl(const QList<QNetworkCookie> &cookieList, const QUrl &url)
{
    if (!m_loaded)
        load();
    if (QNetworkCookieJar::setCookiesFromUrl(cookieList,url)){
        m_autoSaver->changeOccurred();
        return true;
    }
    else
        return false;
}

void MTNetworkCookieJar::load()
{
    if (m_loaded)
        return;

    qRegisterMetaTypeStreamOperators<QList<QNetworkCookie> >("QList<QNetworkCookie>");
    QSettings cookieSettings("./Info.ini", QSettings::IniFormat);
    setAllCookies(qvariant_cast< QList<QNetworkCookie> >(cookieSettings.value(QLatin1String("cookies"))));//[Geranal]
    m_loaded = true;
}

void MTNetworkCookieJar::save()
{
    if (!m_loaded)
        return;
    QList<QNetworkCookie> networkCookies = allCookies();
    QDateTime currrentDate = QDateTime::currentDateTime();
    foreach(QNetworkCookie cookie,networkCookies){
        if (cookie.isSessionCookie() ||
            (!cookie.isSessionCookie() && cookie.expirationDate() < currrentDate))
                networkCookies.removeOne(cookie);
    }
    setAllCookies(networkCookies);
    QSettings settings("./Info.ini",QSettings::IniFormat);
    settings.setValue(QLatin1String("cookies"),qVariantFromValue< QList<QNetworkCookie> >(networkCookies));
}
