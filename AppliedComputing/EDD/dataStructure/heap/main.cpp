#include "heap.hpp"

int main(){

    Heap<int> heap;
    int valor;
    int opcao;
    
	cout << "Qual o numero de posicoes da arvore?" << endl;
    cin >> valor ;
    heap.setCapacidade(valor);

    while (heap.capacidade() > heap.tamanho()){
        cout << "Insira um valor" << endl;
        cin >> valor ;
        heap.inserir(valor);
    }
    

    do{
        cout << "------------------" << endl;
        cout << "Escolha uma das alternativas:" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover topo" << endl;
        cout << "3 - Exibir raiz" << endl;
        cout << "4 - Exibir pai" << endl;
        cout << "5 - Exibir posicao do filho a direita" << endl;
        cout << "6 - Exibir posicao do filho a esquerda" << endl;
        cout << "7 - Exibir filho a direita" << endl;
        cout << "8 - Exibir filho a esquerda" << endl;
        cout << "0 - Encerrar o programa" << endl;
        cin >> opcao;

        switch (opcao){
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
                cout << "Posição do elemento pai"<< heap.getPai(valor) << endl;
            
            break;
            case 5:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a direita" << endl;
                cin >> valor ;
                cout << "Posicao do elemento filho a direita: "<< heap.filhoDireita(valor) << endl;
            break;
            case 6:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a esquerda" << endl;
                cin >> valor ;
                cout << "Posicao do elemento filho a esquerda: "<< heap.filhoEsquerda(valor) << endl;
            case 7:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a direita" << endl;
                cin >> valor ;
                cout << "Elemento filho a direita: "<< heap.getFilhoDireita(valor) << endl;
            break;
            case 8:
                cout << "Digite a posicao do elemento que deseja exibir o elemento filho a esquerda" << endl;
                cin >> valor ;
                cout << "Elemento filho a esquerda: "<< heap.getFilhoEsquerda(valor) << endl;
            break;
        }
        
    } while (opcao != 0);

    return 0;

}