#ifndef VIETNAMESEIMEALGORITHM_H
#define VIETNAMESEIMEALGORITHM_H

#include <QString>
#include <QObject>

class VietnameseIMEAlgorithm
{
public:
    VietnameseIMEAlgorithm();
    virtual QString process(QString q) = 0;

private:

};

#endif // VIETNAMESEIMEALGORITHM_H
