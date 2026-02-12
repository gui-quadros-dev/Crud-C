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

int q_produto = 0;
int escolha_menu_1 = 0;
int posicao;



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

int pesquisador(struct produto *lista,int tipo, int q_produtos){
    int idpesquisa = 0;
    switch (tipo)
    {
    case 1:
        printf("digite o id");
        idpesquisa = leitura_segura();
        for (int i = 0; i < q_produtos; i++)
                    {
                            if (lista[i].ID == idpesquisa)
                            {
                                int j = i;
                                return j;
                            }
                    }
            return -1;
        
                break;
    default:
    return -2;
        break;
    }
    
}

int main(){
    setlocale(LC_ALL, "Portuguese");// Arruma acentuação e pontuação
    struct produto *ptrproduto = NULL; // cria um ponteiro para o struct e o define como nulo
    while (escolha_menu_1!=4)
    {printf("\nolá! \nescolha uma das opções abaixo \n1. cadastrar produto \n2. listar produtos \n3.Buscar Produtos \n4. sair \n");
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
                        for (int i = 0; i < q_produto; i++)
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

                else if(escolha_menu_1 == 3){
                    if (q_produto>0)
                    {
                        posicao = pesquisador(ptrproduto,1,q_produto);
                        if (posicao>=0)
                        {
                            
                        
                        
                            printf("\nnome: ");
                            printf("%s",ptrproduto[posicao].nome);
                            printf("\nID: ");
                            printf("%d",ptrproduto[posicao].ID);
                            printf("\nQuantidade ");
                            printf("%d",ptrproduto[posicao].quantidade);
                            printf("\npreço: ");
                            printf("R$%.2f\n\n",ptrproduto[posicao].preco);
                        }
                        else if (posicao == -1){
                            printf("Produto não encontrado.");
                        }
                        else if(posicao == -2){
                            printf("erro fatal");
                            exit(1);
                        }

                    }
                    else{
                        printf("\nnenhum produto cadastrado\n\n");
                    }
                    
                }

                else if (escolha_menu_1 != 4){
                    printf("opcao invalida!\n");
                    }

                


        
    }

    free(ptrproduto);
}


