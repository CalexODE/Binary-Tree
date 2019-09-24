#include "../include/Menu.hpp"

void menu()
{
	while(true){
		int res;
		cout<<"1 - Inserir\n2 - remover\n0-sair"<<endl;
		cin>>res;
		switch(res)
		{
			case 0:
				break;
			case 1:
				cout<<"Inserindo..."<<endl;
				break;
			case 2:
				cout<<"Removendo..."<<endl;
				break;
			default:
				cout<<"Opção invalida"<<endl;
		}

		if(res==0){break;}
		
	}
}