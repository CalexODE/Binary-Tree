#include "../include/Menu.hpp"

void menu()
{
	Arvore* arvore = new Arvore();
	
	while(true){
		int res;
		cout<<"1 - Buscar(Teste)\n2 - Inserir\n3 - Remover\n4 - Percorre\n5 - Bucar N-ésimo\n10 - fteste\n0-sair"<<endl;
		cin>>res;
		


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
			case 4:
				cout<<"Mostrando..."<<endl;
				arvore->percorreSimetrica();
				break;
			case 5:
				cout<<"Buscar N-esimo"<<endl;
				arvore->buscarN_esimo();
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