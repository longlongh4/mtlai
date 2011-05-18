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
      这个界面类负责控制主界面的显示，位于主窗口的右上角，它包含最大化，最小化，关闭之类的东西。
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
            设置指向主窗体的指针。
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
            显示一般尺寸或最大化。
          \endif
    */
    void showNormalOrMax();
private:
    /*!
          \if english
            Minimize button.
          \else
            最小化按钮。
          \endif
    */
    QPushButton *minSizePushButton;
    /*!
          \if english
            Maximize Or Normal Button.
          \else
            最大化或回复按钮。
          \endif
    */
    QPushButton *maxSizePushButton;
    /*!
          \if english
            Close Button.
          \else
            关闭按钮
          \endif
    */
    QPushButton *closePushButton;
    /*!
          \if english
            The pointer pointed to the MainWindow.
          \else
            指向主窗体的指针。
          \endif
    */
    MtMainWindow *mainWindowPointer;

};

#endif // MTCONTROLWIDGET_H
