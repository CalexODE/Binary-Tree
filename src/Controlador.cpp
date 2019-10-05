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

void Arvore::setRaiz(Node* node)
{
	this->raiz = node;
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


void Arvore::remocao()
{
	int chave;
	cout<<"Node a ser removido. Chave: ";
	cin>>chave;
	if (getRaiz() != NULL)
	{
	
		if (getRaiz()->getChave() == chave)
		{
			cout<<"O node é uma raiz"<<endl;

			Node* node_substituto = nodeSubstituto(getRaiz());

			if (node_substituto == NULL)
			{
				if (getRaiz()->getRchild() != NULL)
				{
					//setRaiz(getRaiz->getRchild());
					cout<<"Node há esquerda adicionado com raiz"<<endl;
				}
				else
				{
					delete raiz;
				}
			}
			else{
				cout<<"Node subtituto" <<node_substituto->getChave()<<endl;
				Node* node_father_deslocado = remocaoBusca(getRaiz(), node_substituto->getChave());
				cout<<"O pai do node é: "<<node_father_deslocado->getChave()<<endl;




			}
		}
		else
		{
			cout<<"Node do início "<<getRaiz()->getChave()<<endl;
			Node* node_father = remocaoBusca(getRaiz(), chave);

			cout<<"O pai do node é: "<<node_father->getChave()<<endl;

			if (node_father->getLchild() != NULL)
			{
				cout<<"O filho L do node é: "<<node_father->getLchild()->getChave()<<endl;
			}
			else {
				cout<<"Filho L null"<<endl;
			}

			if (node_father->getRchild() != NULL)
			{
				cout<<"O filho R do node é: "<<node_father->getRchild()->getChave()<<endl;
			}
			else {
				cout<<"Filho R null"<<endl;
			}


			Node* node_r;
			if (node_father->getLchild()->getChave() == chave)
			{
				node_r = node_father->getLchild();
			}
			else{
				node_r = node_father->getRchild();
			}

			cout<<"Node a ser removido: "<<node_r->getChave()<<endl;
			Node* node_substituto = nodeSubstituto(node_r);
			//cout<<"Substituto: "<<node_substituto->getChave()<<endl;

			
		}
	}
}

Node* nodeSubstituto(Node* node)
{
	cout<<"Node de entrada: "<<node->getChave()<<endl;

	if (node->getLchild() == NULL)
	{
		cout<<"Node null poraqui"<<endl;
		cout<<"Node null"<<endl;
		return NULL;
	}
	else{

		return nodeSubstitutoAux(node->getLchild());
	}
}

Node* nodeSubstitutoAux(Node* node)
{
	cout<<"nodeSubstitutoAux: "<<node->getChave()<<endl;
	if (node->getRchild() != NULL)
	{
		node = nodeSubstitutoAux(node->getRchild());
	}
	else{

		return node;
	}
}

Node* remocaoBusca(Node* node, int chave)
{
	if (node->getChave() > chave)
	{
		cout<<"O node é menor que a raiz"<<endl;
		if (node->getLchild() != NULL)
		{
			if (node->getLchild()->getChave() == chave)
			{
				cout<<"node encontrado!"<<endl;
				cout<<node->getChave()<<endl;
				return node;
			}
			else
			{
				node = remocaoBusca(node->getLchild(), chave);
			}
		}
	}
	else if (node->getChave() < chave)
	{
		cout<<"O node é maior que a raiz"<<endl;
		if (node->getRchild() != NULL)
		{

			if (node->getRchild()->getChave() == chave)
			{
				cout<<"node encontrado!"<<endl;
				cout<<node->getChave()<<endl;
				return node;
			}
			else
			{
				node = remocaoBusca(node->getRchild(), chave);
			}
		}
	}
	return node;

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

Node* Arvore::buscarN_esimo()
{
	int n;
	cout<<"Buscar n-esimo: "<<endl;
	cin>>n;

	Node* n_esimo = buscarN_esimoAux(raiz, n);

	cout<<"N-ésimo: "<<n_esimo->getChave()<<endl;

}

Node* buscarN_esimoAux(Node* node, int n)
{
	cout<<"Node Atual: "<<node->getChave()<<" |  n: "<<n<<endl;
	if (n == 0)
	{
		return node;
	}
	else{
		if (node != NULL)
		{

			cout<<"antes do if(node->getLchild())"<<endl;
			if (node->getLchild() != NULL)
			{

				cout<<"buscarN_esimoAux(node->getLchild(), n)"<<endl;

				buscarN_esimoAux(node->getLchild(), n);

			}

			cout<<"antes do getChave()"<<endl;
			cout<<node->getChave()<<endl;
			cout<<"Node Atual: "<<node->getChave()<<" |  n: "<<n<<endl;
			n--;
			if (n==0)
			{
				return node;
			}

			if (node->getRchild() != NULL)
			{

				cout<<"buscarN_esimoAux(node->getRchild(), n)"<<endl;
				buscarN_esimoAux(node->getRchild(), n);


			}
		}
	}
	return node;
}