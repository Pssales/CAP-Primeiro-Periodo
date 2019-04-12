// MyCode
#include "point.hpp"
 
// C++ Standard Library
#include <cmath>
 
Point::Point(double x, double y)
    : x_(x), y_(y)
{
}
 
double Point::x() const
{
    return x_;
}
 
double Point::y() const
{
    return y_;
} 
 
void Point::translate(double x, double y)
{
    x_ += x;
    y_ += y;
}
 
double Point::distance(const Point& other) const
{
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;
 
    double d = std::sqrt(dx*dx  + dy*dy);
    return d;
}


  do
    {
        std::string option;
        std::cout << "------------------" << std::endl;
        std::cout << "Escolha uma das opções:" << std::endl;
        std::cout << "1 - Retornar o primeiro elemento" << std::endl;
        std::cout << "2 - Retorna o último elemento " << std::endl;
        std::cout << "3 - Inserir Valor no Início" << std::endl;
        std::cout << "4 - Inserir Valor no Final" << std::endl;
        std::cout << "5 - Remover o primeiro elemento " << std::endl;
        std::cout << "6 - Remover o último elemento" << std::endl;
        std::cout << "0 - Encerar o programa" << std::endl;
        std::cin >> option ;

        
    } while (/* condition */);
    
