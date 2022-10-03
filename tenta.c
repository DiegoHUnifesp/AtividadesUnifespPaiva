#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>

//ordena o vetor em ordem crescente
void OrdenaV(float *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        for (int j = i; j < tamanho; j++)
            if (vetor[i] > vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
}


//faz a mediana
void Mediana(float *vetor, int tamanho)
{
    
    OrdenaV(vetor, tamanho);
    
    float pos1,pos2;
    float mediana;
    
    if((int)tamanho % 2 == 0)
    {
    pos1=vetor[(tamanho/2) -1];
    pos2 = vetor[tamanho/2];
    mediana = ((float)pos1 + (float)pos2) / 2;
    
    }else
        mediana=vetor[tamanho/2];
    
    printf("mediana = %.2f\n",mediana);

}

//define os numeros maximo e minino
void NumMaxNumMin(float *vetor, int tamanho)
{
    float numMin=0, numMax=0;
    
    //seta o numMax e numMin ao valor da primeira posição do vetor
    numMax=vetor[0]; 
    numMin=vetor[0];
    //se o vetor for menor que o numMin, seta esse valor a ele, mesma coisa para o numMax, porem se for maior 
    for(int i=0;i<tamanho;i++)
    {
        if(vetor[i]<numMin)
            numMin=vetor[i];

        if(vetor[i]>numMax)
            numMax=vetor[i];
    }
    
    if(numMax == numMin)
        printf("Os numeros são iguais, portanto não tem numeros maiores ou menores\n");
    
    else
        printf("\nMenor Valor = %.2f\nMaior Valor = %.2f\n",numMin,numMax);
            
}

//faz a media e o desvio padrão
void MediaeDesvioP(float *vetor, int tamanho)
{
    float media=0, soma=0;
    float desvio=0, varia=0, desvioP=0;
    
    for(int i=0;i<tamanho;i++)
        soma += vetor[i];
    
    media = soma / tamanho;
    
    printf("Média = %.2f\n",media);
    
    //Desvio padrão
    for(int i=0;i<tamanho;i++)
    {
            desvio = vetor[i] - media;
            varia += desvio * desvio;
    }
            
    desvioP = sqrt(varia / tamanho);
    
    printf("Desvio Padrão = %g\n",desvioP);
}

void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
} 

int main()
{
    system("clear");
    float *vetor,desvio, varia, desvioP;
    float tamanho;
    int x = 1;
    
    while(x == 1)
    {
        printf("Digite o tamanho da sua série: ");
        scanf("%f%*c",&tamanho);
        flush_in();


        if(tamanho == (int)tamanho)
        {
            x = 0;
            vetor=(float*)calloc(tamanho,sizeof(int));

            for(int i=0;i<tamanho;i++)
            {
                printf("Digite o %dº número: ", i+1);
                scanf("%f%*c",&vetor[i]);
            }

            OrdenaV(vetor,tamanho);
            NumMaxNumMin(vetor,tamanho);
            Mediana(vetor, tamanho);
            MediaeDesvioP(vetor, tamanho);
            
            printf("\nDigite 1 para continuar ou 2 para sair\n\n");
            scanf("%d%*c", &x);
        }
        
        if(tamanho != (int)tamanho)
        {
            printf("Numero digitado é invalído\n");
            x=1;
        }
    }
}