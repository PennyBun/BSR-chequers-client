#ifndef COMMANDS_H
#define COMMANDS_H
#include <QString>
enum command{
    LGN,
    CRA,
    LSP,
    RFP,
    RP1,
    RP2,
    INI,
    CHB,
    YMV,
    GVU,
    EOG,
    LGO,
    ERR,
    ERS,
    MOV,
    INTERNAL_ERROR

};
struct fullCommand{
    command com;
    QString prm1;
    QString prm2;
    QString prm3;
    QString prm4;
};

#endif // COMMANDS_H
