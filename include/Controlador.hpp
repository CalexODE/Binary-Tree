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
	
	void busca();
	void insercao();
	void remocao();

	void inserir(int chave);
	void inserirAux(Node* node, int chave);

	void remover(int chave);

	void percorreSimetrica();
};

void percorreSimetricaAux(Node* no);