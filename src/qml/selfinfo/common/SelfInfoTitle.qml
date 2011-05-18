import Qt 4.7
//显示标题栏
Rectangle{
    id:selfInfoTitle
    //要显示的文本内容
    property alias selfInfoText: selfInfoTitleText.text
    width:parent.width
    height:35
    gradient: Gradient {
        GradientStop { position: 0.0; color: "#66b4fa" }
        GradientStop { position: 0.4; color: "#227be4" }
        //GradientStop { position: 0.6; color: "#d1d6e0" }
        GradientStop { position: 1; color: "#3787ea" }
    }
    Text {
        id: selfInfoTitleText
        anchors.verticalCenter:parent.verticalCenter
        text: ""
        anchors.left:parent.left
        anchors.leftMargin:10
        font.pixelSize:22
    }
}
