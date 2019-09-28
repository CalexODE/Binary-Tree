#include "../include/Menu.hpp"

void menu()
{
	while(true){
		int res;
		cout<<"1 - Buscar(Teste)\n2 - Inserir\n3 - Remover\n10 - fteste\n0-sair"<<endl;
		cin>>res;
		

		Arvore* arvore = new Arvore();

		switch(res)
		{
			case 0:
				break;
			case 1:
				cout<<"Buscando..."<<endl;
				arvore->busca();
				break;
			case 2:
				cout<<"Inserindo..."<<endl;
				arvore->insercao();
				break;
			case 3:
				cout<<"Removendo..."<<endl;
				arvore->remocao();
				break;
			case 10:
				fteste();
				break;
			default:
				cout<<"Opção invalida"<<endl;
		}

		if(res==0){break;}
		
	}
}