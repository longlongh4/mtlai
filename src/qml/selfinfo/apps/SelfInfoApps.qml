import Qt 4.7
import "../common"
import "../../common"

Item {
    id:selfInfoApps
    width: parent.width
    height: parent.height
    property string currentAppName: ""
    SelfInfoTitle{id:selfInfoTitle;selfInfoText:"Apps"}
    Item {
        id: mtListView
        width:parent.width
        anchors.top:selfInfoTitle.bottom
        anchors.bottom:parent.bottom
        Component
                {
                    id:selfInfoAppsDelegate
                    Item {
                        id: delegate

                        width: delegate.ListView.view.width; height: 42

                        Text {
                            text: title
                            color: delegate.ListView.isCurrentItem ? "white" : "black"
                            font { family: "Helvetica"; pixelSize: 16; bold: true }
                            anchors {
                                left: parent.left; leftMargin: 15
                                verticalCenter: parent.verticalCenter
                            }
                        }

                        Rectangle {
                            width: delegate.width; height: 1; color: "#cccccc"
                            anchors.bottom: delegate.bottom
                            visible: delegate.ListView.isCurrentItem ? false : true
                        }
                        Rectangle {
                            width: delegate.width; height: 1; color: "white"
                            visible: delegate.ListView.isCurrentItem ? false : true
                        }

                        MouseArea {
                            anchors.fill: delegate
                            onClicked: {
                                delegate.ListView.view.currentIndex = index
                                if(currentAppName!=name)
                                {
                                    currentAppName=name
                                    MtlaiContext.loadNewApp(name,type);

                                }
                            }
                        }
                    }
                }
        Rectangle {
            width: parent.width; height: parent.height
            color: "#E6E8EE"

            ListView {
                focus: true
                id: dataList
                anchors.fill: parent
                model: PluginModel
                delegate: selfInfoAppsDelegate
                highlight: Rectangle { color: "steelblue" }
                highlightMoveSpeed: 9999999
                boundsBehavior:Flickable.StopAtBounds
            }
        }
    }
}
