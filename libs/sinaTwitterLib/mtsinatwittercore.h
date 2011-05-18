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
    //记录每个QNetworkReply的请求类型
    QMap<QNetworkReply*,STATETYPES::RequestType> requestMap;
    static QString sina_api_key;//api key
    static QString sina_twitter_host;//sina微博地址
    //获取下行数据集(timeline)接口
    static QString statuses_public_timeline;// 获取最新的公共微博消息
    static QString statuses_friends_timeline;// 获取当前登录用户及其所关注用户的最新微博消息 (别名: statuses/home_timeline)
    static QString statuses_user_timeline;// 获取当前登录用户发布的微博消息列表
    static QString statuses_mentions;// 获取@当前用户的微博列表
    static QString statuses_comments_timeline;// 获取当前用户发送及收到的评论列表
    static QString statuses_comments_by_me;// 获取当前用户发出的评论
    static QString statuses_comments_to_me;// 获取当前用户收到的评论
    static QString statuses_comments;// 根据微博消息ID返回某条微博消息的评论列表
    static QString statuses_counts;// 批量获取一组微博的评论数及转发数
    static QString statuses_repost_timeline;// 返回一条原创微博的最新n条转发微博信息 New!
    static QString statuses_repost_by_me;// 返回用户转发的最新n条微博信息 New!
    static QString statuses_unread;// 获取当前用户未读消息数
    static QString statuses_reset_count;// 未读消息数清零接口
    static QString emotions;// 表情接口，获取表情列表
    //微博访问接口
    static QString statuses_show;// 根据ID获取单条微博信息内容
    static QString user_statuses_id;// 根据微博ID和用户ID跳转到单条微博页面
    static QString statuses_update;// 发布一条微博信息Updated!
    static QString statuses_upload;// 上传图片并发布一条微博信息
    static QString statuses_destroy;// 删除一条微博信息
    static QString statuses_repost;// 转发一条微博信息Updated!
    static QString statuses_comment;// 对一条微博信息进行评论
    static QString statuses_comment_destroy_id;// 删除当前用户的微博评论信息
    static QString statuses_comment_destroy_batch;// 批量删除当前用户的微博评论信息
    static QString statuses_reply;// 回复微博评论信息
    //用户接口
    static QString users_show;// 根据用户ID获取用户资料（授权用户）
    static QString statuses_friends;// 获取用户关注列表及每个关注用户最新一条微博
    static QString statuses_followers;// 获取用户粉丝列表及及每个粉丝用户最新一条微博
    static QString users_hot;// 获取系统推荐用户
    static QString user_friends_update_remark;//更新当前登录用户所关注的某个好友的备注信息New!
    static QString users_suggestions;// 返回当前用户可能感兴趣的用户 Beta!
    //私信接口
    static QString direct_messages;// 获取当前用户最新私信列表
    static QString direct_messages_sent;// 获取当前用户发送的最新私信列表
    static QString direct_messages_new;// 发送一条私信
    static QString direct_messages_destroy_id;// 删除一条私信
    static QString direct_messages_destroy_batch;// 批量删除私信
    //关注接口
    static QString friendships_create;// 关注某用户
    static QString friendships_destroy;// 取消关注
    static QString friendships_exists;// 是否关注某用户(推荐使用friendships/show)
    static QString friendships_show;// 获取两个用户关系的详细情况
    //话题接口Beta!
    static QString trends;// 获取某人的话题
    static QString trends_statuses;// 获取某一话题下的微博
    static QString trends_follow;// 关注某一个话题
    static QString trends_destroy;// 取消关注的某一个话题
    static QString trends_hourly;// 按小时返回热门话题
    static QString trends_daily;// 按日期返回热门话题。返回某一日期的话题
    static QString trends_weekly;// 按周返回热门话题。返回某一日期之前某一周的话题
    //Social Graph接口
    static QString friends_ids;// 获取用户关注对象uid列表
    static QString followers_ids;// 获取用户粉丝对象uid列表
    //隐私设置接口[NEW]
    static QString account_update_privacy;// 设置隐私信息
    static QString account_get_privacy;// 获取隐私信息
    //黑名单接口 [NEW]
    static QString blocks_create;// 将某用户加入黑名单
    static QString blocks_destroy;// 将某用户移出黑名单
    static QString blocks_exists;// 检测某用户是否是黑名单用户
    static QString blocks_blocking;// 列出黑名单用户(输出用户详细信息)
    static QString blocks_blocking_ids;// 列出分页黑名单用户（只输出id）
    //用户标签接口[NEW]
    static QString tags;// 返回指定用户的标签列表
    static QString tags_create;// 添加用户标签
    static QString tags_suggestions;// 返回用户感兴趣的标签
    static QString tags_destroy;// 删除标签
    static QString tags_destroy_batch;// 批量删除标签
    //账号接口
    static QString account_verify_credentials;// 验证当前用户身份是否合法
    static QString account_rate_limit_status;// 获取当前用户API访问频率限制
    static QString account_end_session;// 当前用户退出登录
    static QString account_update_profile_image;// 更改头像
    static QString account_update_profile;// 更改资料
    //收藏接口
    static QString favorites;// 获取当前用户的收藏列表
    static QString favorites_create;// 添加收藏
    static QString favorites_destroy;// 删除当前用户收藏的微博信息
    static QString favorites_destroy_batch;// 批量删除收藏的微博信息
    //登录/OAuth接口
    static QString oauth;// OAuth授权方式介绍
    static QString oauth_request_token;// 获取未授权的Request Token
    static QString oauth_authorize;// 请求用户授权Token
    static QString oauth_access_token;// 获取授权过的Access Token
};

#endif // MTSINATWITTERCORE_H
