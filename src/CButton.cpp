/*
 * Game developed by CrociDB on SpeedHack 2007
 * http://speedhack.allegro.cc/
 *
 * CrociDBlog - http://crocidb.wordpress.com/
 *
 * The App Control class.
 *
 */

#include <CButton.h>

CButton::CButton(char *txt, int tp, int cx, int cy, int cw, int ch, BITMAP *buffer)
{
    this->text = new char[50];
    strcpy(this->text, txt);

    this->type = tp;

    this->x = cx;
    this->y = cy;
    this->w = cw;
    this->h = ch;

    this->buf = buffer;

    this->align = LEFT;

    this->up = 0;

    if (this->type == 1)
    {

    }
}

void CButton::setDesc(char *txt)
{
    this->desc = new char[100];
    strcpy(this->desc, txt);
}

void CButton::setText(char *txt)
{
    this->text = new char[100];
    strcpy(this->text, txt);
}

void CButton::setFont(FONT *fnt)
{
    this->fonte = fnt;
}

void CButton::setAlign(int al)
{
    this->align = al;
}

void CButton::setPosition(int cx, int cy)
{
    this->x = cx;
    this->y = cy;
}

void CButton::setColors(int a, int b)
{
    this->ncolor = a;
    this->ucolor = b;

    this->color = ncolor;
}

void CButton::runButton()
{
    if (this->type == 0)
    {
        if (this->align == LEFT)
        {
            textprintf_ex(this->buf, fonte, this->x, this->y, color, -1, "%s", this->text);

            if ((mouse_x > this->x) && (mouse_x < this->x + this->w) && (mouse_y > this->y) && (mouse_y < this->y + this->h))
            {
                this->color = this->ucolor;
                this->up = 1;
            }
            else
            {
                this->color = this->ncolor;
                this->up = 0;
            }
        }
        else
        {
            textprintf_centre_ex(this->buf, fonte, this->x, this->y, color, -1, "%s", this->text);

            if ((mouse_y > this->y) && (mouse_y < this->y + this->h))
            {
                this->color = this->ucolor;
                this->up = 1;
            }
            else
            {
                this->color = this->ncolor;
                this->up = 0;
            }
        }

    }
}

int CButton::isPressed()
{
    if (this->up == 1)
    {
        if (mouse_b & 1)
        {
            return 1;
        }
    }
    return 0;
}


