import Qt 4.7

Rectangle {
    id:serviceListRectangle
    property int current: 0

    //设置ServiceList与SelfInfo的连接
    onCurrentChanged: setOpacities()
    Component.onCompleted: setOpacities()
    function setOpacities() {
        for (var i = 0; i < selfInfo.children.length; ++i) {
            selfInfo.children[i].opacity = (i == current ? 1 : 0)
        }
    }
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#7b7b7b" }
        GradientStop { position: 0.4; color: "#717171" }
        GradientStop { position: 0.6; color: "#5e5e5e" }
        GradientStop { position: 1; color: "#787878" }
    }
    ListModel {
        id: serviceListModel
        ListElement { name: "Mtlai"; icon: "qrc:/Resources/rss.png" }
        ListElement { name: "Friends"; icon: "qrc:/Resources/rss.png" }
        ListElement { name: "Groups"; icon: "qrc:/Resources/rss.png" }
        ListElement { name: "Settings"; icon: "qrc:/Resources/rss.png" }
        ListElement { name: "Apps"; icon: "qrc:/Resources/rss.png" }
    }
    Component {
        id: serviceListDelegate

        Item {
            width: 46; height: 46
            Rectangle{
                id:serviceListDelegateBackground
                anchors.fill:parent
                color:"#3c3c3c"
                radius:5
                opacity:0
            }
            Image {
                id: myIcon
                anchors.horizontalCenter: parent.horizontalCenter
                source: icon
            }
            Text {
                anchors { top: myIcon.bottom; horizontalCenter: parent.horizontalCenter }
                text: name
                color:"white"
            }
            MouseArea{
                hoverEnabled:true
                anchors.fill:parent
                onEntered:{serviceListDelegateBackground.opacity=0.5}
                onExited:{serviceListDelegateBackground.opacity=0}
                onClicked:{
                    serviceListView.currentIndex=index
                    current=index
                }
            }
        }
    }

    Component {
        id: serviceListHighlight
        Rectangle { width: 46; height: 46;
            color:"#3c3c3c"
            radius:5
        }
    }
    ListView {
        id:serviceListView
        anchors.topMargin:3
        anchors.fill: parent
        anchors.leftMargin:11
        anchors.rightMargin:11
        orientation:ListView.Horizontal
        spacing:10
        highlight: serviceListHighlight
        focus: true
        model: serviceListModel
        delegate: serviceListDelegate
    }

}
