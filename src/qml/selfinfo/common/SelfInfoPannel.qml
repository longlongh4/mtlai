import Qt 4.7
//显示头像信息
Rectangle {
    width: parent.width; height: 86
    color:"#E6E8EE"
        Rectangle {
            x: 6; y: 4; width: 77; height: 77; color: "white"; smooth: true
            Image { source: "../images/test.jpg"; x: 1; y: 1 }
        }
        Column {
            x: 92; width: parent.width - 95; y: 10; spacing: 15
            Text { text: "Geng Hailong"; color: "black"; width: parent.width; font.bold: true; elide: Text.ElideRight; style: Text.Raised; styleColor: "black";font.pointSize:12 }
            Text { text: "\u8BF7\u8F93\u5165\u7F51\u5740"; width: parent.width; elide: Text.ElideLeft; color: "#cccccc"; style: Text.Raised; styleColor: "black" }
        }

}
