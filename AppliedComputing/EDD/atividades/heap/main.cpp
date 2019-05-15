#include "heap.hpp"

int main(){

    Heap<int> heap;

    int a[] = {4, 5,2,3,6,7};
    int len = sizeof(a) /sizeof(int);
    int valor;
    
	cout << "Qual o numero de posicoes da arvore?" << endl;
    cin >> valor ;
    heap.setCapacidade(valor);

    while (heap.capacidade() > heap.tamanho())
    {
        cout << "Insira um valor" << endl;
        cin >> valor ;
        heap.inserir(valor);
    }
    

    int option;
    do
    {
        cout << "------------------" << endl;
        cout << "Escolha uma das alternativas:" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover topo" << endl;
        cout << "3 - Exibir raiz" << endl;
        cout << "4 - Exibir pai" << endl;
        cout << "5 - Exibir filho a direita" << endl;
        cout << "6 - Exibir filho a esquerda" << endl;
        cout << "0 - Encerrar o programa" << endl;
        cin >> option ;

        switch (option){
            case 1:
                if(heap.capacidade() > heap.tamanho()){
                    cout << "Informe o valor" << endl;
                    cin >> valor ;
                    heap.inserir(valor);
                }else{
                    cout << "tamanho maximo atingido" << endl;
                }
            break;
            case 2:
                heap.remover();
            break;
            case 3:
                cout << "Raiz da arvore: " << heap.root() << endl;
            break;
            case 4:
                cout << "Digite a posicao do elemento que deseja exibir o elemento pai" << endl;
                cin >> valor ;
                heap.getPai(valor);
            break;
            case 5:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a direita" << endl;
                cin >> valor ;
                cout << heap.filhoDireita(valor);
            break;
            case 6:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a esquerda" << endl;
                cin >> valor ;
                heap.filhoEsquerda(valor);
            break;
        }
        
    } while (option != 0);

    while(heap.tamanho() > 0){
        heap.remover();
        cout<<"Heap Max\t"<< heap.root()<<endl;
    }

    return 0;

}