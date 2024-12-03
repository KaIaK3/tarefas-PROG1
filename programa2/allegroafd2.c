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

#define IMAGENAME "02-saida-AFD.bmp" /* nome do arquivo de imagem */

void desenhaestado(BITMAP *bmp, int x, int y, const char *label, int is_final)
{
    circle(bmp, x, y, 30, CORPRETO);
    textprintf_centre_ex(bmp, font, x, y - 4, CORPRETO, -1, "%s", label);
    if (is_final)
    {
        circle(bmp, x, y, 34, CORPRETO);
    }
}

void desenhatransicao(BITMAP *bmp, int x1, int y1, int x2, int y2, const char *label)
{
    line(bmp, x1, y1, x2, y2, CORPRETO);
    int label_x = (x1 + x2) / 2;
    int label_y = (y1 + y2) / 2;
    textprintf_centre_ex(bmp, font, label_x, label_y - 10, CORPRETO, -1, "%s", label);
}


void desenhaArcoRetorno(BITMAP *bmp, int x, int y, const char *label)
{
    arc(bmp, x, y, itofix(32), itofix(96), 40, CORPRETO);
    textprintf_centre_ex(bmp, font, x, y - 50, CORPRETO, -1, "%s", label);
}

void desenhaseta(BITMAP *bmp, int x1, int y1, int x2, int y2)
{
    line(bmp, x1, y1, x2, y2, CORPRETO);
    float angle = atan2(y2 - y1, x2 - x1);
    int arrow_length = 10;
    int arrow_angle = 20; // degrees

    int arrow_x1 = x2 - arrow_length * cos(angle - M_PI / 180 * arrow_angle);
    int arrow_y1 = y2 - arrow_length * sin(angle - M_PI / 180 * arrow_angle);

    int arrow_x2 = x2 - arrow_length * cos(angle + M_PI / 180 * arrow_angle);
    int arrow_y2 = y2 - arrow_length * sin(angle + M_PI / 180 * arrow_angle);

    line(bmp, x2, y2, arrow_x1, arrow_y1, CORPRETO);
    line(bmp, x2, y2, arrow_x2, arrow_y2, CORPRETO);
}


int main(void)
{
    BITMAP *buff;
    PALETTE pal;

    if (install_allegro(SYSTEM_NONE, &errno, atexit) != 0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Create a larger buffer for the DFA diagram.
    buff = create_bitmap(800, 600);
    if (buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    clear_to_color(buff, CORBRANCO);

    // desenho dos estados (q0, q1, q2, q3)
    desenhaestado(buff, 150, 300, "q0", 0);
    desenhaestado(buff, 300, 300, "q1", 1);
    desenhaestado(buff, 450, 300, "q2", 0);
    desenhaestado(buff, 600, 300, "q3", 1);

    //desenho das transições
    desenhatransicao(buff, 180, 300, 264, 300, "a,b"); //q0 --ab--> q1
    desenhatransicao(buff, 330, 300, 416, 300, "a"); // q1 --a--> q2
    desenhatransicao(buff, 480, 300, 566, 300, "c"); // q2 --c--> q3
                                                     //
    desenhaArcoRetorno(buff, 300, 270, "a,b"); // q1 --ab--> q1 (retorno)
    desenhatransicao(buff, 272, 241, 272, 282, " "); // auxiliar do retorno
    desenhatransicao(buff, 328, 241, 328, 282, " "); // auxiliar do retorno
                                                     //
    desenhaArcoRetorno(buff, 450, 270, "b"); // q2 --b--> q2
    desenhatransicao(buff, 422, 241, 422, 286, " "); //auxiliar do retorno
    desenhatransicao(buff, 478, 241, 478, 286, " "); //auxiliar do retorno

    desenhaArcoRetorno(buff, 600, 270, "c"); // q3 --c--> q3
    desenhatransicao(buff, 572, 241, 572, 282, " "); // auxiliar do retorno
    desenhatransicao(buff, 628, 241, 628, 282, " "); // auxiliar do retorno

    desenhatransicao(buff, 150, 330, 150, 400, " "); //q0 --ac--> q3
    desenhatransicao(buff, 150, 400, 600, 400, "a,c");
    desenhatransicao(buff, 600, 400, 600, 334, " ");

    desenhatransicao(buff, 300, 334, 300, 360, " "); //q1 --c--> q3
    desenhatransicao(buff, 300, 360, 590, 360, "c");
    desenhatransicao(buff, 590, 360, 590, 334, " ");


    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN()

