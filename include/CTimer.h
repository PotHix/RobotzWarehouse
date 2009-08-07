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

#include <allegro.h>

#define TIMER_PAUSED                0
#define TIMER_STARTED               1

class CTimer
{
private:
    int         iCount;
    int         velocidade;
    int         status;

    static void update(void *param);

public:
                CTimer(int vel);
                ~CTimer();

    void        Start();
    void        Pause();
    int         getCount();
    void        Reset();
    int         getStatus();
    void        desc();
};
