#include "../include/Node.hpp"

#include <iostream>
using namespace std;

void fteste();


/* * * * * *   * * * * * */
class Arvore
{
private:

	Node* raiz;

public:

	Arvore();
	Node* getRaiz();
	void setRaiz(Node* node);
	
	void busca();
	void insercao();
	void remocao();

	void inserir(int chave);
	void inserirAux(Node* node, int chave);


	void percorreSimetrica();
};

Node* remocaoBusca(Node* node, int chave);

Node* nodeSubstituto(Node* node);
Node* nodeSubstitutoAux(Node* node);

Node* buscaAux(Node* node, int chave);

void percorreSimetricaAux(Node* no);
