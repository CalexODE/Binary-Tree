#include "../include/Controlador.hpp"

void fteste()
{
	Node* node = new Node(13);
	cout<<node->chave<<endl;
}

Arvore::Arvore()
{
	this->raiz = NULL;
}

void Arvore::busca()
{
	
}

void Arvore::insercao()
{
	inserir(13);
}

void Arvore::remocao()
{

}

void Arvore::inserir(int chave)
{
	if (raiz == NULL)
	{
		raiz = new Node(chave);
	}else
	{
		inserirAux(raiz, chave);
	}
}

void Arvore::inserirAux(Node* node, int chave)
{
	if (node->getChave() < chave)
	{

		cout<<"A chave é maior que raiz"<<endl;

		if(node->getRchild() == NULL)
		{

			cout<<"Não há filho a direita"<<endl;

			Node* new_node = new Node(chave);
			node->setRchild(new_node);
		}
		else 
		{

			cout<<"Há filho a direita"<<endl;			

			inserirAux(node->getRchild(), chave);
		}
	}
	else if (node->getChave() > chave)
	{

		cout<<"A chave é menor que raiz"<<endl;

		if (node->getLchild() == NULL)
		{

			cout<<"Não há filho a esquerda"<<endl;

			Node* new_node = new Node(chave);
			node->setLchild(new_node);
		}
		else
		{

			cout<<"Há filho a esquerda"<<endl;

			inserirAux(node->getLchild(), chave);
		}
	}
}