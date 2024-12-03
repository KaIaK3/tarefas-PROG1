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

#define IMAGENAME "01-saida-AFD.bmp" /* nome do arquivo de imagem */

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
    if (buff == NULL) {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    clear_to_color(buff, CORBRANCO);

    // Desenho dos estados (q0, q1, q2)
    desenhaestado(buff, 150, 300, "q0", 0);  // q0
    desenhaestado(buff, 400, 150, "q1", 1);  // q1
    desenhaestado(buff, 650, 300, "q2", 0);  // q2

    // desenho das transicoes
    desenhatransicao(buff, 180, 300, 370, 170, "a"); // q0 --a--> q1
    desenhatransicao(buff, 180, 300, 620, 300, "b"); // q0 --b--> q2
    desenhatransicao(buff, 620, 300, 430, 170, "a"); // q2 --a--> q1
    desenhatransicao(buff, 370, 102, 370, 132, " "); // auxilio do retorno q1
    desenhatransicao(buff, 430, 102, 430, 132, " "); // auxilio do retorno q1
    desenhatransicao(buff, 620, 252, 620, 290, " "); // auxilio do retorno q2
    desenhatransicao(buff, 680, 252, 680, 290, " "); // auxilio do retorno q2
    desenhaArcoRetorno(buff, 400, 130, "a,b"); // q1 --a--> q1 (retorno)
    desenhaArcoRetorno(buff, 650, 280, "b"); // q2 --b--> q2 (retorno)

    // desenho da seta inicial
    desenhaseta(buff, 80, 300, 110, 300); // seta apontando para q0


    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN()
