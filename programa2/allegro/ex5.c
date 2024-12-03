#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define IMAGENAME "circulo.bmp" /*nome da imagem*/

int main()
{
    //inicialização
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("TESTE DO ALLEGRO");

    //variavel
     int x = 100, y = 100;

     while (!key[KEY_ESC])
     {
        circlefill(screen, x, y, 100, makecol(211, 140, 11));
     }

    return 0;
}
END_OF_MAIN();
