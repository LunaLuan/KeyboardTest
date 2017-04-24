#include "telextalgorithm.h"

TelextAlgorithm::TelextAlgorithm()
{
    QString temp[] = {
        "aas", "aaf", "aar", "aax", "aaj", "aa", "as", "af", "ar", "ax", "aj", "aws", "awf",
        "awr", "awx", "awj", "aw", "us", "uf", "ur", "ux", "uj", "uws", "uwf", "uwr", "uwx",
        "uwj", "uw", "ees", "eef", "eer", "eex", "eej", "ee", "es", "ef", "er", "ex", "ej",
        "oos", "oof", "oor", "oox", "ooj", "oo", "os", "of", "or", "ox", "oj", "ows", "owf",
        "owr", "owx", "owj", "ow", "is", "if", "ir", "ix", "ij", "ys", "yf", "yr", "yx", "yj",
        "dd", "AAS", "AAF", "AAR", "AAX", "AAJ", "AA", "AS", "AF", "AR", "AX",
        "AJ", "AWS", "AWF", "AWR", "AWX", "AWJ", "AW", "US", "UF", "UR", "UX",
        "UJ", "UWS", "UWF", "UWR", "UWX", "UWJ", "UW", "EES", "EEF", "EER",
        "EEX", "EEJ", "EE", "ES", "EF", "ER", "EX", "EJ", "OOS", "OOF", "OOR",
        "OOX", "OOJ", "OO", "OS", "OF", "OR", "OX", "OJ", "OWS", "OWF", "OWR",
        "OWX", "OWJ", "OW", "IS", "IF", "IR", "IX", "IJ", "YS", "YF", "YR", "YX",
        "YJ", "DD"
    };

    QChar unicodeString[] = {
        7845, 7847, 7849, 7851, 7853, 226, 225, 224, 7843, 227, 7841, 7855, 7857, 7859,
        7861, 7863, 259, 250, 249, 7911, 361, 7909, 7913, 7915, 7917, 7919, 7921, 432,
        7871, 7873, 7875, 7877, 7879, 234, 233, 232, 7867, 7869, 7865, 7889, 7891, 7893,
        7895, 7897, 244, 243, 242, 7887, 245, 7885, 7899, 7901, 7903, 7905, 7907, 417,
        237, 236, 7881, 297, 7883, 253, 7923, 7927, 7929, 7925, 273, 7844, 7846, 7848,
        7850, 7852, 194, 193, 192, 7842, 195, 7840, 7854, 7856, 7858, 7860, 7862, 258,
        218, 217, 7910, 360, 7908, 7912, 7914, 7916, 7918, 7920, 431, 7870, 7872, 7874,
        7876, 7878, 202, 201, 200, 7866, 7868, 7864, 7888, 7890, 7892, 7894, 7896, 212,
        211, 210, 7886, 213, 7884, 7898, 7900, 7902, 7904, 7906, 416, 205, 204, 7880, 296,
        7882, 221, 7922, 7926, 7928, 7924, 272
    };

    QChar dontCare[] = {
        'Q', 'T', 'Y', 'I', 'P',
        'G', 'H', 'J', 'K', 'L',
        'Z', 'C', 'V', 'B', 'N', 'M',
        'q', 't', 'y', 'i', 'p',
        'g', 'h', 'j', 'k', 'l',
        'z', 'c', 'v', 'b', 'n', 'm'
    };


    int mapLength = sizeof(unicodeString) / sizeof(unicodeString[0]);
    for(int i = 0 ; i < mapLength ; i++) {
        map.insert(temp[i], unicodeString[i]);
    }

    int dontCareLength = sizeof(dontCare) /sizeof(dontCare[0]);
    for(int i = 0 ; i < dontCareLength ; i++) {
        dontCareSet.insert(dontCare[i]);
    }

}

TelextAlgorithm::~TelextAlgorithm()
{

}

QString TelextAlgorithm::process(QString q)
{
    QString temp[] = {
        "aas", "aaf", "aar", "aax", "aaj", "aa", "as", "af", "ar", "ax", "aj", "aws", "awf",
        "awr", "awx", "awj", "aw", "us", "uf", "ur", "ux", "uj", "uws", "uwf", "uwr", "uwx",
        "uwj", "uw", "ees", "eef", "eer", "eex", "eej", "ee", "es", "ef", "er", "ex", "ej",
        "oos", "oof", "oor", "oox", "ooj", "oo", "os", "of", "or", "ox", "oj", "ows", "owf",
        "owr", "owx", "owj", "ow", "is", "if", "ir", "ix", "ij", "ys", "yf", "yr", "yx", "yj",
        "dd", "AAS", "AAF", "AAR", "AAX", "AAJ", "AA", "AS", "AF", "AR", "AX",
        "AJ", "AWS", "AWF", "AWR", "AWX", "AWJ", "AW", "US", "UF", "UR", "UX",
        "UJ", "UWS", "UWF", "UWR", "UWX", "UWJ", "UW", "EES", "EEF", "EER",
        "EEX", "EEJ", "EE", "ES", "EF", "ER", "EX", "EJ", "OOS", "OOF", "OOR",
        "OOX", "OOJ", "OO", "OS", "OF", "OR", "OX", "OJ", "OWS", "OWF", "OWR",
        "OWX", "OWJ", "OW", "IS", "IF", "IR", "IX", "IJ", "YS", "YF", "YR", "YX",
        "YJ", "DD"
    };

    QChar unicodeString[] = {
        7845, 7847, 7849, 7851, 7853, 226, 225, 224, 7843, 227, 7841, 7855, 7857, 7859,
        7861, 7863, 259, 250, 249, 7911, 361, 7909, 7913, 7915, 7917, 7919, 7921, 432,
        7871, 7873, 7875, 7877, 7879, 234, 233, 232, 7867, 7869, 7865, 7889, 7891, 7893,
        7895, 7897, 244, 243, 242, 7887, 245, 7885, 7899, 7901, 7903, 7905, 7907, 417,
        237, 236, 7881, 297, 7883, 253, 7923, 7927, 7929, 7925, 273, 7844, 7846, 7848,
        7850, 7852, 194, 193, 192, 7842, 195, 7840, 7854, 7856, 7858, 7860, 7862, 258,
        218, 217, 7910, 360, 7908, 7912, 7914, 7916, 7918, 7920, 431, 7870, 7872, 7874,
        7876, 7878, 202, 201, 200, 7866, 7868, 7864, 7888, 7890, 7892, 7894, 7896, 212,
        211, 210, 7886, 213, 7884, 7898, 7900, 7902, 7904, 7906, 416, 205, 204, 7880, 296,
        7882, 221, 7922, 7926, 7928, 7924, 272
    };

    int mapLength = sizeof(unicodeString) / sizeof(unicodeString[0]);
    for(int i = 0 ; i < mapLength ; i++) {
        q.replace(temp[i], unicodeString[i], Qt::CaseSensitive);
    }

    return q;
}

