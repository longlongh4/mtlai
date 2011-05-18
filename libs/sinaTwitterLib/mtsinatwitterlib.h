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

#ifndef MTSINATWITTERLIB_H
#define MTSINATWITTERLIB_H

#include "mtsinatwittercore.h"

class MtSinaTwitterLib : public MtSinaTwitterCore
{
    Q_OBJECT
public:
    explicit MtSinaTwitterLib(QObject *parent = 0);
//==================================================================
    //APIS
//=====================================================================
    /**
     *  获取最新的公共微博消息,默认是20条
     *  @param number 非必须.用来控制返回的条数,默认是20条,范围是1到200
     */
    void getPublicTimeline(int number=20);
signals:

public slots:

};

#endif // MTSINATWITTERLIB_H
