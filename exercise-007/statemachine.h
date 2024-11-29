#ifndef MY_STATEMACHINE_H
#define MY_STATEMACHINE_H

typedef enum {
    STATE_OBEN         = 0,
    STATE_UNTEN        = 1,
    STATE_FAHRE_HOCH   = 2,
    STATE_FAHRE_RUNTER = 3,
    STATE_ERROR        = 4,
    STATE_MAX
} StatemachineState_t;

typedef enum {
    EV_TASTE               = 0,
    EV_ENDSCHALTER_OBEN    = 1,
    EV_ENDSCHALTER_UNTEN   = 2,
    EV_MAX
} Event_t;

typedef int (*stateHandler_t)(Event_t e);

typedef struct {
    StatemachineState_t nextState;
    stateHandler_t hdl;
}StateTuple_t;

typedef struct MyState{
    StatemachineState_t state; /*< The state   */
} MyState_t;

MyState_t* myStatemachine_create(void);
void myStatemachine_free(MyState_t* statemachine);
int myStatemachine_handle(MyState_t* statemachine, Event_t event);



#endif