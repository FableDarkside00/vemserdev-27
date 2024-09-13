#include <stdio.h>
#include <stdlib.h>

int* calcPessoa()
{
    int *list_pessoa = (int*)malloc(3*sizeof(int));
    if (list_pessoa == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    
    int num_pessoa;
    int num_homem;
    int num_mulher;

    printf("\nQuantas pessoas irao a festa?(8 - 20): ");
    scanf("%d", &num_pessoa);
    
    //Check minimal quantity
    if (num_pessoa < 8 || num_pessoa > 20){
        free(list_pessoa);
        return NULL;
    
    };
    printf("\nQuantos sao homens?: ");
    scanf("%d", &num_homem);
    
    if (num_homem > num_pessoa)
    {
        free(list_pessoa);
        return NULL;
    }

    num_mulher = num_pessoa - num_homem;
    list_pessoa[0] = num_pessoa;
    list_pessoa[1] = num_homem;
    list_pessoa[2] = num_mulher;
    
    return list_pessoa;
}

void calcCarne(int* num_pessoa)
{    
    //0 - All people
    //1 - Men
    //2 - Women

    int qnt_carne_h = num_pessoa[1] * 500;
    int qnt_carne_m = num_pessoa[2] * 300;

    int qnt_queijo_h = num_pessoa[1] * 100;
    int qnt_queijo_m = num_pessoa[2] * 200;

    int qnt_linguica = num_pessoa[0] * 100;
  
    int qnt_cerveja_h = num_pessoa[1] * 4;
    int qnt_cerveja_m = num_pessoa[2] * 2;

    int list_qnt[7] = {qnt_carne_h, qnt_carne_m, qnt_queijo_h, qnt_queijo_m, qnt_linguica, qnt_cerveja_h, qnt_cerveja_m};
    int size_qnt = (sizeof(list_qnt) / sizeof(list_qnt[0]));
    printf("\nA quantidade respectiva para homens e mulheres de carne, queijo, linguica e cerveja e:\n");
    for (int i = 0; i < size_qnt; i++)
    {
        printf("%d\n", list_qnt[i]);
    }
}

int main()
{
    printf("\nBem vindo ao sistema de organizacao de churrascos!");
    printf("\nMede a quantidade respectiva para homens e mulheres de carne, queijo, linguica e cerveja em gramas e por numero de garrafas\n");
    int* num_pessoa = calcPessoa();
    int question;
    if (num_pessoa == NULL) {
        printf("\nQuantidade invalida!");
        return main();
    }
    calcCarne(num_pessoa);
    free(num_pessoa);

    printf("\nDeseja repetir?(1 - Repetir | 0 - Sair): ");
    scanf("%d", &question);
    if (question == 1) return main();
    exit(0);
    return 0;
}
