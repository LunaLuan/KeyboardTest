#include "keyemitter.h"

#include <QCoreApplication>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQuickItem>

KeyEmitter::KeyEmitter() {

}


void KeyEmitter::emitKey(Qt::Key key) {
    QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
    if(!receiver)
        return;

    QString s = QKeySequence(key).toString();
    if(key == Qt::Key_Space) {
        s = " ";
    }


    QKeyEvent pressEvent = QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, s);
    QKeyEvent releaseEvent = QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);

    QCoreApplication::sendEvent(receiver, &pressEvent);
    QCoreApplication::sendEvent(receiver, &releaseEvent);
}



KeyEmitter::~KeyEmitter() {


}
