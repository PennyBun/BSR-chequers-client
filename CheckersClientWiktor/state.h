#ifndef STATE_H
#define STATE_H
enum state{
    NLG,//NOT LOGGED
    LGN_WFR, //LGN - WAITING FOR RESPONSE
    CRA_WFR,
    ROOM,
    LSP_WFR,
    WAITR, //WAIT FOR RESPONSE
    WAITG, //WAIT FOR GAME START
    GAME,
    RECEIVED_UNEXPECTED_COMMAND,
};

#endif // STATE_H