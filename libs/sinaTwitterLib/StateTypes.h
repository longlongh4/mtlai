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
        quint64 id;// 用户UID
        QString screen_name;// 微博昵称
        QString name;// 好友显示名称，如Bill Gates(此特性暂不支持)
        int province;// 省份编码（参考省份编码表）
        int city;// 城市编码（参考城市编码表）
        QString location;//地址
        QString description;// 个人描述
        QString url;// 用户博客地址
        QString profile_image_url;// 自定义图像
        QString domain;// 用户个性化URL
        SexType gender;// 性别,m--男，f--女,n--未知
        int followers_count;// 粉丝数
        int friends_count;// 关注数
        quint64 statuses_count;// 微博数
        int favourites_count;// 收藏数
        QDateTime created_at;// 创建时间
        bool following;// 是否已关注(此特性暂不支持)
        bool verified;// 加V标示，是否微博认证用户
    };
    struct Status
    {
        Status(){user=NULL;}
        QDateTime createdAt;//微博创建时间
        quint64 id; //微博ID
        QString text;//微博信息内容
        Source source;// 微博来源
        bool favorited;// 是否已收藏(正在开发中，暂不支持)
        bool truncated;// 是否被截断
        quint64 in_reply_to_status_id;// 回复ID
        quint64 in_reply_to_user_id;// 回复人UID
        QString in_reply_to_screen_name;// 回复人昵称
        QString thumbnail_pic; //缩略图
        QString bmiddle_pic;//中型图片
        QString original_pic;//原始图片
        User* user; //作者信息
        struct Status *retweeted_status; //转发的博文，内容为status，如果不是转发，则没有此字段
    };

    struct Comment
    {
        Comment(){user=NULL;status=NULL;reply_comment=NULL;}
        quint64 id;// 评论ID
        QString text;// 评论内容
        QString source;// 评论来源
        bool favorited;// 是否收藏
        bool truncated;// 是否被截断
        QDateTime created_at;// 评论时间
        User* user;// 评论人信息,结构参考user
        Status* status;// 评论的微博,结构参考status
        struct Comment *reply_comment;// 评论来源，数据结构跟comment一致
    };
    struct DirectMessage
    {
        DirectMessage(){sender=NULL;recipient=NULL;}
        quint64 id;// 私信ID
        QString text;// 私信内容
        quint64 sender_id;//发送人UID
        quint64 recipient_id;// 接受人UID
        QDateTime created_at;// 发送时间
        QString sender_screen_name;// 发送人昵称
        QString recipient_screen_name;//接受人昵称
        User* sender;// 发送人信息，参考user说明
        User* recipient;// 接受人信息，参考user说明
    };
    enum RequestType
    {
        STATUSES_PUBLIC_TIMELINE,// 获取最新的公共微博消息
        STATUSES_FRIENDS_TIMELINE,// 获取当前登录用户及其所关注用户的最新微博消息 (别名: STATUSES/HOME_TIMELINE)
        STATUSES_USER_TIMELINE,// 获取当前登录用户发布的微博消息列表
        STATUSES_MENTIONS,// 获取@当前用户的微博列表
        STATUSES_COMMENTS_TIMELINE,// 获取当前用户发送及收到的评论列表
        STATUSES_COMMENTS_BY_ME,// 获取当前用户发出的评论
        STATUSES_COMMENTS_TO_ME,// 获取当前用户收到的评论
        STATUSES_COMMENTS,// 根据微博消息ID返回某条微博消息的评论列表
        STATUSES_COUNTS,// 批量获取一组微博的评论数及转发数
        STATUSES_REPOST_TIMELINE,// 返回一条原创微博的最新N条转发微博信息 NEW!
        STATUSES_REPOST_BY_ME,// 返回用户转发的最新N条微博信息 NEW!
        STATUSES_UNREAD,// 获取当前用户未读消息数
        STATUSES_RESET_COUNT,// 未读消息数清零接口
        EMOTIONS,// 表情接口，获取表情列表
          //微博访问接口
        STATUSES_SHOW,// 根据ID获取单条微博信息内容
        USER_STATUSES_ID,// 根据微博ID和用户ID跳转到单条微博页面
        STATUSES_UPDATE,// 发布一条微博信息UPDATED!
        STATUSES_UPLOAD,// 上传图片并发布一条微博信息
        STATUSES_DESTROY,// 删除一条微博信息
        STATUSES_REPOST,// 转发一条微博信息UPDATED!
        STATUSES_COMMENT,// 对一条微博信息进行评论
        STATUSES_COMMENT_DESTROY_ID,// 删除当前用户的微博评论信息
        STATUSES_COMMENT_DESTROY_BATCH,// 批量删除当前用户的微博评论信息
        STATUSES_REPLY,// 回复微博评论信息
          //用户接口
        USERS_SHOW,// 根据用户ID获取用户资料（授权用户）
        STATUSES_FRIENDS,// 获取用户关注列表及每个关注用户最新一条微博
        STATUSES_FOLLOWERS,// 获取用户粉丝列表及及每个粉丝用户最新一条微博
        USERS_HOT,// 获取系统推荐用户
        USER_FRIENDS_UPDATE_REMARK,//更新当前登录用户所关注的某个好友的备注信息NEW!
        USERS_SUGGESTIONS,// 返回当前用户可能感兴趣的用户 BETA!
          //私信接口
        DIRECT_MESSAGES,// 获取当前用户最新私信列表
        DIRECT_MESSAGES_SENT,// 获取当前用户发送的最新私信列表
        DIRECT_MESSAGES_NEW,// 发送一条私信
        DIRECT_MESSAGES_DESTROY_ID,// 删除一条私信
        DIRECT_MESSAGES_DESTROY_BATCH,// 批量删除私信
          //关注接口
        FRIENDSHIPS_CREATE,// 关注某用户
        FRIENDSHIPS_DESTROY,// 取消关注
        FRIENDSHIPS_EXISTS,// 是否关注某用户(推荐使用FRIENDSHIPS/SHOW)
        FRIENDSHIPS_SHOW,// 获取两个用户关系的详细情况
          //话题接口BETA!
        TRENDS,// 获取某人的话题
        TRENDS_STATUSES,// 获取某一话题下的微博
        TRENDS_FOLLOW,// 关注某一个话题
        TRENDS_DESTROY,// 取消关注的某一个话题
        TRENDS_HOURLY,// 按小时返回热门话题
        TRENDS_DAILY,// 按日期返回热门话题。返回某一日期的话题
        TRENDS_WEEKLY,// 按周返回热门话题。返回某一日期之前某一周的话题
          //SOCIAL GRAPH接口
        FRIENDS_IDS,// 获取用户关注对象UID列表
        FOLLOWERS_IDS,// 获取用户粉丝对象UID列表
          //隐私设置接口[NEW]
        ACCOUNT_UPDATE_PRIVACY,// 设置隐私信息
        ACCOUNT_GET_PRIVACY,// 获取隐私信息
          //黑名单接口 [NEW]
        BLOCKS_CREATE,// 将某用户加入黑名单
        BLOCKS_DESTROY,// 将某用户移出黑名单
        BLOCKS_EXISTS,// 检测某用户是否是黑名单用户
        BLOCKS_BLOCKING,// 列出黑名单用户(输出用户详细信息)
        BLOCKS_BLOCKING_IDS,// 列出分页黑名单用户（只输出ID）
          //用户标签接口[NEW]
        TAGS,// 返回指定用户的标签列表
        TAGS_CREATE,// 添加用户标签
        TAGS_SUGGESTIONS,// 返回用户感兴趣的标签
        TAGS_DESTROY,// 删除标签
        TAGS_DESTROY_BATCH,// 批量删除标签
          //账号接口
        ACCOUNT_VERIFY_CREDENTIALS,// 验证当前用户身份是否合法
        ACCOUNT_RATE_LIMIT_STATUS,// 获取当前用户API访问频率限制
        ACCOUNT_END_SESSION,// 当前用户退出登录
        ACCOUNT_UPDATE_PROFILE_IMAGE,// 更改头像
        ACCOUNT_UPDATE_PROFILE,// 更改资料
          //收藏接口
        FAVORITES,// 获取当前用户的收藏列表
        FAVORITES_CREATE,// 添加收藏
        FAVORITES_DESTROY,// 删除当前用户收藏的微博信息
        FAVORITES_DESTROY_BATCH,// 批量删除收藏的微博信息
          //登录/OAUTH接口
        OAUTH,// OAUTH授权方式介绍
        OAUTH_REQUEST_TOKEN,// 获取未授权的REQUEST TOKEN
        OAUTH_AUTHORIZE,// 请求用户授权TOKEN
        OAUTH_ACCESS_TOKEN,// 获取授权过的ACCESS TOKEN
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
