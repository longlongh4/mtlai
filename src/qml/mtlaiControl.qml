import Qt 4.7

Item {
    id: mtlaiControl
    ServiceList {id:serviceList;  width: parent.width; height: 54;z:5;anchors.left:parent.left
    }
    SelfInfo {id:selfInfo;  width: parent.width; anchors.bottom:parent.bottom;anchors.top:serviceList.bottom;anchors.left:parent.left }
}

