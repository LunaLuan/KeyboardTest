import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Window {
    id: mainWindow
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    title: qsTr("Hello World")

    TextInput {
        id: inputField
        anchors.horizontalCenter: parent.horizontalCenter
        height: 60
        text: "1234"
        font.pointSize: 30
        onAccepted: focus= true
        anchors.top: parent.top
        anchors.topMargin: 30
        Keys.onEscapePressed: undo()
    }

    Row {
        id: keyRow1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: inputField.bottom
        anchors.topMargin: 20

        Button {
            id: button1
            text: qsTr("1")
            onClicked: keyEmitter.emitKey(Qt.Key_1)
        }
        Button {
            id: button2
            text: qsTr("2")
            onClicked: keyEmitter.emitKey(Qt.Key_2)
        }
        Button {
            id: button3
            text: qsTr("3")
            onClicked: keyEmitter.emitKey(Qt.Key_3)
        }
        Button {
            id: button4
            text: qsTr("4")
            onClicked: keyEmitter.emitKey(Qt.Key_4)
        }
        Button {
            id: button5
            text: qsTr("5")
            onClicked: keyEmitter.emitKey(Qt.Key_5)
        }
        Button {
            id: button6
            text: qsTr("6")
            onClicked: keyEmitter.emitKey(Qt.Key_6)
        }
        Button {
            id: button7
            text: qsTr("7")
            onClicked: keyEmitter.emitKey(Qt.Key_7)
        }
        Button {
            id: button8
            text: qsTr("8")
            onClicked: keyEmitter.emitKey(Qt.Key_8)
        }
        Button {
            id: button9
            text: qsTr("9")
            onClicked: keyEmitter.emitKey(Qt.Key_9)
        }
        Button {
            id: button0
            text: qsTr("0")
            onClicked: keyEmitter.emitKey(Qt.Key_0)
        }

        Button {
            id: buttonBackspace
            text: qsTr("<-")
            onClicked: keyEmitter.keyboardSpecialKeyClicked(Qt.Key_Backspace)
        }
    }

    Row {
        id: keyRow2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: keyRow1.bottom
        anchors.topMargin: 20

        Button {
            id: buttonQ
            text: qsTr("Q")
            onClicked: keyEmitter.emitKey(Qt.Key_Q)
        }
        Button {
            id: buttonW
            text: qsTr("W")
            onClicked: keyEmitter.emitKey(Qt.Key_W)
        }
        Button {
            id: buttonE
            text: qsTr("E")
            onClicked: keyEmitter.emitKey(Qt.Key_E)
        }
        Button {
            id: buttonR
            text: qsTr("R")
            onClicked: keyEmitter.emitKey(Qt.Key_R)
        }
        Button {
            id: buttonT
            text: qsTr("T")
            onClicked: keyEmitter.emitKey(Qt.Key_T)
        }
        Button {
            id: buttonY
            text: qsTr("Y")
            onClicked: keyEmitter.emitKey(Qt.Key_Y)
        }
        Button {
            id: buttonU
            text: qsTr("U")
            onClicked: keyEmitter.emitKey(Qt.Key_U)
        }
        Button {
            id: buttonI
            text: qsTr("I")
            onClicked: keyEmitter.emitKey(Qt.Key_I)
        }
        Button {
            id: buttonO
            text: qsTr("O")
            onClicked: keyEmitter.emitKey(Qt.Key_O)
        }
        Button {
            id: buttonP
            text: qsTr("P")
            onClicked: keyEmitter.emitKey(Qt.Key_P)
        }
    }

    Row {
        id: keyRow3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: keyRow2.bottom
        anchors.topMargin: 20

        Button {
            id: buttonA
            text: qsTr("A")
            onClicked: keyEmitter.emitKey(Qt.Key_A)
        }
        Button {
            id: buttonS
            text: qsTr("S")
            onClicked: keyEmitter.emitKey(Qt.Key_S)
        }
        Button {
            id: buttonD
            text: qsTr("D")
            onClicked: keyEmitter.emitKey(Qt.Key_D)
        }
        Button {
            id: buttonF
            text: qsTr("F")
            onClicked: keyEmitter.emitKey(Qt.Key_F)
        }
        Button {
            id: buttonG
            text: qsTr("G")
            onClicked: keyEmitter.emitKey(Qt.Key_G)
        }
        Button {
            id: buttonH
            text: qsTr("H")
            onClicked: keyEmitter.emitKey(Qt.Key_H)
        }
        Button {
            id: buttonJ
            text: qsTr("J")
            onClicked: keyEmitter.emitKey(Qt.Key_J)
        }
        Button {
            id: buttonK
            text: qsTr("K")
            onClicked: keyEmitter.emitKey(Qt.Key_K)
        }
        Button {
            id: buttonL
            text: qsTr("L")
            onClicked: keyEmitter.emitKey(Qt.Key_L)
        }

        Button {
            id: buttonEnter
            text: qsTr("Enter")
            onClicked: keyEmitter.keyboardSpecialKeyClicked(Qt.Key_Enter)
        }

    }

    Row {
        id: keyRow4
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: keyRow3.bottom
        anchors.topMargin: 20

        Button {
            id: buttonZ
            text: qsTr("Z")
            onClicked: keyEmitter.emitKey(Qt.Key_Z)
        }
        Button {
            id: buttonX
            text: qsTr("X")
            onClicked: keyEmitter.emitKey(Qt.Key_X)
        }
        Button {
            id: buttonC
            text: qsTr("C")
            onClicked: keyEmitter.emitKey(Qt.Key_C)
        }
        Button {
            id: buttonV
            text: qsTr("V")
            onClicked: keyEmitter.emitKey(Qt.Key_V)
        }
        Button {
            id: buttonB
            text: qsTr("B")
            onClicked: keyEmitter.emitKey(Qt.Key_B)
        }
        Button {
            id: buttonN
            text: qsTr("N")
            onClicked: keyEmitter.emitKey(Qt.Key_N)
        }
        Button {
            id: buttonM
            text: qsTr("M")
            onClicked: keyEmitter.emitKey(Qt.Key_M)
        }
    }

    Row {
        id: keyRow5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: keyRow4.bottom
        anchors.topMargin: 20

        Button {
            id: buttonCtrl
            text: qsTr("Ctrl")
        }
        Button {
            id: buttonShift
            text: qsTr("Shift")
        }

        Button {
            id: buttonSpace
            text: qsTr("Space")
            width: 300
            onClicked: keyEmitter.emitKey(Qt.Key_Space)
        }
        Button {
            id: buttonAlt
            text: qsTr("Alt")
        }
    }

}
