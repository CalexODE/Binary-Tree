#include "Node.hpp"
//@TODO aprenda a usar ponteiros inteligentes
#include <memory>

Node::Node(int chave)
{
	this->chave = chave;
	Lchild = NULL;
	Rchild = NULL;
}

int Node::getChave()
{
	return this->chave;
}

Node* Node::getLchild()
{
	return this->Lchild;
}

Node* Node::getRchild()
{
	return this->Rchild;
}

void Node::setLchild(Node* left)
{
	this->Lchild = left;
}
void Node::setRchild(Node* rigth)
{
	this->Rchild = rigth;
}