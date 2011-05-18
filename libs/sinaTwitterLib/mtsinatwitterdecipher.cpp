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

#include "mtsinatwitterdecipher.h"
#include <QtXml/QXmlStreamReader>
#include <QDateTime>
#include <QLocale>
#include <QDebug>
MtSinaTwitterDecipher* MtSinaTwitterDecipher::m_instance=NULL;

MtSinaTwitterDecipher::MtSinaTwitterDecipher(QObject *parent) :
    QObject(parent)
{
}

MtSinaTwitterDecipher* MtSinaTwitterDecipher::instance()
{
    if(!m_instance)
    {
        m_instance=new MtSinaTwitterDecipher();
    }
    return m_instance;
}

STATETYPES::Status* MtSinaTwitterDecipher::getOneStatus(QXmlStreamReader &xmlReader)
{
    STATETYPES::Status* newStatus=new STATETYPES::Status();
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="created_at")
            {
                QLocale lo(QLocale::C);
                QDateTime dateTime = lo.toDateTime(xmlReader.readElementText(), "ddd MMM dd HH:mm:ss +0800 yyyy");
                newStatus->createdAt=dateTime;
            }
            else if(xmlReader.name()=="id")
            {
                newStatus->id=xmlReader.readElementText().toULongLong();
            }
            else if(xmlReader.name()=="text")
            {
                newStatus->text=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="source")
            {
                xmlReader.readNext();
                while(!xmlReader.isStartElement())
                {
                    xmlReader.readNext();
                }
                newStatus->source.url=xmlReader.attributes().value("","href").toString();
                newStatus->source.name=xmlReader.readElementText();

            }
            else if(xmlReader.name()=="favorited")
            {
                newStatus->favorited=xmlReader.readElementText()=="false"?false:true;
            }
            else if(xmlReader.name()=="truncated")
            {
                newStatus->truncated=xmlReader.readElementText()=="false"?false:true;
            }
            else if(xmlReader.name()=="in_reply_to_status_id")
            {
                newStatus->in_reply_to_status_id=xmlReader.readElementText().toULongLong();
            }
            else if(xmlReader.name()=="in_reply_to_user_id")
            {
                newStatus->in_reply_to_user_id=xmlReader.readElementText().toULongLong();
            }
            else if(xmlReader.name()=="in_reply_to_screen_name")
            {
                newStatus->in_reply_to_screen_name=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="user")
            {
                newStatus->user=getOneUser(xmlReader);
            }

        }
        else if(xmlReader.isEndElement())
        {
            if(xmlReader.name()=="status")
            {
                return newStatus;
            }
        }
    }
}
STATETYPES::User* MtSinaTwitterDecipher::getOneUser(QXmlStreamReader &xmlReader)
{
    STATETYPES::User* newUser=new STATETYPES::User();
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name()=="id")
            {
                newUser->id=xmlReader.readElementText().toULongLong();
            }
            else if(xmlReader.name()=="screen_name")
            {
                newUser->screen_name=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="name")
            {
                newUser->name=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="province")
            {
                newUser->province=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="city")
            {
                newUser->city=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="location")
            {
                newUser->location=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="description")
            {
                newUser->description=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="url")
            {
                newUser->url=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="profile_image_url")
            {
                newUser->profile_image_url=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="domain")
            {
                newUser->domain=xmlReader.readElementText();
            }
            else if(xmlReader.name()=="gender")
            {
                QString tmp=xmlReader.readElementText();
                if(tmp=="m")
                {
                    newUser->gender=STATETYPES::Male;
                }
                else if(tmp=="f")
                {
                    newUser->gender=STATETYPES::Female;
                }
                else
                {
                    newUser->gender=STATETYPES::Unknown;
                }
            }
            else if(xmlReader.name()=="followers_count")
            {
                newUser->followers_count=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="friends_count")
            {
                newUser->friends_count=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="statuses_count")
            {
                newUser->friends_count=xmlReader.readElementText().toULongLong();
            }
            else if(xmlReader.name()=="favourites_count")
            {
                newUser->favourites_count=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="created_at")
            {
                QLocale lo(QLocale::C);
                QDateTime dateTime = lo.toDateTime(xmlReader.readElementText(), "ddd MMM dd HH:mm:ss +0800 yyyy");
                newUser->created_at=dateTime;
            }
            else if(xmlReader.name()=="following")
            {
                newUser->following=xmlReader.readElementText()=="false"?false:true;
            }
            else if(xmlReader.name()=="verified")
            {
                newUser->verified=xmlReader.readElementText()=="false"?false:true;
            }
        }
        else if(xmlReader.isEndElement())
        {
            if(xmlReader.name()=="user")
            {
                return newUser;
            }
        }
    }
}

QList<STATETYPES::Status*> MtSinaTwitterDecipher::getStatus(const QByteArray &xml)
{
    QList<STATETYPES::Status*> statusList;
    QXmlStreamReader xmlReader(xml);
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name() == "statuses")
            {
                while(!xmlReader.atEnd())
                {
                    xmlReader.readNext();
                    if(xmlReader.isStartElement())
                    {
                        if(xmlReader.name()=="status")
                        {
                            statusList.append(getOneStatus(xmlReader));
                        }
                    }
                    else if(xmlReader.isEndElement())
                    {
                        if(xmlReader.name()=="statuses")
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    if(xmlReader.hasError())
    {
        qDebug()<<"error in getStatus when parseing xml";
    }
    return statusList;
}
QList<STATETYPES::User*> MtSinaTwitterDecipher::getUser(const QByteArray &xml)
{}
QList<STATETYPES::Comment*> MtSinaTwitterDecipher::getComment(const QByteArray &xml)
{}
QList<STATETYPES::DirectMessage*> MtSinaTwitterDecipher::getDirectMessage(const QByteArray &xml)
{}
