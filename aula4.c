#include <stdio.h>
#include <stdlib.h>




int main()
{
    int userId, senha;
    int logged = 0;

    printf("Digite seu numero de usuario: ");
    scanf("%d", &userId);
    printf("Digite sua senha: ");
    scanf("%d", &senha);

    logged = loginFunc(userId, senha);

    if (logged != 0)
    {
      printf("Sai fora canalha");
      return 1;
    }else
    {
        char op;
        float m1, m2;

        system("clear");
        printf("Menu de opcoes");
        printf("\n1 Quadrado");
        printf("\n2 Retangulo");
        printf("\n3 Triangulo");
        printf("\n4 Encerrar");
        printf("\nSua Opcao: ");
        scanf("%d", &op);

        printf("\nDigite o lado 1: ");
        scanf("%f", m1);
        printf("\nDigite o lado 2: ");
        scanf("%f", m2);

        calcFigures(m1, m2, op);
    }
    
    return 0;
}


int loginFunc(int senha, int userId)
{
    char sn;
    int verify;
    if (userId != 20091 && senha != 123 )
    {
        return 1;
    }
    printf("\nSeja bem vindo ao sistema");
    printf("Deseja continuar? (S/N)");
    sn = getchar();
    verify = (65 + sn % 65 % 32 == 'S') ? 0 : 1;
    
    return verify; 
}

int calcFigures(float m1, float m2, int op)
{

    if (op == 1)
    {
        square(m1, m2);
    }
    else if (op == 2)
    {
        rectangle(m1, m2);

    }else if (op == 3)
    {
        triangle(m1, m2);
    }else if (op == 4)
    {
        return 0;
    }else
    {
        printf("Valor nao existe");
        return 1;
    }
    
    return 0;
}


void square(float m1, float m2)
{
    float perim, area;

    perim = m1 * 4;
    area = m1 * m2;
    
    printf("\n\n Perimetro: %f", perim);
    printf("\n\n Area: %f", area);
}


void rectangle(float m1, float m2)
{
    float perim, area;

    perim = m1 * 2 + m2 * 2;
    area = m1 * m2;
    printf("\n\n Perimetro: %f", perim);
    printf("\n\n Area: %f", area);
}

void triangle(float m1, float m2)
{
    float perim, area;
    
}