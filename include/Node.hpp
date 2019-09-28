#ifndef NODE_HPP
#define NODE_HPP

#include <string>
using namespace std;

class Node
{
	public:
		int chave;
		Node* Lchild;
		Node* Rchild;

		Node(int valor);

		int getChave();

		Node* getLchild();
		Node* getRchild();

		void setLchild(Node* left);
		void setRchild(Node* rigth);
};

#endif