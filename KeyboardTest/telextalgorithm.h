#ifndef TELEXTALGORITHM_H
#define TELEXTALGORITHM_H

#include "vietnameseimealgorithm.h"
#include <QMap>
#include <QDebug>

class TelextAlgorithm: public VietnameseIMEAlgorithm
{
public:
    TelextAlgorithm();
    ~TelextAlgorithm();

    virtual QString process(QString q);

private:
    QMap<QString, QChar> map;
    QSet<QChar> dontCareSet;


};

#endif // TELEXTALGORITHM_H
