import Qt 4.7
Item {
    id: mtListView
    width:parent.width

    property string currentDataItem: "abc"
    //property bool loading: dataModel.status == XmlListModel.Loading
    property bool loading:true
    ListDataModel{id:listDataModel}
    Rectangle {
        width: parent.width; height: mtListView.height
        color: "#E6E8EE"

        ListView {
            focus: true
            id: dataList
            anchors.fill: parent
            model: listDataModel
            delegate: ListDelegateWithoutBusyIndicator {}
            highlight: Rectangle { color: "steelblue" }
            highlightMoveSpeed: 9999999
            boundsBehavior:Flickable.StopAtBounds
        }
        ScrollBar {
            scrollArea: dataList; height: dataList.height; width: 8
            anchors.right: dataList.right
        }
    }
}

