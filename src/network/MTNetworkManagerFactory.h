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

#ifndef MTNETWORKMANAGERFACTORY_H
#define MTNETWORKMANAGERFACTORY_H
#include "mtnetworkmanager.h"

//…Ë÷√qml”√µƒnetworkManagerFactory
class MTNetworkManagerFactory:public QDeclarativeNetworkAccessManagerFactory
{
public:
    QNetworkAccessManager *create(QObject * parent)
    {
        return new MTNetworkManager(parent);
    }
};
#endif // MTNETWORKMANAGERFACTORY_H
