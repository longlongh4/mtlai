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

#ifndef MTHEADERWIDGET_H
#define MTHEADERWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "mtcontrolwidget.h"

/*!
  \if english
      This is a header Widget.It in on the top of the MainWindow.Which contains the multimedia widget and the control widget.
  \else
      ���𶥲�widget�Ļ���,������ý��widget�Ϳ���widget
  \endif
*/
class MtHeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MtHeaderWidget(QWidget *parent = 0);
    ~MtHeaderWidget();
    /*!
          \if english
            Set the pointer which is pointed to the MainWidow.
          \else
            ����ָ���������ָ�롣
          \endif
    */
    void setMainWindowPointer(MtMainWindow *pointer);
    /*!
          \if english
            Get the pointer of the control widget.
          \else
            ���ControlWidget��ָ��
          \endif
    */
    MtControlWidget *getControlWidget() const;
private:
    /*!
          \if english
            pointer of the control widget.
          \else
            Control Widget��ָ�롣
          \endif
    */
    MtControlWidget *controlWidget;
};

#endif // MTHEADERWIDGET_H
