#include<stdio.h>
#include<string.h>
#include<malloc.h>
//crio uma estrutura do tipo pessoa com 2 atributos  
//nome e idade. 
typedef struct _pessoa{ 
	char* nome; 
	int idade; 
}pessoa; 
//Crio uma  estrutura do tipo No 
typedef struct _node{ 
	int var; 
	struct _node *prox; 
}node; 
/*Espaço para funçoes*/ 
void insereNoFim(node** velhaLista,node* novoNo); 
node* criaNo(int conteudo); 
pessoa* criaPessoa(char* nome, int idade); 
int excluiNo(node* velhoNo); 
void menu();
//Crio uma função CriaNo d tipo nó 
node* criaNo(int conteudo){ 
	node* novoNo;//crio uma variavel do tipo nó* 
	novoNo=(node*)malloc(sizeof(node));//aloco espaço na memoria 
	novoNo->var=conteudo;//atribuo conteudo 
	novoNo->prox=0;//inicializo com zero || NULL 
	return novoNo;//retorno o novo nó. 
} 
//Crioi uma função do tipo Pessoa 
pessoa* criaPessoa(char* nome, int idade){ 
	pessoa* novaPessoa=0;//crio uma nova pessoa do tipo pessoa* 
	novaPessoa=(pessoa*)malloc(sizeof(pessoa));//aloco espaço pra essa pessoa 
	novaPessoa->nome=(char*)malloc(sizeof(srtlen(nome+1)));//aloco espaço par o nome dessa pessoa 
	strcpy(novaPessoa->nome,nome);//faço a copia do conteudo de nome para a novapessoa apontando para o ome 
	novaPessoa->idade=idade;//atribuo a idade 
	return novaPessoa;//retono a nova pessoa 
}
 //Comentar essa função.... 
 void insereNoFim(node** velhaLista,node* novoNo){ 
	if((*velhaLista)==NULL){ 
 		*velhaLista=novoNo; 
		novoNo->prox=NULL; 
	}else 
	if((*velhaLista)->prox==NULL){ 
		(*velhaLista)->prox=novoNo; 
		novoNo->prox=NULL;		 
	}else{ 
		node* aux=(*velhaLista); 
		while(aux->prox!=NULL){ 
			aux=aux->prox; 
		aux->prox=novoNo; 
			novoNo->prox=NULL; 
		} 
	} 
} 
int excluiNo(node* velhoNo){ 
	int aux; 
	aux=velhoNo->var; 
	free(velhoNo); 
	return aux; 
} 
void pri( pessoa* pessoa  ){
	printf("nome: %s\t",pessoa->nome); 
	printf("Idade: %d\n",pessoa->idade); 
	printf("\n"); 
} 
void menu(){ 
	pessoa* p1; 
	node* lista=0; 
	int op=1,i=0; 
	while(op!=0){ 
		printf("\n======EDA======\n"); 
		printf("[1]-IMPRIMIR LISTA\n"); 
		printf("[2]-INSERIR PESSOA NA LISTA\n[0]-SAIR\n"); 
		scanf("%d",&op); 
		if(op==1){
			int aux=0;
			if(i==0){
				printf("\nLISTA VAZIA\n");
			}else{
					while(aux<i){
					pri(p1);
					aux++; 
				}
			}
			//menu(); 
		}else 
		if(op==2){
			p1=(pessoa*)malloc(sizeof(pessoa));
			p1->nome=(char*)malloc(sizeof(char)*strlen(p1->nome+1));
			printf("\nInforme o nome:");
			fflush(stdin);
			gets(p1->nome);
			printf("\nInforme a idade:");
			scanf("%d",&p1->idade);
			p1=criaPessoa(p1->nome,p1->idade); 
			lista=criaNo((void*)p1); 
			printf("%d elemento inserido\n",i+1); 
			i++;
		} 
	} 
} 
/*Função principal*/ 
int main(){ 
	menu(); 
return 0; 
}
