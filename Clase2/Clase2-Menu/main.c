#include <stdio.h>
#include <stdlib.h>
/*
Solo me deja restar si antes sume
*/
int main()
{
    char opcion;
    char salir='n';
    int flag=0;

    do
    {
        system("cls");
        printf("-----Menu de Opciones -----\n\n");
        printf("a- Sumar\n");
        printf("b- Restar\n");
        printf("c- Multiplicar\n");
        printf("d- Dividir\n");
        printf("e- Salir\n\n");
        printf("Indique opcion: \n");
        fflush(stdin);
        opcion= getche();

        switch(opcion)
        {
        case 'a':
            printf("\nUsted eligio sumar\n");
            system("pause");
            flag = 1;
            break;
        case 'b':
            if(flag == 0)
            {
                printf("\nPara restar primero tiene que sumar\n");
            }
            else
            {
                printf("\nUsted eligio restar\n");

            }
            system("pause");
            break;
        case 'c':
            printf("\nUsted eligio multiplicar\n");
            system("pause");
            break;
        case 'd':
            printf("\nUsted eligio dividir\n");
            system("pause");
            break;
        case 'e':
            printf("\nConfirma salida?\n");
            fflush(stdin);
            salir=getchar();
            break;
        default:
            printf("\nOpcion invalida\n\n");
            system("pause");
            break;
        }
    }
    while(salir =='n');


    return 0;
}
