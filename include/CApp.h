/*
 * Game developed by CrociDB on SpeedHack 2009
 * http://speedhack.allegro.cc/
 *
 * CrociDBlog - http://crocidb.wordpress.com/
 *
 * The App Control class.
 *
 */

#include <allegro.h>

class CApp
{
private:
    /* Variaveis que guardam a resolucao */
	int w, h;
	/* Tamanho para programacao */
	int tw, th;
	/* Buffer */
	BITMAP *buffer;
	/* Wide */
	int wide;
	/* Bitmap do mouse */
	BITMAP *bmpMouse;
public:
	/* Funcao de Inicializacao */
	void Init(int sw, int sh, char *title);
	/* Funcao de Inicializacao (carrega info do arquivo) */
	void Init(char *title);
	/* Funcao de Desiniciacao */
	void deInit();
	/* Funcao que muda entre Fullscreen e Windowed */
	void SwitchMode();
    /* Funcao que muda entre Widescreen e normal */
	void SwitchWide();
	/* Limpa o Buffer */
	void ClearBuffer();
	void ClearBuffer(int col);
	/* Funcao que atualiza o buffer */
	void Refresh();
	/* Mostra o cursor */
	void ShowMouse();

	/* Está em Widescreen? */
	int isWide();

    /* Seta o Buffer */
	void SetBuffer(BITMAP *dbuffer);
    /* Pega o Buffer */
	BITMAP *GetBuffer();
	/* Cria um Buffer */
	void CreateBuffer();

    /* Fade In */
    void fade_in(BITMAP *bmp_orig, int speed);
    void fadeInToColor(BITMAP *bmp_orig, int speed, int color);
    /* Fade Out */
    void fade_out(int speed);
    void fadeOutToColor(int speed, int color);

};
