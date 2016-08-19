#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
 struct ficha{
       char rua[50];
       int numero;
       char bairro[50];
       int cep;
       char cidade[50];
   };
typedef struct dados{
	   char nome[50];
       char email[30];
       int telefone;
       struct ficha dados;
       struct dados *proximo;
}dados;
      
void inserepessoa(struct dados **inicio, int *sinal);
void mostrapessoa(struct dados *lista,int *sinal);
void mostratudo(struct dados *lista,int *sinal);
void liberalista(struct dados **lista);

 
int main()
{
    struct dados *li=NULL;
    int opt;
    int ok;
    opt=1; 
    while(opt!=4)
	{
          system("cls");
          printf("\tAGENDA DE TELEFONES\n\n");
          printf("\t1.Inserir pessoa\n");
          printf("\t2.Mostrar pessoas(nome,telefone,email)\n");
          printf("\t3.Mostrar pessoas(todos os dados)\n");
          printf("\t4.Sair\n\n");
          printf("\t");scanf("%d",&opt);
          switch(opt)
		   {
             case 1 : inserepessoa(&li,&ok);if(ok==0) printf("\t\nErro na alocacao de memoria..."); break;              
             case 2 : mostrapessoa(li,&ok);if(ok==0)
		                                        {
		                                           system("cls");
		                                           printf("\tMOSTRAR CONTATOS(nome,telefone,email)\n\n");
		                                           printf("\tLista Vazia!!");
												   printf("\n\n"); 
									              }
									              break;
             case 3 : mostratudo(li,&ok);if(ok==0)
		                                        {
		                                           system("cls");
		                                           printf("\tMOSTRAR CONTATOS\n\n");
		                                           printf("\tLista Vazia!!");
												   printf("\n\n"); 
									        		} 
													break;
             case 4:printf("\tPrograma encerrado...");
			        printf("\n\n");
					 break;
		     default: printf("\t\nOpcao invalida");
                     printf("\n\n");
            }
            printf("\n\t");
            system("pause");
    }
    liberalista(&li);
}
     
     
void inserepessoa(struct dados **inicio, int *sinal)
{
     char op;
     struct dados *pe,*aux,*ant;
     op='s';
     while(op=='s' || op=='S')
        {
              pe=(struct dados*) malloc ( sizeof(struct dados));
              if(pe)
                {
                    system("cls");
                    printf("\tNOVO CONTATO\n\n");
                    printf("\tNome: ");fflush(stdin); gets(pe->nome);
                    printf("\tEmail: ");fflush(stdin);gets(pe->email);
                    printf("\tTelefone: "); scanf("%d",&pe->telefone);
                    printf("\tENDERECO\n");
                    printf("\tRua: "); fflush(stdin); gets(pe->dados.rua);
                    printf("\tNumero: ");scanf("%d",&pe->dados.numero);
                    printf("\tBairro: "); fflush(stdin);gets(pe->dados.bairro);
                    printf("\tCEP: "); scanf("%d",&pe->dados.cep);
                    printf("\tCidade: ");fflush(stdin); gets(pe->dados.cidade);
                    printf("\n");
                    printf("\tDeseja cadastrar mais pessoas? S/N:  ");
                    fflush(stdin);scanf("%c",&op);
                    if(*inicio==NULL)
                    {
                        aux=*inicio;
                        *inicio=pe;
                        pe->proximo=NULL;
                        *sinal=1;
                        
                    }
                    else
                    {
                    	aux=*inicio;
                        while(aux!=NULL){
                        	ant=aux;
                        	aux=aux->proximo;
                        }
                       	pe->proximo=ant->proximo;
                        ant->proximo=pe;
						*sinal =1;
                         
                    }
                }
               else
               {
                   *sinal=0;
                   
                   }
           
        }
      
}
void mostrapessoa(struct dados *lista,int *sinal)
{
	struct dados *aux;
	int cont;
	aux=lista;
	cont=0;
    if(aux==NULL)
	{
		*sinal=0;
	}
	else
	{
	  system("cls");
	  printf("\tMOSTRAR CONTATOS(nome,tel e email)\n\n");
      while(aux!=NULL)
      {
      	cont++;
      	printf("\n%d CONTATO\n",cont);
    	printf("\nNome: %s",aux->nome);
    	printf("\nTelefone: %d",aux->telefone);
    	printf("\nEmail:%s",aux->email);
    	printf("\n");
        aux=aux->proximo;
        }
     *sinal =1;
     printf("\n");
     system("pause");
    }
}

void mostratudo(struct dados *lista,int *sinal)
{
	struct dados *aux;
	int cont;
    aux=lista;
    cont=0;
    if(aux==NULL)
	{
		*sinal=0;
	}
	else
	{
	  system("cls");
	  printf("\tMOSTRAR CONTATOS(todos os dados)\n\n");
	  for(aux=lista;aux!=NULL;aux=aux->proximo)
      {
      	cont++;
      	printf("\t%i CONTATO",cont);
    	printf("\nNome: %s",aux->nome);
    	printf("\nTelefone: %d",aux->telefone);
    	printf("\nEmail: %s",aux->email);
    	printf("\nENDERECO");
        printf("\nRua: %s ",aux->dados.rua);
        printf("\nNumero: %d",aux->dados.numero);
        printf("\nBairro: %s",aux->dados.bairro);
        printf("\nCEP: %d",aux->dados.cep);
        printf("\nCidade: %s",aux->dados.cidade);
    	printf("\n\n");
     }
     *sinal =1;
     printf("\n");
     system("pause");
    }
}     
 
void liberalista(struct dados **lista)
{
	struct dados *aux,*p;
	aux=*lista;
	while(aux!=NULL)
	{
		p=aux;
		aux=aux->proximo;
		free(p);
	}
}
