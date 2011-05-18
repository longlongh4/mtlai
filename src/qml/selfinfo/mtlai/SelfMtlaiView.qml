import Qt 4.7
import "../common"
import "../../common"
Item {
    width:parent.width
    height:parent.height
    SelfInfoTitle{id:selfInfoTitle;selfInfoText:"Mtlai"}
    SelfInfoPannel{id:selfInfoPannel;anchors.top:selfInfoTitle.bottom}
    SelfInfoSearchBar{id:selfInfoSearchBar;anchors.top:selfInfoPannel.bottom}
    MtListView{id:mtListView;anchors.top:selfInfoSearchBar.bottom;anchors.bottom:parent.bottom;z:-5}
}
