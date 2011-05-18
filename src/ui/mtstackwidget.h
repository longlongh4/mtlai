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

#ifndef MTSTACKWIDGET_H
#define MTSTACKWIDGET_H

#include <QStackedWidget>
#include <QWebView>
#include <QQueue>
#include "plugins/mtpluginmanager.h"
#include "plugins/mtplugininterface.h"
struct PluginNode
{
    MtPluginInterface *pluginInstance;
};

/*!
  \if english
      This is a container for the plugins to show.
  \else
      作为主显示区的容器。
  \endif
*/
class MtStackWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit MtStackWidget(QWidget *parent = 0);
    void setMaxNumberToRun(int max);
    int getMaxNumberToRun();
public slots:
    /*!
      \if english
          Load a new plugin and show it.
      \else
          加载新的插件并显示。通过查找map找到相应的索引页并将其打开.
      \endif
    */
    void loadNewApp(QString newAppName,QString newType);
private:
    /*!
      \if english
          Initialize the stackedWidget.
      \else
          初始化StackedWidget。
      \endif
    */
    void initStackWidget();
    /*!
      \if english
          A queue to store the plugins which have been loaded.
      \else
          一个队列，负责保存已经加载的插件。
      \endif
    */
    QQueue<PluginNode> pluginQueue;
    /*!
      \if english
          A plugin Manager.
      \else
          一个插件管理器.
      \endif
    */
    MtPluginManager *pluginManager;
    /*!
      \if english
          The max number of plugins to be loaded.
      \else
          允许同时加载的插件的数量。
      \endif
    */
    int maxNumberToRun;
};

#endif // MTSTACKWIDGET_H
