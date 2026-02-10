#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct produto
{
    int ID;
    char nome[50];
    int quantidade;
    float preco;
};

int i;
int q_produto = 0;
int escolha_menu_1 = 0;

int leitura_segura(){
    char buffer[20];
    int isnum;
    char extra;
while(1){
    if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
        if(sscanf(buffer, "%d %c" , &isnum, &extra) == 1){ // sscanf retorna 1 apenas se conseguir ler só o %d, se ler %c também, há lixo na entrada assim retornando 2

            return isnum;
                                              }
                                                }
    printf("entrada invalida! , insira um numero.\n\n");
        }           }

float leitura_float_segura(){
    char buffer[30];
    float valor;
    char extra;

    while(1){
        if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
            if(sscanf(buffer, "%f %c", &valor, &extra) == 1){
                return valor;
            }
        }
        printf("entrada invalida! insira um numero decimal valido.\n");
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese");// Arruma acentuação e pontuação
    struct produto *ptrproduto = NULL; // cria um ponteiro para o struct e o define como nulo
    while (escolha_menu_1!=3)
    {printf("\nolá! \nescolha uma das opções abaixo \n1. cadastrar produto \n2. listar produtos \n3. sair\n");
        escolha_menu_1 = leitura_segura();
        
                if (escolha_menu_1 == 1){
                    struct produto *verify = realloc(ptrproduto, (q_produto +1) * sizeof(struct produto));
                        if (verify == NULL)
                        {
                            printf("\n erro de memória.");
                            exit(1);
                        }
                        ptrproduto = verify;
                        
                    printf("\n\nvamos cadastrar um produto!\n\nPor favor coloque o nome do produto\n\n");
                    //getchar();
                    if(fgets(ptrproduto[q_produto].nome ,sizeof(ptrproduto[q_produto].nome), stdin) == NULL){
                        printf("\n erro de memória.");
                        exit(1);
                    }
                    ptrproduto[q_produto].nome[strcspn(ptrproduto[q_produto].nome, "\n")] = '\0';
                    //getchar();
                    //scanf("%49[^\n]" , ptrproduto[q_produto].nome);
                    printf("ID:");
                    //scanf("%d", &ptrproduto[q_produto].ID);
                    ptrproduto[q_produto].ID = leitura_segura();
                    printf("quantidade:");
                    //scanf("%d", &ptrproduto[q_produto].quantidade);
                    ptrproduto[q_produto].quantidade = leitura_segura();
                    printf("Preço:");
                    //scanf("%f", &ptrproduto[q_produto].preco);
                    ptrproduto[q_produto].preco = leitura_float_segura();
                    q_produto++;
                    printf("\n\nProduto cadastrado com sucesso!");
                    

                }
            


                else if (escolha_menu_1 == 2){
                    if(q_produto > 0){
                        for (i = 0; i < q_produto; i++)
                        {
                            printf("---produto %d---",i+1 );
                            printf("\nnome: ");
                            printf("%s",ptrproduto[i].nome);
                            printf("\nID: ");
                            printf("%d",ptrproduto[i].ID);
                            printf("\nQuantidade ");
                            printf("%d",ptrproduto[i].quantidade);
                            printf("\npreço: ");
                            printf("R$%.2f\n\n",ptrproduto[i].preco);
                        }}
                    else{
                        printf("\nnenhum produto cadastrado\n\n");
                    }
                    
                }
                else if (escolha_menu_1 != 3){
                    printf("opcao invalida!\n");
                    }

                


        
    }
    free(ptrproduto);
}


