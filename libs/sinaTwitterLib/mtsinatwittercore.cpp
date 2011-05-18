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

#include "mtsinatwittercore.h"
#include "common/mtglobal.h"
#include <QDebug>
#include "mtsinatwitterdecipher.h"
#include <QNetworkRequest>
QString MtSinaTwitterCore::sina_api_key = "1085591804";
QString MtSinaTwitterCore::sina_twitter_host = "http://api.t.sina.com.cn/";
QString MtSinaTwitterCore::statuses_public_timeline = "statuses/public_timeline";
MtSinaTwitterCore::MtSinaTwitterCore(QObject *parent) :
    QObject(parent)
{
    sinaTwitterNetworkManager=new MTNetworkManager(this);
    connect(sinaTwitterNetworkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(httpFinished(QNetworkReply*)));
}

void MtSinaTwitterCore::httpFinished(QNetworkReply *newReply)
{
    switch(requestMap.value(newReply))
    {
    case STATETYPES::STATUSES_PUBLIC_TIMELINE:
        STATETYPES::PublicTimeline *newOne=new STATETYPES::PublicTimeline();
        newOne->list=MtSinaTwitterDecipher::instance()->getStatus(newReply->readAll());
        emit OnResponseReceived(newOne);
        break;
    }

    newReply->deleteLater();
}

void MtSinaTwitterCore::getPublicTimeline(int number)
{
    if(number<1||number>200)
    {
        qDebug()<<"error MtSinaTwitterCore 返回最新的20条公共微博,最少返回1，最多返回200";
        return;
    }
    QString request=sina_twitter_host+statuses_public_timeline+".xml?source="+sina_api_key+"&count="+QString::number(number);
    QNetworkReply *reply=sinaTwitterNetworkManager->get(QNetworkRequest(QUrl(request)));
    requestMap.insert(reply,STATETYPES::STATUSES_PUBLIC_TIMELINE);
}
