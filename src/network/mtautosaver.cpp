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

#include "mtautosaver.h"
#include <QtCore/QCoreApplication>
#include <QtCore/QMetaObject>
#include <QtDebug>


MTAutoSaver::MTAutoSaver(QObject *parent) : QObject(parent)
{
    Q_ASSERT(parent);
}

MTAutoSaver::~MTAutoSaver()
{
    if (m_timer.isActive())
        qDebug() << "autosaver exit unexpected,changes will not be saved";
}

void MTAutoSaver::changeOccurred()
{
    if (m_firstChange.isNull())
        m_firstChange.start();

    if (m_firstChange.elapsed() > MAXWAIT) {
        saveIfNeccessary();
    } else {
        m_timer.start(AUTOSAVE, this);
    }
}

void MTAutoSaver::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer.timerId()) {
        saveIfNeccessary();
    } else {
        QObject::timerEvent(event);
    }
}

void MTAutoSaver::saveIfNeccessary()
{
    if (!m_timer.isActive())
        return;
        m_timer.stop();
    m_firstChange = QTime();

        if (!QMetaObject::invokeMethod(parent(), "save", Qt::DirectConnection)) {
        qDebug() << "error invoking slot save() on parent";

        }
}
