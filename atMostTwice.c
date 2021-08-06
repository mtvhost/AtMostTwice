#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long Integer;

Integer powInteger(Integer n, Integer r)
{
    Integer result = 1, i = 0;
    for(i=1; i<=r; i++)
    {
        result = result * n;
    }
    return result;
}

Integer sizeOfInteger(Integer number)
{
    Integer cont = 0, ten = 10, zero = 0;
    for(cont = zero; number>zero; cont++)
    {
        number = number/ten;
    }
    return cont;
}

Integer atMostTwice(Integer number)
{
    Integer i=0, j=0, k=0, w=0;
    Integer sz = 0, aj = 0, ak = 0, nj = 0, nk = 0, flag = 0, test = 1, aux = 0, auxd = 0;
    for(i=number; i>0; i--)
    {
        sz = sizeOfInteger(i);
        aj = i;
        test = 1;
        for(j=sz-1; j>=0; j--)
        {
            nj = aj / powInteger(10, j);
            aj = aj - (nj * powInteger(10, j));
            ak = i;
            flag = 0;
            for(k=sz-1; k>=0; k--)
            {
                nk = ak / powInteger(10, k);
                ak = ak - (nk * powInteger(10, k));
                if((nj == nk) && (j != k))
                {
                    flag++;
                }
                if(flag>1)
                {
                    test = 0;
                    break;
                }
            }
            if(flag>1)
            {
                aux = i;
                for(w=sz-1; w>=k; w--)
                {
                    auxd = aux / powInteger(10, w);
                    aux = aux - (auxd * powInteger(10, w));
                }
                i = i - aux;
                test = 0;
                break;
            }
        }
        if(test == 1)
        {
            break;
        }
    }
    return i;
}

int main()
{
    Integer number = (Integer) 0;
    char * nome = malloc(sizeof(char)*1024);
    char * nomeInput = malloc(sizeof(char)*1024);
    char * nomeSolution = malloc(sizeof(char)*1024);
    strcpy(nomeInput, "A\\");
    strcpy(nomeSolution, "A\\");
    FILE * input;
    FILE * solution;
    printf("At Most Twice\n");
    printf("Digite o nome do arquivo da pasta A (sem extensao):");
    gets(nome);
    strcat(nomeInput, nome);
    strcat(nomeInput, ".in");
    strcat(nomeSolution, nome);
    strcat(nomeSolution, ".sol");
    input = fopen(nomeInput, "r");
    solution = fopen(nomeSolution, "w+");
    if(input != NULL)
    {
        printf("Executando...\n");
        fscanf(input, "%lld", &number);
        if((number >= 1) && (number <= powInteger(10, 18)))
        {
            fprintf(solution, "%lld\n", atMostTwice(number));
            printf("Pronto\n");
            printf("Abra solution.sol");
        }
        else
        {
            printf("Erro, 1 <= input <= 10^18");
        }
    }
    else
    {
        printf("Arquivo .in não encontrado na pasta A");
    }
    fclose(solution);
    fclose(input);
    free(nomeSolution);
    free(nomeInput);
    free(nome);
    return 0;
}
