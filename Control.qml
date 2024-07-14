import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick.Layouts
//import QtLocation 6.7

Rectangle {
    id: main
    // x: 0
    // y: 0
    //width: height * 1.2
    //height: parent.height
    //anchors.fill: parent
    //Column {
    // id: col1
    // width: parent.width / 1.625
    // height: parent.height * 0.9
    // spacing: 10
    GridLayout {
        id: grid
        //x: 0
        //y: 0
        width: parent.width
        rowSpacing: 15
        //height: 150
        columnSpacing: 10

        rows: 4
        columns: 15
        //Layout.fillWidth: true
        //Layout.fillHeight: true
        Text {
            id: text2
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("ТЕСТ")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text3
            Layout.fillHeight: true
            //Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            //Layout.fillWidth: true
            //Layout.horizontalStretchFactor: 1
            text: qsTr("СУДЬИ")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text4
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: qsTr("1")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text5
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("2")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }
        Text {
            id: text6
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("3")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: text1
            Layout.fillHeight: true
            Layout.fillWidth: true

            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("4")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: text7
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("5")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            //id: text7
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("СУММА")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        Rectangle {
            Layout.fillHeight: true
            //Layout.fillWidth: true
            width: 1
            color: "lightgray"
            Layout.rowSpan: 3
        }

        Text {
            //id: text7
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("ОБЩАЯ СУММА")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            Layout.columnSpan: 6
        }

        Text {
            id: text8
            //width: parent.width / 8
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.rowSpan: 2
            text: qsTr("5")
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        Rectangle {
            //width: parent.width / 8
            height: 0
        }
        TextField {
            id: textField
            //width: parent.width / 20
            Layout.preferredWidth: parent.width / 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField1
            Layout.preferredWidth: parent.width / 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField2
            Layout.preferredWidth: parent.width / 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField3
            Layout.preferredWidth: parent.width / 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }

        TextField {
            id: textField4
            Layout.preferredWidth: parent.width / 20
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }

        Text {
            id: summ
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("140.5")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //Layout.rowSpan: 2
        }

        Text {
            id: summBlue
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("140.5")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //Layout.rowSpan: 2
            Layout.columnSpan: 2
        }

        Text {
            id: summTotal
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("140.5")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.columnSpan: 2
        }

        Text {
            id: summRed
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("140.5")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.columnSpan: 2
        }
        // Rectangle{
        //     width: 10
        //     height: 10
        //     color: "red"
        // }
        Rectangle {

            height: 0
        }
        Rectangle {
            width: 0
        }
        RoundButton {
            id: roundButton
            Image{
                anchors.fill: parent
                source: "images/x.png"
            }
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        RoundButton {
            id: roundButton1
            Image{
                anchors.fill: parent
                source: "images/x.png"
            }
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        RoundButton {
            id: roundButton2
            //icon.source: "images/x.png"
            //Layout.preferredHeight: parent.height * 0.2
            //Layout.preferredWidth: parent.width
            //icon.height: height
            //icon.width: width
            Image{
                anchors.fill: parent
                source: "images/x.png"
            }

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        RoundButton {
            id: roundButton3

            //icon.source: "images/x.png"
            //padding: 0

            //icon.url: "images/x.png"
            //icon.height: height * 0.9
            // icon.height: height * 0.9
            // icon.width: width * 0.9
            //text: "X"
            Image{
                anchors.fill: parent

                //smooth: true
                //antialiasing: true

                //mipmap: true
                source: "images/x.png"
            }
            //antialiasing: true
            //smooth: true

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 6
        }
        // Rectangle{
        //     Layout.fillHeight: true
        //     Layout.fillWidth: true
        // }
        // Rectangle{
        //     Layout.fillHeight: true
        //     Layout.fillWidth: true
        // }
        Rectangle{
            height: 1
            Layout.columnSpan: 15
            Layout.fillWidth: true
            color: "lightgray"
        }
    }

    GridLayout {
        id: grid1
        width: parent.width * 0.6
        height: parent.height - grid.height - 60
        rowSpacing: 10
        y: grid.height + 30

        //scale: 0.9
        //anchors.left: grid.left
        //anchors.top: grid.bottom
        //anchors.leftMargin: 8
        //anchors.topMargin: 36
        columnSpacing: 10
        Layout.fillHeight: true
        rows: 8
        columns: 4

        // Rectangle {
        //     id: rectangle0
        //     Layout.preferredWidth: parent.width * 0.95
        //     //width: parent.width
        //     height: 1
        //     color: "lightgray"
        //     Layout.columnSpan: 3
        //     Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        // }

        Text {
            //Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("-0.5")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.rowSpan: 2
        }

        Text {
            //Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("-1.0")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.rowSpan: 2
        }

        Text {
            //Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: parent.width / 8
            //Layout.alignment: AlignHCenter
            text: qsTr("-2.0")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //Layout.rowSpan: 2
        }

        Rectangle{
            Layout.rowSpan: 8
            Layout.fillHeight: true
            width: 1
            color: "lightgray"
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            id: rec1
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Неэффективный\nзахват")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Неэффективное\nконвоирование")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Медленно,\nбез усилий")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Частичная потеря\nравновесия")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            //color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
            color: mouse.hovered ? "#ba69cafa" : "#5c69cafa"
            HoverHandler{
                id: mouse
                acceptedDevices: PointerDevice.Mouse
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "#5c69cafa"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("Не подана команда\nпри выполнении")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.width / 10
            }
        }


        Rectangle {
            id: rectangle
            Layout.fillWidth: true
            //width: parent.width
            height: 1
            color: "lightgray"
            Layout.columnSpan: 3
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "red"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("0")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "red"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("+1")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }
        }

        Rectangle {
            //Layout.fillWidth: true
            //Layout.fillHeight: true
            Layout.minimumHeight: parent.height / 8
            Layout.minimumWidth: parent.width / 4
            color: "red"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Text {
                anchors.fill: parent
                text: qsTr("ВВОД")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
            }
        }

    }

    Rectangle {
        x: grid1.width
        y: grid.height
        width: parent.width - grid1.width
        height: parent.height - grid.height
        //anchors.left: col1.right
        //anchors.leftMargin: 0
        color: "transparent"

        Rectangle  {
            id: row
            //x: grid1.width
            //y: grid.height
            width: parent.width
            height: parent.height / 8
            //rightPadding: 10
            //leftPadding: 10
            //spacing: 0
            //rows: 1
            //columns: 3

            Text {
                id: text9

                x: 0
                y: 0
                width: parent.width * 0.45
                height: parent.height
                //Layout.fillHeight: true
                //Layout.fillWidth: true
                text: qsTr("Спортсмен\nс синим поясом")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                color: "blue"

            }

            Rectangle {
                id: button

                x: parent.width * 0.45
                y: (parent.height - height) / 2
                width: parent.width * 0.1
                height: parent.width * 0.1
                color: "lightgray"

                Image{
                    //anchors.fill: parent
                    x: 4
                    y: 4
                    width: parent.width - 8
                    height: parent.width - 8
                    smooth: true
                    antialiasing: true
                    source: "qrc:/images/change.png"
                    mipmap: true
                }
            }

            Text {
                id: text10
                x: parent.width * 0.55
                y: 0
                width: parent.width * 0.45
                height: parent.height
                text: qsTr("Спортсмен\nс красным поясом")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "red"
            }
        }

        Rectangle {
            id: flow1
            x: 0
            y: row.height
            width: parent.width
            //height: parent.height - row.height
            height: parent.height - row.height
            color:"transparent"
            //margins: 10
            Button {
                id: button1
                x: parent.width / 4
                y: parent.height * 0.06
                width: parent.width / 2
                height: parent.height * 0.25
                text: qsTr("Следующий\nвопрос")
                //Layout.fillHeight: true
                //Layout.fillWidth: true
                //Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
            Button {
                id: button2
                text: qsTr("Зафиксировать\nрезультат")
                x: parent.width / 4
                y: parent.height * 0.37
                width: parent.width / 2
                height: parent.height * 0.25
            }
            GroupBox {
                id: groupBox
                x: parent.width / 4
                y: parent.height * 0.68
                width: parent.width / 2
                height: parent.height * 0.25
                //Layout.fillHeight: true
                //Layout.fillWidth: true
                title: qsTr("Первый вопрос")

                label: Label {
                    x: groupBox.leftPadding
                    y: 10
                    width: groupBox.availableWidth
                    height: 10

                    text: groupBox.title
                    // background: Rectangle{ color: "white"}

                    //     //groupBox.title

                    // //color: "#21be2b"
                    elide: Text.ElideRight
                }


                ColumnLayout {
                    anchors.fill: parent
                    //anchors.bottomMargin: -59

                    enabled: false
                    RadioButton {
                        id: radioButton
                        text: qsTr("Красный")
                    }

                    RadioButton {
                        id: radioButton1
                        text: qsTr("Синий")
                        checked: true
                    }
                }
            }
        }




    }


}


