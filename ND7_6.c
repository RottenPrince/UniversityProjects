#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);
int validation(int dish_num, int menuSize);
int main()
{
    char *title = "Prasciausios virtuves Meniu";
    char *options[] = {"Skeriu liezuviai", "Veziu kepenys", "Zyliu smegenys", "Jaguaro ausys", "Barsuko bluznis", "Udros nosys", "Varliu akys", "Gruzdinti tarakonai"};
    int size = 8;
    char *message = "Sveiki atvyke i prasciausia miesto restorana.\nKadangi esame tokie prasti, starteriu neturime, todel raginame iskart pereiti prie pagrindinio vakaro patiekalo";
    int num = showMenu(title, options, size, message);
    printf("%d pasirinkimas yra sefo specialusis. %s yra tikras delikatesas pietu Azijos salyse.\nDeja, turiu perspeti, kad teks palaukti bent 20 min.\n", num, options[num - 1]);
    return 0;
}

 int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
 {
    redo:
    printf("%s\n", menuTitle);
    for(int i = 0; i < menuSize; ++i)
    {
        printf("%d) %s;\n", i + 1, menuOptions[i]);
    }

    printf("%s.Prasome pasirinkti patiekala ir pasakyti jo numeri is musu kuklaus Meniu\n", inputMsg);

    int dish_num;
    while(scanf("%d", &dish_num) != 1 || validation(dish_num, menuSize) != 1 || getchar() != '\n' )
    {
        printf("Jusu paprasyto patiekalo kol kas musu asorti nera.\nPagarbiai prasome pasirinkti patiekala is Meniu\n");
        while(getchar() != '\n')
            ;
        goto redo;
    }
    return dish_num;
 }

int validation(int dish_num, int menuSize)
{
    if(dish_num >= 1 && dish_num <= menuSize)
        return 1;  
}