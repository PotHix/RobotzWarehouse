/*
 * Game developed by CrociDB on SpeedHack 2007
 * http://speedhack.allegro.cc/
 *
 * CrociDBlog - http://crocidb.wordpress.com/
 *
 * The App Control class.
 *
 */

#include <allegro.h>
#include <strings.h>

#define CENTER              1
#define LEFT                0

/*
 * Valores para TYPE:
 * 0 - Texto normal
 * 1 - Texto com fundo do botão
 */

class CButton
{
private:
    char *text;
    char *desc;
    int type;

    int x, y;
    int w, h;

    int ncolor, ucolor;
    int color;

    BITMAP *buf;
    FONT *fonte;

    int up;
    int align;
public:
    int id;

            CButton(char *txt, int tp, int cx, int cy, int cw, int ch, BITMAP *buffer);

    void    setDesc(char *txt);
    void    setText(char *txt);

    void    setFont(FONT * fnt);
    void    setAlign(int al);

    void    setPosition(int cx, int cy);

    void    setColors(int a, int b);

    void    runButton();
    int     isPressed();

            ~CButton();
};

