#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Node.hpp"
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

	void preOrder(Node* n);
	void percorreSimetrica();
	void postOrder(Node* n);

	Node* buscarN_esimo();
};

Node* remocaoBusca(Node* node, int chave);

Node* nodeSubstituto(Node* node);
Node* nodeSubstitutoAux(Node* node);

Node* buscaAux(Node* node, int chave);

void percorreSimetricaAux(Node* no);


Node* buscarN_esimoAux(Node* node, int n);

#endif