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

#ifndef MTSINATWITTERCORE_H
#define MTSINATWITTERCORE_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QList>
#include <QNetworkReply>
#include "mtnetworkmanager.h"
#include "mtsinatwitterdecipher.h"

class MtSinaTwitterCore : public QObject
{
    Q_OBJECT
public:
    explicit MtSinaTwitterCore(QObject *parent = 0);
    void getPublicTimeline(int number=20);
signals:
    void OnResponseReceived(STATETYPES::Response *resp);
public slots:
    void httpFinished(QNetworkReply *newReply);
private:


    MTNetworkManager *sinaTwitterNetworkManager;
    //��¼ÿ��QNetworkReply����������
    QMap<QNetworkReply*,STATETYPES::RequestType> requestMap;
    static QString sina_api_key;//api key
    static QString sina_twitter_host;//sina΢����ַ
    //��ȡ�������ݼ�(timeline)�ӿ�
    static QString statuses_public_timeline;// ��ȡ���µĹ���΢����Ϣ
    static QString statuses_friends_timeline;// ��ȡ��ǰ��¼�û���������ע�û�������΢����Ϣ (����: statuses/home_timeline)
    static QString statuses_user_timeline;// ��ȡ��ǰ��¼�û�������΢����Ϣ�б�
    static QString statuses_mentions;// ��ȡ@��ǰ�û���΢���б�
    static QString statuses_comments_timeline;// ��ȡ��ǰ�û����ͼ��յ��������б�
    static QString statuses_comments_by_me;// ��ȡ��ǰ�û�����������
    static QString statuses_comments_to_me;// ��ȡ��ǰ�û��յ�������
    static QString statuses_comments;// ����΢����ϢID����ĳ��΢����Ϣ�������б�
    static QString statuses_counts;// ������ȡһ��΢������������ת����
    static QString statuses_repost_timeline;// ����һ��ԭ��΢��������n��ת��΢����Ϣ New!
    static QString statuses_repost_by_me;// �����û�ת��������n��΢����Ϣ New!
    static QString statuses_unread;// ��ȡ��ǰ�û�δ����Ϣ��
    static QString statuses_reset_count;// δ����Ϣ������ӿ�
    static QString emotions;// ����ӿڣ���ȡ�����б�
    //΢�����ʽӿ�
    static QString statuses_show;// ����ID��ȡ����΢����Ϣ����
    static QString user_statuses_id;// ����΢��ID���û�ID��ת������΢��ҳ��
    static QString statuses_update;// ����һ��΢����ϢUpdated!
    static QString statuses_upload;// �ϴ�ͼƬ������һ��΢����Ϣ
    static QString statuses_destroy;// ɾ��һ��΢����Ϣ
    static QString statuses_repost;// ת��һ��΢����ϢUpdated!
    static QString statuses_comment;// ��һ��΢����Ϣ��������
    static QString statuses_comment_destroy_id;// ɾ����ǰ�û���΢��������Ϣ
    static QString statuses_comment_destroy_batch;// ����ɾ����ǰ�û���΢��������Ϣ
    static QString statuses_reply;// �ظ�΢��������Ϣ
    //�û��ӿ�
    static QString users_show;// �����û�ID��ȡ�û����ϣ���Ȩ�û���
    static QString statuses_friends;// ��ȡ�û���ע�б�ÿ����ע�û�����һ��΢��
    static QString statuses_followers;// ��ȡ�û���˿�б���ÿ����˿�û�����һ��΢��
    static QString users_hot;// ��ȡϵͳ�Ƽ��û�
    static QString user_friends_update_remark;//���µ�ǰ��¼�û�����ע��ĳ�����ѵı�ע��ϢNew!
    static QString users_suggestions;// ���ص�ǰ�û����ܸ���Ȥ���û� Beta!
    //˽�Žӿ�
    static QString direct_messages;// ��ȡ��ǰ�û�����˽���б�
    static QString direct_messages_sent;// ��ȡ��ǰ�û����͵�����˽���б�
    static QString direct_messages_new;// ����һ��˽��
    static QString direct_messages_destroy_id;// ɾ��һ��˽��
    static QString direct_messages_destroy_batch;// ����ɾ��˽��
    //��ע�ӿ�
    static QString friendships_create;// ��עĳ�û�
    static QString friendships_destroy;// ȡ����ע
    static QString friendships_exists;// �Ƿ��עĳ�û�(�Ƽ�ʹ��friendships/show)
    static QString friendships_show;// ��ȡ�����û���ϵ����ϸ���
    //����ӿ�Beta!
    static QString trends;// ��ȡĳ�˵Ļ���
    static QString trends_statuses;// ��ȡĳһ�����µ�΢��
    static QString trends_follow;// ��עĳһ������
    static QString trends_destroy;// ȡ����ע��ĳһ������
    static QString trends_hourly;// ��Сʱ�������Ż���
    static QString trends_daily;// �����ڷ������Ż��⡣����ĳһ���ڵĻ���
    static QString trends_weekly;// ���ܷ������Ż��⡣����ĳһ����֮ǰĳһ�ܵĻ���
    //Social Graph�ӿ�
    static QString friends_ids;// ��ȡ�û���ע����uid�б�
    static QString followers_ids;// ��ȡ�û���˿����uid�б�
    //��˽���ýӿ�[NEW]
    static QString account_update_privacy;// ������˽��Ϣ
    static QString account_get_privacy;// ��ȡ��˽��Ϣ
    //�������ӿ� [NEW]
    static QString blocks_create;// ��ĳ�û����������
    static QString blocks_destroy;// ��ĳ�û��Ƴ�������
    static QString blocks_exists;// ���ĳ�û��Ƿ��Ǻ������û�
    static QString blocks_blocking;// �г��������û�(����û���ϸ��Ϣ)
    static QString blocks_blocking_ids;// �г���ҳ�������û���ֻ���id��
    //�û���ǩ�ӿ�[NEW]
    static QString tags;// ����ָ���û��ı�ǩ�б�
    static QString tags_create;// ����û���ǩ
    static QString tags_suggestions;// �����û�����Ȥ�ı�ǩ
    static QString tags_destroy;// ɾ����ǩ
    static QString tags_destroy_batch;// ����ɾ����ǩ
    //�˺Žӿ�
    static QString account_verify_credentials;// ��֤��ǰ�û�����Ƿ�Ϸ�
    static QString account_rate_limit_status;// ��ȡ��ǰ�û�API����Ƶ������
    static QString account_end_session;// ��ǰ�û��˳���¼
    static QString account_update_profile_image;// ����ͷ��
    static QString account_update_profile;// ��������
    //�ղؽӿ�
    static QString favorites;// ��ȡ��ǰ�û����ղ��б�
    static QString favorites_create;// ����ղ�
    static QString favorites_destroy;// ɾ����ǰ�û��ղص�΢����Ϣ
    static QString favorites_destroy_batch;// ����ɾ���ղص�΢����Ϣ
    //��¼/OAuth�ӿ�
    static QString oauth;// OAuth��Ȩ��ʽ����
    static QString oauth_request_token;// ��ȡδ��Ȩ��Request Token
    static QString oauth_authorize;// �����û���ȨToken
    static QString oauth_access_token;// ��ȡ��Ȩ����Access Token
};

#endif // MTSINATWITTERCORE_H
