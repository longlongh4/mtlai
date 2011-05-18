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

#ifndef STATETYPES_H
#define STATETYPES_H
#include <QDateTime>
#include <QString>

namespace STATETYPES
{
    enum SexType
    {
        Male,
        Female,
        Unknown
    };
    struct Source
    {
        QString url;
        QString name;
    };
    struct User
    {
        quint64 id;// �û�UID
        QString screen_name;// ΢���ǳ�
        QString name;// ������ʾ���ƣ���Bill Gates(�������ݲ�֧��)
        int province;// ʡ�ݱ��루�ο�ʡ�ݱ����
        int city;// ���б��루�ο����б����
        QString location;//��ַ
        QString description;// ��������
        QString url;// �û����͵�ַ
        QString profile_image_url;// �Զ���ͼ��
        QString domain;// �û����Ի�URL
        SexType gender;// �Ա�,m--�У�f--Ů,n--δ֪
        int followers_count;// ��˿��
        int friends_count;// ��ע��
        quint64 statuses_count;// ΢����
        int favourites_count;// �ղ���
        QDateTime created_at;// ����ʱ��
        bool following;// �Ƿ��ѹ�ע(�������ݲ�֧��)
        bool verified;// ��V��ʾ���Ƿ�΢����֤�û�
    };
    struct Status
    {
        Status(){user=NULL;}
        QDateTime createdAt;//΢������ʱ��
        quint64 id; //΢��ID
        QString text;//΢����Ϣ����
        Source source;// ΢����Դ
        bool favorited;// �Ƿ����ղ�(���ڿ����У��ݲ�֧��)
        bool truncated;// �Ƿ񱻽ض�
        quint64 in_reply_to_status_id;// �ظ�ID
        quint64 in_reply_to_user_id;// �ظ���UID
        QString in_reply_to_screen_name;// �ظ����ǳ�
        QString thumbnail_pic; //����ͼ
        QString bmiddle_pic;//����ͼƬ
        QString original_pic;//ԭʼͼƬ
        User* user; //������Ϣ
        struct Status *retweeted_status; //ת���Ĳ��ģ�����Ϊstatus���������ת������û�д��ֶ�
    };

    struct Comment
    {
        Comment(){user=NULL;status=NULL;reply_comment=NULL;}
        quint64 id;// ����ID
        QString text;// ��������
        QString source;// ������Դ
        bool favorited;// �Ƿ��ղ�
        bool truncated;// �Ƿ񱻽ض�
        QDateTime created_at;// ����ʱ��
        User* user;// ��������Ϣ,�ṹ�ο�user
        Status* status;// ���۵�΢��,�ṹ�ο�status
        struct Comment *reply_comment;// ������Դ�����ݽṹ��commentһ��
    };
    struct DirectMessage
    {
        DirectMessage(){sender=NULL;recipient=NULL;}
        quint64 id;// ˽��ID
        QString text;// ˽������
        quint64 sender_id;//������UID
        quint64 recipient_id;// ������UID
        QDateTime created_at;// ����ʱ��
        QString sender_screen_name;// �������ǳ�
        QString recipient_screen_name;//�������ǳ�
        User* sender;// ��������Ϣ���ο�user˵��
        User* recipient;// ��������Ϣ���ο�user˵��
    };
    enum RequestType
    {
        STATUSES_PUBLIC_TIMELINE,// ��ȡ���µĹ���΢����Ϣ
        STATUSES_FRIENDS_TIMELINE,// ��ȡ��ǰ��¼�û���������ע�û�������΢����Ϣ (����: STATUSES/HOME_TIMELINE)
        STATUSES_USER_TIMELINE,// ��ȡ��ǰ��¼�û�������΢����Ϣ�б�
        STATUSES_MENTIONS,// ��ȡ@��ǰ�û���΢���б�
        STATUSES_COMMENTS_TIMELINE,// ��ȡ��ǰ�û����ͼ��յ��������б�
        STATUSES_COMMENTS_BY_ME,// ��ȡ��ǰ�û�����������
        STATUSES_COMMENTS_TO_ME,// ��ȡ��ǰ�û��յ�������
        STATUSES_COMMENTS,// ����΢����ϢID����ĳ��΢����Ϣ�������б�
        STATUSES_COUNTS,// ������ȡһ��΢������������ת����
        STATUSES_REPOST_TIMELINE,// ����һ��ԭ��΢��������N��ת��΢����Ϣ NEW!
        STATUSES_REPOST_BY_ME,// �����û�ת��������N��΢����Ϣ NEW!
        STATUSES_UNREAD,// ��ȡ��ǰ�û�δ����Ϣ��
        STATUSES_RESET_COUNT,// δ����Ϣ������ӿ�
        EMOTIONS,// ����ӿڣ���ȡ�����б�
          //΢�����ʽӿ�
        STATUSES_SHOW,// ����ID��ȡ����΢����Ϣ����
        USER_STATUSES_ID,// ����΢��ID���û�ID��ת������΢��ҳ��
        STATUSES_UPDATE,// ����һ��΢����ϢUPDATED!
        STATUSES_UPLOAD,// �ϴ�ͼƬ������һ��΢����Ϣ
        STATUSES_DESTROY,// ɾ��һ��΢����Ϣ
        STATUSES_REPOST,// ת��һ��΢����ϢUPDATED!
        STATUSES_COMMENT,// ��һ��΢����Ϣ��������
        STATUSES_COMMENT_DESTROY_ID,// ɾ����ǰ�û���΢��������Ϣ
        STATUSES_COMMENT_DESTROY_BATCH,// ����ɾ����ǰ�û���΢��������Ϣ
        STATUSES_REPLY,// �ظ�΢��������Ϣ
          //�û��ӿ�
        USERS_SHOW,// �����û�ID��ȡ�û����ϣ���Ȩ�û���
        STATUSES_FRIENDS,// ��ȡ�û���ע�б�ÿ����ע�û�����һ��΢��
        STATUSES_FOLLOWERS,// ��ȡ�û���˿�б���ÿ����˿�û�����һ��΢��
        USERS_HOT,// ��ȡϵͳ�Ƽ��û�
        USER_FRIENDS_UPDATE_REMARK,//���µ�ǰ��¼�û�����ע��ĳ�����ѵı�ע��ϢNEW!
        USERS_SUGGESTIONS,// ���ص�ǰ�û����ܸ���Ȥ���û� BETA!
          //˽�Žӿ�
        DIRECT_MESSAGES,// ��ȡ��ǰ�û�����˽���б�
        DIRECT_MESSAGES_SENT,// ��ȡ��ǰ�û����͵�����˽���б�
        DIRECT_MESSAGES_NEW,// ����һ��˽��
        DIRECT_MESSAGES_DESTROY_ID,// ɾ��һ��˽��
        DIRECT_MESSAGES_DESTROY_BATCH,// ����ɾ��˽��
          //��ע�ӿ�
        FRIENDSHIPS_CREATE,// ��עĳ�û�
        FRIENDSHIPS_DESTROY,// ȡ����ע
        FRIENDSHIPS_EXISTS,// �Ƿ��עĳ�û�(�Ƽ�ʹ��FRIENDSHIPS/SHOW)
        FRIENDSHIPS_SHOW,// ��ȡ�����û���ϵ����ϸ���
          //����ӿ�BETA!
        TRENDS,// ��ȡĳ�˵Ļ���
        TRENDS_STATUSES,// ��ȡĳһ�����µ�΢��
        TRENDS_FOLLOW,// ��עĳһ������
        TRENDS_DESTROY,// ȡ����ע��ĳһ������
        TRENDS_HOURLY,// ��Сʱ�������Ż���
        TRENDS_DAILY,// �����ڷ������Ż��⡣����ĳһ���ڵĻ���
        TRENDS_WEEKLY,// ���ܷ������Ż��⡣����ĳһ����֮ǰĳһ�ܵĻ���
          //SOCIAL GRAPH�ӿ�
        FRIENDS_IDS,// ��ȡ�û���ע����UID�б�
        FOLLOWERS_IDS,// ��ȡ�û���˿����UID�б�
          //��˽���ýӿ�[NEW]
        ACCOUNT_UPDATE_PRIVACY,// ������˽��Ϣ
        ACCOUNT_GET_PRIVACY,// ��ȡ��˽��Ϣ
          //�������ӿ� [NEW]
        BLOCKS_CREATE,// ��ĳ�û����������
        BLOCKS_DESTROY,// ��ĳ�û��Ƴ�������
        BLOCKS_EXISTS,// ���ĳ�û��Ƿ��Ǻ������û�
        BLOCKS_BLOCKING,// �г��������û�(����û���ϸ��Ϣ)
        BLOCKS_BLOCKING_IDS,// �г���ҳ�������û���ֻ���ID��
          //�û���ǩ�ӿ�[NEW]
        TAGS,// ����ָ���û��ı�ǩ�б�
        TAGS_CREATE,// ����û���ǩ
        TAGS_SUGGESTIONS,// �����û�����Ȥ�ı�ǩ
        TAGS_DESTROY,// ɾ����ǩ
        TAGS_DESTROY_BATCH,// ����ɾ����ǩ
          //�˺Žӿ�
        ACCOUNT_VERIFY_CREDENTIALS,// ��֤��ǰ�û�����Ƿ�Ϸ�
        ACCOUNT_RATE_LIMIT_STATUS,// ��ȡ��ǰ�û�API����Ƶ������
        ACCOUNT_END_SESSION,// ��ǰ�û��˳���¼
        ACCOUNT_UPDATE_PROFILE_IMAGE,// ����ͷ��
        ACCOUNT_UPDATE_PROFILE,// ��������
          //�ղؽӿ�
        FAVORITES,// ��ȡ��ǰ�û����ղ��б�
        FAVORITES_CREATE,// ����ղ�
        FAVORITES_DESTROY,// ɾ����ǰ�û��ղص�΢����Ϣ
        FAVORITES_DESTROY_BATCH,// ����ɾ���ղص�΢����Ϣ
          //��¼/OAUTH�ӿ�
        OAUTH,// OAUTH��Ȩ��ʽ����
        OAUTH_REQUEST_TOKEN,// ��ȡδ��Ȩ��REQUEST TOKEN
        OAUTH_AUTHORIZE,// �����û���ȨTOKEN
        OAUTH_ACCESS_TOKEN,// ��ȡ��Ȩ����ACCESS TOKEN
    };
    class Response
    {
            public:
                    Response() {}
                    virtual ~Response() {}
                    RequestType reqType;
    };
    class PublicTimeline:public Response
    {
    public:
            PublicTimeline() {}
            ~PublicTimeline() {}
            QList<Status*> list;
    };
};
#endif // STATETYPES_H
