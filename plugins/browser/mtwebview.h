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

#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QtWebKit/QWebView>
#include <QUrl>
class QAuthenticator;
class QMouseEvent;
class QNetworkProxy;
class QNetworkReply;
class QSslError;

class MtWebPage : public QWebPage {
    Q_OBJECT

signals:
    void loadingUrl(const QUrl &url);

public:
    MtWebPage(QObject *parent = 0);
protected:
    QWebPage *createWindow(QWebPage::WebWindowType type);
private slots:
    void handleUnsupportedContent(QNetworkReply *reply);

private:
    friend class MtWebView;

};

class MtWebView : public QWebView {
    Q_OBJECT

public:
    MtWebView(QWidget *parent = 0);
    MtWebPage *webPage() const { return m_page; }
    void loadUrl(const QUrl &url);
    QString lastStatusBarText() const;
    inline int progress() const { return m_progress; }

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void setProgress(int progress);
    void loadFinished();
    void downloadRequested(const QNetworkRequest &request);
    void openLinkInNewTab();
    void setStatusBarText(const QString &string);
private:
    int m_progress;
    MtWebPage *m_page;
    QString m_statusBarText;

};

#endif

