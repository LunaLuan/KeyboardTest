#include "keyemitter.h"

#include <QCoreApplication>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQuickItem>
#include <QDebug>

KeyEmitter::KeyEmitter() {
    currentString = new QString("");
    realString = new QString("");

    engine = new TelextAlgorithm();
}


void KeyEmitter::emitKey(Qt::Key key) {
    QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
    if(!receiver)
        return;

    QString s = QKeySequence(key).toString();
    if(key == Qt::Key_Space) {
        s = " ";
        currentString->append(s);

        QKeyEvent pressEvent = QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, s);
        QKeyEvent releaseEvent = QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);

        QCoreApplication::sendEvent(receiver, &pressEvent);
        QCoreApplication::sendEvent(receiver, &releaseEvent);

        return;
    }
    qDebug()<<"- Current string: "<<*currentString;

    QRegExp tagExp(" ");
    QStringList ls = currentString->split(tagExp);
    QString cs = ls[ls.length() - 1];
    cs.append(s);

    QString new_cs = engine->process(cs);

    QInputMethodEvent event;
    if(new_cs != cs) {
        for(int i = 0 ; i < cs.length() - 1 ; i++) {
            event.setCommitString("", -1, 1);
            QCoreApplication::sendEvent(receiver, &event);
        }
        cs = new_cs;
        event.setCommitString(cs);
        QCoreApplication::sendEvent(receiver, &event);
    }
    else {
        event.setCommitString(s);
        QCoreApplication::sendEvent(receiver, &event);
    }

    *currentString = "";
    for(int i = 0 ; i < ls.length() - 2 ; i++) {
        currentString->append(ls[i]);
    }
    currentString->append(cs);
}

void KeyEmitter::keyboardSpecialKeyClicked(Qt::Key key)
{
    QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
    if(!receiver)
        return;

    if(key == Qt::Key_Enter) {
        QKeyEvent *pressEvent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
        QCoreApplication::postEvent(receiver, pressEvent);

        QKeyEvent *releaseEvent = new QKeyEvent(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier);
        QCoreApplication::postEvent(receiver, releaseEvent);
    }
    else if(key == Qt::Key_Backspace) {
        QString newString = currentString->mid(0, currentString->length() - 1);
        currentString = &newString;

        QKeyEvent *pressBackspace = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);
        QCoreApplication::postEvent(receiver, pressBackspace);

        QKeyEvent *releaseEvent = new QKeyEvent(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier);
        QCoreApplication::postEvent(receiver, releaseEvent);
    }

}


KeyEmitter::~KeyEmitter() {
    delete currentString;
    // delete engine;
    delete realString;
}
