/***************************************************\
**            Desenvolvido por CrociDB             **
**                                                 **
** Voce pode usar a vontade este codigo, desde que **
**  coloque os devidos creditos ao autor original. **
**                                                 **
**   Nao me resposabilizo por seus atos com este   **
**                      codigo.                    **
**                                                 **
\***************************************************/

#include "CTimer.h"

CTimer::CTimer(int vel)
{
    this->velocidade = vel;

    iCount = 0;
    status = TIMER_PAUSED;

    LOCK_VARIABLE(iCount);
    LOCK_FUNCTION(update);
}

void CTimer::update(void *param)
{
    CTimer *pthis = (CTimer*)param;
    ++(pthis->iCount);
} END_OF_FUNCTION(update)

void CTimer::Start()
{
    install_param_int(CTimer::update, this, velocidade);
    status = TIMER_STARTED;
}

void CTimer::Pause()
{
    remove_param_int(CTimer::update, this);
    status = TIMER_PAUSED;
}

int CTimer::getCount()
{
    return this->iCount;
}

void CTimer::Reset()
{
    this->iCount = 0;
}

int CTimer::getStatus()
{
    return status;
}

void CTimer::desc()
{
    this->iCount--;
}

CTimer::~CTimer()
{
    remove_param_int(CTimer::update, this);
}


