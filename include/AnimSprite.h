/*
 *
 * AnimSprite - By CrociDB
 * http://crocidb.wordpress.com/
 *
 * Obrigado por usar ^^
 *
 */

#include <allegro.h>

#include <iostream>
#include <vector>

#include <State.h>

class AnimSprite
{
private:
    std::vector<BITMAP*> frames;
    int frame_atual;
    int delay;

    int time;

    std::vector<State*> states;
    int curr_state;

    int x, y;
public:
    AnimSprite();

    void run(BITMAP* bmp);

    void SetDelay(int sdelay);
    int GetDelay() const;

    void SetX(int sx);
    void SetY(int sy);
    void SetPosition(int sx, int sy);

    int GetX() const;
    int GetY() const;

    void AddFrame(const char* file);
    void AddFrame(BITMAP* bmp);

    int GetNumFrames() const;

    void AddState(State* st);
    void FitStates();

    void SetCurrentState(int st);
    int GetCurrentState() const;
};
