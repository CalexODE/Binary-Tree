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

Node* Arvore::getRaiz()
{
	return this->raiz;
}

void Arvore::busca()
{
	int chave;
	cout<<"Chave: ";
	cin>>chave;
	Node* node = buscaAux(getRaiz(), chave);
	if (node != NULL)
	{
		cout<<"Node encontrado! chave: "<< node->getChave()<<endl;
	}
	else{
		cout<<"nada encontrado"<<endl;
	}
}

void Arvore::insercao()
{
	inserir(13);
	inserir(10);
	inserir(15);
	inserir(14);
	inserir(8);
	inserir(11);
}

void Arvore::remocao()
{

}

void Arvore::inserir(int chave)
{
	if (raiz == NULL)
	{
		raiz = new Node(chave);
		cout<<"Node a ser adicionado: " << raiz->getChave()<<endl;
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
			cout<<"Node a ser adicionado: " << new_node->getChave()<<endl;
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
			cout<<"Node a ser adicionado: " << new_node->getChave()<<endl;
			node->setLchild(new_node);
		}
		else
		{

			cout<<"Há filho a esquerda"<<endl;

			inserirAux(node->getLchild(), chave);
		}
	}
}


void Arvore::remover(int chave)
{

}
void Arvore::percorreSimetrica()
{
	cout<<"antes de chamar"<<endl;

	percorreSimetricaAux(getRaiz());
	
	cout<<"depois de chamar"<<endl;
}

void percorreSimetricaAux(Node* no){
	
	if (no != NULL)
	{


		cout<<"antes do if(no->getLchild())"<<endl;
		if (no->getLchild() != NULL)
		{

			cout<<"antes do percorreSimetricaAux(no->getLchild())"<<endl;

			percorreSimetricaAux(no->getLchild());

		}

		cout<<"antes do getChave()"<<endl;
		cout<<no->getChave()<<endl;

		if (no->getRchild()!=NULL)
		{

			cout<<"antes do percorreSimetricaAux(no->getRchild())"<<endl;
			percorreSimetricaAux(no->getRchild());


		}
	}
}

Node* buscaAux(Node* node, int chave){
	
	if (node != NULL)
	{

		if (chave == node->getChave())
		
		{
			cout<<"Chave encontrada"<<endl;
			return node;
		}

		else if (chave < node->getChave())
		{
			cout<<"antes do if(node->getLchild())"<<endl;
			if (node->getLchild() != NULL)
			{
				cout<<"antes do busca(node->getLchild())"<<endl;
				node = buscaAux(node->getLchild(), chave);
			}
			else {
				cout<<"Chave não encontrada"<<endl;
				node = NULL;
			}
		}

		else if (chave > node->getChave())
		{
			cout<<"antes do if(node->getLchild())"<<endl;
			if (node->getRchild()!=NULL)
			{
				cout<<"antes do busca(node->getRchild())"<<endl;
				node = buscaAux(node->getRchild(), chave);
			}
			else{
				cout<<"Chave não encontrada"<<endl;
				node = NULL;
			}
		}
	}
	cout<<"Se passou aqui ta errado"<<endl;
	return node;
}