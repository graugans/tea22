#include "statemachine.h"
#include <fmt/format.h>


int error(Event_t e)
{
    fmt::println("Error detected! Event: {}", (int)e);
    return EXIT_FAILURE;
}

int state_oben(Event_t e)
{
    fmt::println("Aktueller Zustand: OBEN Event: {}",(int)e);
    return EXIT_SUCCESS;
}

int state_unten(Event_t e)
{
    fmt::println("Aktueller Zustand: UNTEN Event: {}",(int)e);
    return EXIT_SUCCESS;
}

int state_fahre_hoch(Event_t e)
{
    fmt::println("Aktueller Zustand: FAHRE_HOCH Event: {}",(int)e);
    return EXIT_SUCCESS;
}

int state_fahre_runter(Event_t e)
{
    fmt::println("Aktueller Zustand: FAHRE_RUNTER Event: {}",(int)e);
    return EXIT_SUCCESS;
}

static StateTuple_t TransitionTable[EV_MAX][STATE_MAX] = {
    /*                             STATE_OBEN                                STATE_UNTEN                           STATE_FAHRE_HOCH                          STATE_FAHRE_RUNTER     */ 
    /* EV_TASTE              */ { {STATE_FAHRE_RUNTER,state_fahre_runter},  {STATE_FAHRE_HOCH,state_fahre_hoch},  {STATE_FAHRE_RUNTER,state_fahre_runter},  {STATE_FAHRE_HOCH,state_fahre_hoch} },
    /* EV_ENDSCHALTER_OBEN   */ { {STATE_OBEN,state_oben},                  {STATE_ERROR,error},                  {STATE_OBEN,state_oben},                  {STATE_ERROR,error}                 },
    /* EV_ENDSCHALTER_UNTEN  */ { {STATE_ERROR,error},                      {STATE_UNTEN,state_unten},            {STATE_ERROR,error},                      {STATE_UNTEN,state_unten}           }
};










MyState_t* myStatemachine_create(void)
{
    MyState_t* ret = (MyState_t*)malloc(sizeof(MyState_t));
    if(NULL != ret)
    {
        memset(ret,0,sizeof(MyState_t));
        ret->state = STATE_FAHRE_HOCH;
    }
    return ret;
}

void myStatemachine_free(MyState_t* statemachine)
{
    if(NULL != statemachine)
    {
        free(statemachine);
    }
}

int myStatemachine_handle(MyState_t* statemachine, Event_t event)
{
    int ret = 1;
    if(   ((STATE_OBEN <= statemachine->state) && (STATE_MAX > statemachine->state)))
    {
        StateTuple_t state = TransitionTable[event][statemachine->state];
        statemachine->state = state.nextState;
        ret = state.hdl(event);
    }
    return ret;
}
