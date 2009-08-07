/*
 *
 * AnimSprite - By CrociDB
 * http://crocidb.wordpress.com/
 *
 * Obrigado por usar ^^
 *
 */

#include <AnimSprite.h>

/* Construtor */

AnimSprite::AnimSprite()
{
    SetPosition(0, 0);
    SetDelay(10);

    time = 0;
    frame_atual = 0;
    curr_state = 0;
}


/* Métodos de Delay da Animação */

void AnimSprite::SetDelay(int sdelay)
{
    this->delay = sdelay;
}

int AnimSprite::GetDelay() const
{
    return this->delay;
}


/* Método de Execução */

void AnimSprite::run(BITMAP* bmp)
{
    time++;
    if (frames.size() > 0)
    {
        draw_trans_sprite(bmp, frames[frame_atual], GetX(), GetY());
        if ((time-delay) > 0)
        {
            time = 0;
            if (states[curr_state]->GetNumFrames() > 1)
            {
                if (frame_atual++ == states[curr_state]->GetLastFrame())
                {
                    frame_atual = states[curr_state]->GetFirstFrame();
                }
            }
            else
            {
                frame_atual = states[curr_state]->GetFirstFrame();
            }
        }
    }
}


/* Métodos de Coordenadas do Sprite */

void AnimSprite::SetX(int sx)
{
    this->x = sx;
}

void AnimSprite::SetY(int sy)
{
    this->y = sy;
}

void AnimSprite::SetPosition(int sx, int sy)
{
    this->x = sx;
    this->y = sy;
}

int AnimSprite::GetX() const
{
    return this->x;
}

int AnimSprite::GetY() const
{
    return this->y;
}


/* Métodos do Vetor de Bitmaps */

void AnimSprite::AddFrame(const char* file)
{
    frames.push_back(load_bitmap(file, NULL));
}

void AnimSprite::AddFrame(BITMAP* bmp)
{
    frames.push_back(bmp);
}

int AnimSprite::GetNumFrames() const
{
    return frames.size();
}


/* Métodos para controle dos States */

void AnimSprite::AddState(State* st)
{
    states.push_back(st);
}

void AnimSprite::FitStates()
{
    states.push_back(new State(0, frames.size()-1));
}

void AnimSprite::SetCurrentState(int st)
{
    this->curr_state = st;
    this->time = this->delay;
    frame_atual = states[curr_state]->GetFirstFrame();
}

int AnimSprite::GetCurrentState() const
{
    return this->curr_state;
}
