/*
Implementar um sistema que
contenha uma estrutura do tipo pessoa,
criar uma função criaPessoa, uma funçao insereFilho,
e uma função mataPessoa
<!--	Roger Monteiro	-->
Date: 20/09/2016
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
//crio um aestrutura do tipo pessoa
typedef struct _pessoa{
	//declaro as variaves dessa estrutura
	char* nome;
	int idade;
	int nfilhos;
	struct _pessoa** filho;
}pessoa;
/*função usada para inserir filho nos pais, não consegui fazer funcionar em
uma unica função entaõ fiz uma pro pai e outra pra mae*/
void insereFilhoPai(pessoa* pai,pessoa* filho){
	if(pai->filho!=0){
		pai->nfilhos++;
		pai->filho=(pessoa**)realloc(pai->filho,sizeof(pessoa)*pai->nfilhos+1);
	}
	else{
		pai->nfilhos++;
		pai->filho=(pessoa**)malloc(sizeof(pessoa*));
	}
	pai->filho=filho;
}
void insereFilhoMae(pessoa* mae,pessoa* filho){
if(mae->filho!=0){
		mae->filho=(pessoa**)realloc(mae->filho,sizeof(pessoa)*mae->nfilhos+1);
		mae->nfilhos++;
	}
	else{
		mae->filho=(pessoa**)malloc(sizeof(pessoa*));
		mae->nfilhos++;
	}
mae->filho=filho;
}
//crio uma função mataPEssoa do tipo void, pois não precisa retornar nada
//preceisa apenas eliminar o conteudo das variaves.
void mataPessoa(pessoa* velhaPessoa){
	free(velhaPessoa->nome);
	free(velhaPessoa);
}
//crio uma função criapessoa do tipo pessoa*
pessoa* criaPessoa(char* nome,int idade){
	//crio uma variavel do tipo pessoa*
	pessoa* novaPessoa=0;
	//faço alocação dinamica para está variavel
	novaPessoa=(pessoa*)malloc(sizeof(pessoa));
	//faço alocação dinamica pera está variavel quando ela aponta para nome
	novaPessoa->nome=(char*)malloc(sizeof(char)*(strlen(nome+1)));
	//faço a copia dos dados inseridos em nome para a novaPessoa apontando pra nome
	strcpy(novaPessoa->nome,nome);
	//atribuo  o valor inserido em idade para novaPesso apontando para idade
	novaPessoa->idade=idade;
	//retorno a variavel novapessoa
	return novaPessoa;
}
/*Função para fazer a impressao final*/
void imprime(pessoa* pai,pessoa*mae){
	//se o pai tiver filhos imprimo o nome do pai e o nome do filho
	if(pai->nfilhos!=0){
		printf("Nome do pai=%s\n nome do filho=%s\n\n",pai->nome,pai->filho[pai->nfilhos-1]);
	}else{//senao imprimo apenas o nome do pai
		printf("Nome do pai=%s\nfilho=Desconhecido\n\n",pai->nome);
	}//a mesma coisa para a mae
	if(mae->nfilhos!=0){
		printf("Nome da mae=%s\nnome do filho=%s\n\n",mae->nome,mae->filho[mae->nfilhos-1]);
	}else{
		printf("Nome da mae=%s\nfilho=Desconhecido\n\n",mae->nome);
	}	
}
//função principal
int main(){
	//declaro uma variavel p1 do tipo pessoa*
	pessoa* pai=0;
	pessoa* mae=0;
	//atribuo valores a ela atraves da funçãpo craPessoa
	pai=criaPessoa("Luiz",38);
	mae=criaPessoa("Carla",48);
	//faço a impressão antes de inserir filho para que seja impresso apenas o
	//nome do pai segundo a linha 71
	imprime(pai,mae);
	//agora faço a inserção dos filhos tanto pra mae quanto pro pai
	printf("\n<-- Inserindo Filho -->\n");
	insereFilhoPai(pai,criaPessoa("pedro",10));
	insereFilhoMae(mae,criaPessoa("pedro",10));
	//aguardo o pressionamento de uma tecla
	getch();
	//agora o pai e a mae já tem filhos então eles caem na condição da linha 68 e 73 
	//nessa impressao os filhos já aparecem
	imprime(pai,mae);
	//aqui mato o filho do pai e logo abaixo mato o pai :D kkk ( canta pra subir)
	mataPessoa(pai->filho);
	mataPessoa(pai);
	//aqui mato o filho da mae e logo abaixo mato a mae :D kkk ( canta pra subir tambem kk)
	mataPessoa(mae->filho);
	mataPessoa(mae);
	printf("\nGERAL CANTOU PRA SUBIR KKK\n");	
	return 0;
}
