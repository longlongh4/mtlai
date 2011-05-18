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

#ifndef MTBROWSERTABBAR_H
#define MTBROWSERTABBAR_H

#include <QPushButton>
#include <QUrl>
#include <QWidget>
#include "mtwebview.h"
#include <QLineEdit>
#include <QWebHistory>
#include <QHBoxLayout>

class MtBrowserTabBar : public QWidget
{
    Q_OBJECT
public:
    MtBrowserTabBar(QWidget *parent = 0,MtWebView *newWebView=NULL);
public slots:
    void loadUrlAddress();//����lineEdit����س�ʱ���뵱ǰ��ַ���ĵ�ַ
    void displayUrl(const QUrl newUrl);//���Ե�ǰ����ҳ�ĵ�ַ���������Ƿ����ʹ��ǰ���ͺ���
    void webLoadStarted();//��ʼ����ҳ��
    void webLoadFinished(bool);//ҳ���������
signals:
    void loadUrl(QString newUrl);   //�ڵ�ǰҳ������Url
private:
    QPushButton *backPushButton;
    QPushButton *forwardPushButton;
    QPushButton *reloadPushButton;
    QPushButton *stopPushButton;
    QLineEdit *urlAddress;
    MtWebView *webView;
};

#endif // MTBROWSERTABBAR_H

