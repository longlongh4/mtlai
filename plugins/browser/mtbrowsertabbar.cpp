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

#include "mtbrowsertabbar.h"
#include <QLinearGradient>

MtBrowserTabBar::MtBrowserTabBar(QWidget *parent, MtWebView *newWebView) :
    QWidget(parent),webView(newWebView)
{
    QHBoxLayout *hBoxLayout=new QHBoxLayout(this);
    backPushButton=new QPushButton(this);
    backPushButton->setIcon(QIcon(":Resources/back.png"));
    forwardPushButton=new QPushButton(this);
    forwardPushButton->setIcon(QIcon(":Resources/forward.png"));
    reloadPushButton=new QPushButton(this);
    reloadPushButton->setIcon(QIcon(":Resources/reload.png"));
    stopPushButton=new QPushButton(this);
    stopPushButton->setIcon(QIcon(":Resources/stop.png"));
    urlAddress=new QLineEdit(this);
    hBoxLayout->addWidget(backPushButton);
    hBoxLayout->addWidget(forwardPushButton);
    hBoxLayout->addWidget(reloadPushButton);
    hBoxLayout->addWidget(stopPushButton);
    hBoxLayout->addWidget(urlAddress);
    hBoxLayout->setContentsMargins(10,0,100,0);
    backPushButton->setEnabled(false);
    forwardPushButton->setEnabled(false);
    stopPushButton->setEnabled(false);
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    setLayout(hBoxLayout);
    setAutoFillBackground(true);
    QLinearGradient linerGradient;
    linerGradient.setColorAt(0,QColor("#7b7b7b"));
    linerGradient.setColorAt(0.4,QColor("#707070"));
    linerGradient.setColorAt(0.6,QColor("#505050"));
    linerGradient.setColorAt(1,QColor("#787878"));
    QPalette p(this->palette());
    p.setBrush(QPalette::Window,QBrush(linerGradient));
    this->setPalette(p);
    connect(urlAddress, SIGNAL(returnPressed()), this, SLOT(loadUrlAddress()));
    connect(webView,SIGNAL(urlChanged(QUrl)),this,SLOT(displayUrl(QUrl)));
    connect(backPushButton,SIGNAL(clicked()),webView,SLOT(back()));
    connect(forwardPushButton,SIGNAL(clicked()),webView,SLOT(forward()));
    connect(reloadPushButton,SIGNAL(clicked()),webView,SLOT(reload()));
    connect(stopPushButton,SIGNAL(clicked()),webView,SLOT(stop()));
    connect(webView, SIGNAL(loadStarted()), this, SLOT(webLoadStarted()));
    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(webLoadFinished(bool)));
}

void MtBrowserTabBar::loadUrlAddress()
{
    QString url = urlAddress->text();
    if (url.left(5) != "http:" && url.left(5) != "file:")
        url.prepend("http://");
    webView->loadUrl(url);
}
void MtBrowserTabBar::displayUrl(const QUrl newUrl)
{
    urlAddress->setText(newUrl.toString());
    if (webView->history()->canGoBack())
        backPushButton->setEnabled(true);
    else
        backPushButton->setEnabled(false);

    if (webView->history()->canGoForward())
        forwardPushButton->setEnabled(true);
    else
        forwardPushButton->setEnabled(false);
}

void MtBrowserTabBar::webLoadStarted()
{
     stopPushButton->setEnabled(true);
}

void MtBrowserTabBar::webLoadFinished(bool succeed)
{
    if (succeed)
        stopPushButton->setEnabled(false);
}

