import Qt 4.7
import "../common"
Rectangle {
    width: parent.width
    height: parent.height
    SelfInfoTitle{id:selfInfoTitle;selfInfoText:"Friends"}
    Text {
        id: coming_soon
        anchors.centerIn:parent
        text: "Coming soon!"
    }
}
