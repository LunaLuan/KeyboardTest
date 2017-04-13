#ifndef KEYEMITTER_H
#define KEYEMITTER_H

#include <QObject>

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
     void keyboardSpeciaKeyClicked(const QString &character);

};

#endif // KEYEMITTER_H
