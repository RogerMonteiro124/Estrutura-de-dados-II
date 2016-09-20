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
	struct _pessoa** filho;
}pessoa;
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
//função principal
int main(){
	//declaro uma variavel p1 do tipo pessoa*
	pessoa* p1=0;
	//atribuo valores a ela atraves da funçãpo craPessoa
	p1=criaPessoa("roger",18);
	//faço a impressão apenas para validar as informações
	printf("%s idade=%d",p1->nome,p1->idade);
	return 0;
}
