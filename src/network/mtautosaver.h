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

#ifndef MTAUTOSAVER_H
#define MTAUTOSAVER_H
#include <QObject>
#include <QBasicTimer>
#include <QTime>

#define AUTOSAVE  1000 * 3  // seconds
#define MAXWAIT      1000 * 15 // seconds

//设置自动保存机制，每当改变发生时，每隔AUTOSAVE尝试进行保存


class MTAutoSaver : public QObject {

Q_OBJECT

public:
    MTAutoSaver(QObject *parent);
    ~MTAutoSaver();
    //进行保存，并停止计时
    void saveIfNeccessary();
signals:
        void toSave();
public slots:
        //发生改变，开始计时
    void changeOccurred();

protected:
    //m_timer计时到时
    void timerEvent(QTimerEvent *event);

private:
    QBasicTimer m_timer;
    QTime m_firstChange;
};
#endif // MTAUTOSAVER_H
