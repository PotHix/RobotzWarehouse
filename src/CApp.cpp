/*
 * Game developed by CrociDB on SpeedHack 2009
 * http://speedhack.allegro.cc/
 *
 * CrociDBlog - http://crocidb.wordpress.com/
 *
 * The App Control class.
 *
 */

#include <CApp.h>

void sair()
{
	// ESC! ;)
	key[KEY_ESC] = true;
}END_OF_FUNCTION(sair)

void CApp::Init(int sw, int sh, char *title)
{
	this->w = sw;
	this->h = sh;

	int depth, res;
    allegro_init();

	set_config_file("../config.dbc");

	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);

	int i = get_config_int("gfx", "mode", -1);
	if (i == 0)
        res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, sw, sh, 0, 0);
    else if (i == 1)
        res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, sw, sh, 0, 0);
    else
    {
        res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, sw, sh, 0, 0);
    }

	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();

	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

	// Seta o titulo da janela
	set_window_title(title);

	// Para que os sorteios acontecam realmente
	srand(time(NULL));

    CreateBuffer();
	
	LOCK_FUNCTION(sair);
	set_close_button_callback(sair);

	bmpMouse = load_bitmap("../media/mouse.bmp", NULL);
}

void CApp::Init(char *title)
{
    allegro_init();

    set_config_file("config.dbc");

	this->tw = 640;
    this->th = 480;
}

void CApp::deInit()
{
	clear_keybuf();
	allegro_exit(); // Finaliza o Allegro
}

void CApp::SwitchWide()
{
    set_config_file("config.dbc");

	if (this->wide == 0)
	{
	    w = 640;
	    h = 400;
		if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->w, this->h, 0, 0))
		{
		    allegro_message("Your monitor doesn't support this resolution.");
		    exit(-1);
		}
		set_config_int("gfx", "wide", 1);
		this->wide = 1;
	}
	else
	{
	    w = 640;
	    h = 480;
		set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->w, this->h, 0, 0);
		set_config_int("gfx", "wide", 0);
		this->wide = 0;
	}
	//this->CreateBuffer();
	set_config_int("gfx", "mode", 0);
}

void CApp::SwitchMode()
{
    set_config_file("config.dbc");

	if (is_windowed_mode())
	{
		if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, this->w, this->h, 0, 0))
		{
		    allegro_message("Your monitor doesn't support this resolution.");
		    exit(-1);
		}
		else
		{
            set_config_int("gfx", "mode", 1);
		}
	}
	else
	{
		set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->w, this->h, 0, 0);
		set_config_int("gfx", "mode", 0);
	}
}

void CApp::ClearBuffer()
{
	clear(this->buffer);
}

void CApp::ClearBuffer(int col)
{
	clear_to_color(buffer, col);
}

void CApp::Refresh()
{
	//stretch_blit(this->buffer, screen, 0, 0, tw, th, 0, 0, this->w, this->h);
	blit(this->buffer, screen, 0, 0, 0, 0, this->w, this->h);
}

void CApp::ShowMouse()
{
    draw_sprite(this->buffer, bmpMouse, mouse_x, mouse_y);
}

void CApp::fade_in(BITMAP *bmp_orig, int speed)
{
   BITMAP *bmp_buff;

    if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        int a;
        if (speed <= 0) speed = 16;

        for (a = 0; a < 256; a+=speed)
        {
            clear(bmp_buff);
            set_trans_blender(0,0,0,a);
            draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
            vsync();
            blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
        }
        destroy_bitmap(bmp_buff);
    }

    blit(bmp_orig, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
}

void CApp::fadeInToColor(BITMAP *bmp_orig, int speed, int color)
{
   BITMAP *bmp_buff;

    if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        clear_to_color(bmp_buff, color);
        int a;
        if (speed <= 0) speed = 16;

        for (a = 0; a < 256; a+=speed)
        {
            clear_to_color(bmp_buff, color);
            set_trans_blender(0,0,0,a);
            draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
            vsync();
            blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
        }
        destroy_bitmap(bmp_buff);
    }

    blit(bmp_orig, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
}

void CApp::fade_out(int speed)
{
    BITMAP *bmp_orig, *bmp_buff;

    if ((bmp_orig = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
        {
            int a;
            blit(screen, bmp_orig, 0,0, 0,0, SCREEN_W, SCREEN_H);
            if (speed <= 0) speed = 16;

            for (a = 255-speed; a > 0; a-=speed)
            {
                clear(bmp_buff);
                set_trans_blender(0,0,0,a);
                draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
                vsync();
                blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
            }
            destroy_bitmap(bmp_buff);
        }
        destroy_bitmap(bmp_orig);
    }

    rectfill(screen, 0,0, SCREEN_W,SCREEN_H, makecol(0,0,0));
}

void CApp::fadeOutToColor(int speed, int color)
{
    BITMAP *bmp_orig, *bmp_buff;

    if ((bmp_orig = create_bitmap(SCREEN_W, SCREEN_H)))
    {
        if ((bmp_buff = create_bitmap(SCREEN_W, SCREEN_H)))
        {
            clear_to_color(bmp_buff, color);
            int a;
            blit(screen, bmp_orig, 0,0, 0,0, SCREEN_W, SCREEN_H);
            if (speed <= 0) speed = 16;

            for (a = 255-speed; a > 0; a-=speed)
            {
                clear_to_color(bmp_buff, color);
                set_trans_blender(0,0,0,a);
                draw_trans_sprite(bmp_buff, bmp_orig, 0, 0);
                vsync();
                blit(bmp_buff, screen, 0,0, 0,0, SCREEN_W, SCREEN_H);
            }
            destroy_bitmap(bmp_buff);
        }
        destroy_bitmap(bmp_orig);
    }

    rectfill(screen, 0,0, SCREEN_W,SCREEN_H, makecol(0,0,0));
}

void CApp::SetBuffer(BITMAP *dbuffer)
{
	this->buffer = dbuffer;
}

BITMAP* CApp::GetBuffer()
{
	return this->buffer;
}

void CApp::CreateBuffer()
{
    this->buffer = create_bitmap(tw, th);
}

int CApp::isWide()
{
    return wide;
}

