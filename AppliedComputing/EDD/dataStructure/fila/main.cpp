#include "fila.hpp"

int main(){
    Fila <int> f;
    f.insert(2);
    f.insert(3);
    f.insert(4);
    f.insert(5);
    
    f.print();
    f.remove();
    f.print();
}