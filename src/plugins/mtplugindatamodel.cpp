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

#include "mtplugindatamodel.h"
#include <QSqlQuery>
#include <QDebug>
const char* MtPluginDataModel::COLUMN_NAMES[] = {
        "title","name","type","author","icon","contact",
        NULL
};

const char* MtPluginDataModel::SQL_SELECT =
"SELECT title,name,type,author,icon,contact"
"  FROM PLUGINTABLE";

MtPluginDataModel::MtPluginDataModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    int idx = 0;
    QHash<int, QByteArray> roleNames;

    while( COLUMN_NAMES[idx]) {
            roleNames[Qt::UserRole + idx + 1] = COLUMN_NAMES[idx];
            idx++;
    }

    setRoleNames(roleNames);
    refresh();
}

void MtPluginDataModel::refresh()
{
    setQuery(SQL_SELECT, QSqlDatabase::database());
}

QVariant MtPluginDataModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if(role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }

    return value;
}
