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

#ifndef MTBROWSER_H
#define MTBROWSER_H

#include <QWidget>
#include <QVBoxLayout>
#include "mtbrowsertabbar.h"
#include "mtwebview.h"

class MtBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit MtBrowser(QWidget *parent = 0);
signals:

public slots:
private:
    MtBrowserTabBar *mtBrowserTabBar;
    MtWebView *mtWebView;
};

#endif // MTBROWSER_H
