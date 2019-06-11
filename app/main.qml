import QtQuick 2.0
import QtQuick.Window 2.2
import Qt.labs.settings 1.0
import com.machinekoder 1.0

Window {
    id: appWindow
    visible: true
    width: 1000
    height: 800
    
    Text {
        anchors.centerIn: parent
        text: "Foo"
    }
    
    Vibrator {
        id: vibrator
    }
}
