
#ifndef RETO2_VECTORPILAS_H
#define RETO2_VECTORPILAS_H

#include <vector>

using namespace std;

template<typename T>
/**
 * @brief Clase que implementa un vector de pilas.
 *
 * @details se utiliza un vector de tamaño tam con un número k de pilas. Utilizamos un array de bases para almacenar el
 * índice del inicio de cada stack y tambien almacenamos los topes en otro array. Las bases pueden comenzar  en cualquier
 * posición, por ejemplo en la posición tam/numpila siendo numpila el índice de la base.
 *
 * @param v el vector en el que están implementadas las pilas
 * @param tam el tamaño del vector
 * @param k el número de pilas
 * @param base el vector que contiene los índices de las bases de cada pila
 * @param top el vector que contiene los índices de los topes de cada pila
 */
class VectorPilas {

    vector<T> v;
    int tam;
    int k;
    vector<int> base;
    vector<int> top;
public:
    /**
     * @brief constructor de la clase VectorPilas
     * @details inicializa el vector con la capacidad indicada, y k con el número de pilas. Además se rellenan los
     * vectores base con las posiciones de inicio de cada una de las pilas y top con top[n]=base[n]-1
     * @pre 0<num_pilas<=capacidad (si num_pilas==capacidad las pilas serán de solo un elemento)
     */
    VectorPilas(int capacidad, int num_pilas)
    /**
     * @brief comprueba si la pila n está llena
     * @details Una pila del vector estará llena sii base[n+1]==tope[n]-1, es decir, cuando no quepa ningún elemento más.
     * @param n pila a comprobar
     * @pre 0<=n<k
     * @return ase[n+1]==tope[n]-1;
     */
    bool llena(int n) const;
    /**
     * @brief comprueba si la pila n está vacía
     * @details una pila está vacía sii base[n]==top[n]-1
     * @param n el número de la pila
     * @pre 0<=n<k
     * @return base[n]==top[n]-1;
     */
    bool vacia(int n) const;
    /**
     * @brief inserta un elemento en el tope del stack n
     * @details si !llena(n) entonces inserta el elemento en la posición top[n], y luego incrementa top[n].
     * @param elem el elemento a insertar en la pila
     * @param n la pila en la que insertar el elemento
     * @pre 0<=n<k
     */
    void push (T elem, int n);
    /**
     * @brief saca el elemento que está en el tope de la pila n
     * @details si !vacia(n) entonces devuelve el elemento en top[n] y lo decrementa
     * @param n la pila de la que sacar el elemento
     * @pre 0<=n<k
     * @return el elemento en el tope de la pila n
     */
    T pop (int n);
    /**
     * @brief mira el elemento en el tope de la pila n
     * @details si !vacia(n) entonces devuelve una referencia constante a top[n]
     * @param n la pila en la que mirar el tope
     * @pre 0<=n<k
     * @return una referencia constante al elemento en el tope de la pila n
     */
    const T & top(int n) const;
};


#endif