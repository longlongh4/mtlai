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

#ifndef MTSERVERSTATE_H
#define MTSERVERSTATE_H

namespace MTSERVERSTATE
{
    enum STATE
    {
        OK = 200,
        NOT_MODIFIED = 304,
        BAD_REQUEST = 400,
        NOT_AUTHORIZED = 401,
        FORBIDDEN = 403,
        NOT_FOUND = 404,
        INTERNAL_SERVER_ERROR = 500,
        BAD_GATEWAY = 502,
        SERVICE_UNAVAILABLE = 503,
        UNKNOWN = 2723
              };
};

#endif // MTSERVERSTATE_H
