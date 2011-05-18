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

#ifndef MTPLUGINDATAMODEL_H
#define MTPLUGINDATAMODEL_H

#include <QSqlQueryModel>

class MtPluginDataModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit MtPluginDataModel(QObject *parent = 0);
    void refresh();
    QVariant data(const QModelIndex &index, int role) const;
signals:

public slots:
private:
    const static char* COLUMN_NAMES[];
    const static char* SQL_SELECT;
};

#endif // MTPLUGINDATAMODEL_H
