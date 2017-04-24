#ifndef KEYEMITTER_H
#define KEYEMITTER_H

#include <QObject>
#include <QString>
#include "vietnameseimealgorithm.h"
#include "telextalgorithm.h"

#include <math.h>

class KeyEmitter : public QObject
{
    Q_OBJECT

public:
    KeyEmitter();
    ~KeyEmitter();

    bool isValid();
    void showInputPanel();
    void hideInputPanel();

signals:

public slots:
     void emitKey(Qt::Key key);
     void keyboardSpecialKeyClicked(Qt::Key key);

private:
     QString *currentString;
     QString *realString;

     VietnameseIMEAlgorithm *engine;

};

#endif // KEYEMITTER_H
