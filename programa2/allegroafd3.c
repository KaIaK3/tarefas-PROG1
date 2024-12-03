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

#define IMAGENAME "03-saida-AFD.bmp"

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

    //desenho dos estados AFND para melhor representacao
    desenhaestado(buff, 300, 150, "q0", 1);
    desenhaestado(buff, 500, 150, "q2", 1);
    desenhaestado(buff, 400, 300, "q1", 0);


    //desenho das transicoes do AFND
    desenhatransicao(buff, 334, 150, 466, 150, "E"); //q0 --E--> q2
    desenhatransicao(buff, 320, 178, 378, 279, "E"); //q0 --E--> q1

    desenhaArcoRetorno(buff, 300, 120, "b"); //q0 --b--> q0
    desenhatransicao(buff, 270, 91, 270, 132, " "); //reta auxiliar
    desenhatransicao(buff, 330, 91, 330, 132, " " ); // reta auxiliar

    desenhaArcoRetorno(buff, 500, 120, "c"); // q2 --c--> q2
    desenhatransicao(buff, 470, 91, 470, 132, " "); // reta auxiliar
    desenhatransicao(buff, 530, 91, 530, 132, " "); // reta auxiliar

    desenhatransicao(buff, 385, 325, 385, 365," "); //q1 --a--> q1
    desenhatransicao(buff, 385, 365, 415, 365, "a"); // reta auxiliar
    desenhatransicao(buff, 415, 365, 415, 325 , " "); //reta auxiliar

    desenhaseta(buff, 220, 150, 250, 150);


/**************************** AFD **************************************/

    //desenho dos estados novos q0 e q1
    desenhaestado(buff, 250, 500, "q0", 1);
    desenhaestado(buff, 450, 500, "q1", 1);

    //desenho das transicoes
    desenhatransicao(buff, 284, 500, 412, 500, "c");
    desenhaArcoRetorno(buff, 250, 470, "a,b");
    desenhatransicao(buff, 220, 440, 220, 485, " ");
    desenhatransicao(buff, 280, 440, 280, 485, " ");
    desenhatransicao(buff, 420, 440,480, 440, "c");
    desenhatransicao(buff, 420, 440, 420, 485, " ");
    desenhatransicao(buff, 480, 440, 480, 485, " ");

    desenhaseta(buff, 160, 500, 190, 500);


    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN()


