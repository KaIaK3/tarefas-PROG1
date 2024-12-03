#include <stdio.h>
#include <allegro.h>
#include <math.h>

#define CORBRANCO (makecol(255, 255, 255))
#define CORPRETO (makecol(0, 0, 0))
#define CORCINZA (makecol(160, 160, 160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255, 255, 100))
#define CORVERMELHO (makecol(255, 0, 0))

#define IMAGENAME "01-saida-PETRI.bmp" /* nome do arquivo de imagem */


void desenhaestado(BITMAP *bmp, int x, int y, const char *label, int is_final)
{
    circle(bmp, x, y, 30, CORPRETO);
    textprintf_centre_ex(bmp, font, x, y - 4, CORPRETO, -1, "%s", label);
    if (is_final)
    {
        circle(bmp, x, y, 34, CORPRETO);
    }
}

void desenhaArcoTransicao(BITMAP *bmp, int x, int y, const char *label)
{
    arc(bmp, x, y, itofix(32), itofix(96), 70, CORPRETO);
    textprintf_centre_ex(bmp, font, x, y - 50, CORPRETO, -1, "%s", label);
}

void desenhatransicao(BITMAP *bmp, int x1, int y1, int x2, int y2, const char *label)
{
    line(bmp, x1, y1, x2, y2, CORPRETO);
    int label_x = (x1 + x2) / 2;
    int label_y = (y1 + y2) / 2;
    textprintf_centre_ex(bmp, font, label_x, label_y - 10, CORPRETO, -1, "%s", label);
}


int main(void)
{
    BITMAP *buff;
    PALETTE pal;

    if (install_allegro(SYSTEM_NONE, &errno, atexit) != 0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);
     set_window_title("REDE DE PETRI");
    // Cria uma janela de dimensao 800x600 para desenharmos nela
    buff = create_bitmap(800, 600);
    if (buff == NULL) {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    clear_to_color(buff, CORBRANCO);


    //desenho dos lugares
    desenhaestado(buff, 230, 100," . .", 0); //l0
    desenhaestado(buff, 440, 100,". . .", 0 ); //l1
    desenhaestado(buff, 450, 215, " ", 0); //l2

    desenhaArcoTransicao(buff, 282, 117, " "); // l0 --> t0
    desenhaArcoTransicao(buff, 389, 117, " "); // t0 --> l1
    desenhatransicao(buff, 335, 70, 335, 130, "  ");
    desenhatransicao(buff, 335, 170, 335, 230, "  ");
    desenhatransicao(buff, 230, 132, 284, 190, " 2 ");
    desenhatransicao(buff, 284, 190, 331, 190, " "); //l0 --> t1
    desenhaArcoTransicao(buff, 388, 240, " "); //t1 --> l2

    desenhatransicao(buff, 335, 65, 336, 65, "T0");
    desenhatransicao(buff, 335, 240, 335, 240, "T1");
    desenhatransicao(buff, 190, 100, 191, 100, "L0");
    desenhatransicao(buff, 490, 100, 491, 100, "L1");
    desenhatransicao(buff, 450, 260, 451, 260, "L2");

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN()

