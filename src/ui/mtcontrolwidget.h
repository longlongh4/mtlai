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

#ifndef MTCONTROLWIDGET_H
#define MTCONTROLWIDGET_H

#include <QWidget>
#include <QAction>
#include <QPushButton>
#include <QHBoxLayout>
class MtMainWindow;

/*!
  \if english
      This is a widget to control the display of the mainwindow .It is placed in the top-right corner,it contains showMinimized ,showMaximized ,close and something like that.
  \else
      ��������ฺ��������������ʾ��λ�������ڵ����Ͻǣ���������󻯣���С�����ر�֮��Ķ�����
  \endif
*/

class MtControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MtControlWidget(QWidget *parent = 0);
    /*!
          \if english
            Set the pointer which is pointed to the MainWidow.
          \else
            ����ָ���������ָ�롣
          \endif
    */
    void setMainWindowPointer(MtMainWindow *pointer);
    ~MtControlWidget();
signals:

public slots:
    /*!
          \if english
            To show normal size or maximum size.
          \else
            ��ʾһ��ߴ����󻯡�
          \endif
    */
    void showNormalOrMax();
private:
    /*!
          \if english
            Minimize button.
          \else
            ��С����ť��
          \endif
    */
    QPushButton *minSizePushButton;
    /*!
          \if english
            Maximize Or Normal Button.
          \else
            ��󻯻�ظ���ť��
          \endif
    */
    QPushButton *maxSizePushButton;
    /*!
          \if english
            Close Button.
          \else
            �رհ�ť
          \endif
    */
    QPushButton *closePushButton;
    /*!
          \if english
            The pointer pointed to the MainWindow.
          \else
            ָ���������ָ�롣
          \endif
    */
    MtMainWindow *mainWindowPointer;

};

#endif // MTCONTROLWIDGET_H
