#include <stdio.h>
#include <stdlib.h>
                            
void triangle_pascal(int (*tab)[10], unsigned taille)
{
    tab[0][0] = 1;

    for (unsigned i = 1; i < taille; ++i)
    {
        tab[i][0] = 1;
    
        for (unsigned j = 1; j < i; ++j)
            tab[i][j] = tab[i - 1][j  - 1] + tab[i - 1][j];
    
        tab[i][i] = 1;
    }
}

void print_triangle(int (*tab)[10], unsigned taille)
{
    for (unsigned i = 0; i < taille; ++i)
    {
        for (int sp = taille - 1 - i; sp > 0; --sp)
            printf(" ");
    
        for (unsigned j = 0; j < taille; ++j)
            if (tab[i][j] != 0)
                printf("%d ", tab[i][j]);
    
        printf("\n");
    }
}

int main(void)
{
    int tab[10][10] = { { 0 } };
    unsigned taille;

    printf("Taille du triangle : ");

    if (scanf("%u", &taille) != 1)
    {
        printf("Mauvais saisie\n");
        return EXIT_FAILURE;
    }
    else if (taille > 10) {
        printf("La taille ne doit pas etre superieure a 10\n");
        return EXIT_FAILURE;
    }

    triangle_pascal(tab, taille);
    print_triangle(tab, taille);
    return 0;
}
      