#include <iostream>
#include <cassert> // para afirmaciones()

/* 
El operador de paréntesis (operador()) es un operador particularmente interesante porque permite variar tanto el tipo 
como el número de parámetros que toma.
Podemos declarar una versión de operator() que toma dos parámetros de índice enteros 
y usarlo para acceder a nuestra matriz bidimensional 
*/

class Matrix{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col); 
    double operator()(int row, int col) const; // para objetos constantes
    void operator()(); // sobrecarga sin parametros 
};

// declaracion por referencia 
double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

// declaracion por valor 
double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

// Metodo de sobrecarga sin parametros
void Matrix::operator()()
{
    // restablecer todos los elementos de la matriz a 0.0
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

int main()
{
    Matrix matrix;
    matrix(1, 2) = 4.5;
    //matrix(); // Borrar la matriz
    std::cout << matrix(1, 2) << '\n';

    return 0;
}