/*
 *
 * AnimSprite - By CrociDB
 * http://crocidb.wordpress.com/
 *
 * Obrigado por usar ^^
 *
 */

#include <State.h>

State::State(int f, int l)
{
    SetFirstFrame(f);
    SetLastFrame(l);
}


void State::SetFirstFrame(int f)
{
    this->first = f;
}

void State::SetLastFrame(int l)
{
    this->last = l;
}


int State::GetFirstFrame() const
{
    return this->first;
}

int State::GetLastFrame() const
{
    return this->last;
}

int State::GetNumFrames() const
{
    return (GetLastFrame()-GetFirstFrame()) + 1;
}


