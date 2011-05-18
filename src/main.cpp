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

#include <QtGui/QApplication>
#include <QtDeclarative>
#include "ui/mtmainwindow.h"
#include "common/mtglobal.h"
#include <QTextCodec>
#include "control/mtdatabaseconnection.h"
#ifdef Q_WS_WIN
#include <windows.h>
#endif



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //保证只启动一个实例
#ifdef Q_WS_WIN
    HANDLE hMutex = CreateMutex(NULL, true, QString("['{EFEB2EF6-F8E0-AE44-BABE-1BBEF2C7FD59}']").toStdWString().c_str());
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        CloseHandle(hMutex);
        QMessageBox::information(NULL, "Info", "there is alredy one instance running ", "OK");
        a.exit(1);
        return 1;
    }
#endif

    //设置程序属性
    a.setQuitOnLastWindowClosed(false);
    a.setFont(QFont("Microsoft Yahei",8));
    a.setOrganizationDomain("mtlai.com");
    a.setApplicationName("MtLai");
    a.setApplicationVersion("0.5");

    //设置字符编码
    QTextCodec *tc=QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(tc);
    QTextCodec::setCodecForTr(tc);
    QTextCodec::setCodecForCStrings(tc);

    //链接数据库
    bool createConnectionSuccess=createConnection();
    if(!createConnectionSuccess)
    {
        return 1;
    }

    MTGLOBAL::globalCookieJar = new MTNetworkCookieJar();

    MtMainWindow w;
    w.show();

    return a.exec();
}
