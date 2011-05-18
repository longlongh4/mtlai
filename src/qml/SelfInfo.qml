import Qt 4.7
import "selfinfo/mtlai"
import "selfinfo/settings"
import "selfinfo/groups"
import "selfinfo/friends"
import "selfinfo/apps"
Item {
    id:selfInfo
    width:parent.width
    anchors.left:parent.left
    SelfMtlaiView{id:selfMtlaiView}
    SelfInfoFriends{id:selfInfoContacts}
    SelfInfoGroups{id:selfInfoGroups}
    SelfInfoSettings{id:selfInfoSettings}
    SelfInfoApps{id:selfInfoApps}
}
