
#ifndef RETO2_PILADOBLE_H
#define RETO2_PILADOBLE_H

#include <vector>
using namespace std;

template <typename T>

/**
 * @brief Clase que implementa una pila doble a partir de un vector.
 *
 * @details Se trata de dos pilas que crecen en un bloque contiguo compartido de memoria (el propio vector) de tamaño
 * fijo. Cada pila comienza desde un extremo del vector y crecen hacia dentro siempre y cuando el vector no esté
 * completo.
 *
 * @param v el vector en el que están implementadas las pilas
 * @param tam el tamaño del vector
 * @param top1 el índice del tope de la pila 1
 * @param top0 el índice del tope de la pila 0
 */
class PilaDoble {

private:
    vector<T> v;
    int tam;

    int top1;
    int top0;

public:
    /**
     * @brief constructor de la clase PilaDoble dado el tamaño de su vector.
     * @details se hace un resize al vector con la capacidad indicada, y se inicializa top1=-1, top0=tam=capacidad
     *
     * @param tamaño tamaño del vector sobre el que están las pilas
     * @pre capacidad > 0
     */
    PilaDoble(int capacidad);

    /**
     * @brief comprueba si el vector está lleno.
     *
     * @details se comprueba si el vector está lleno sii el siguiente elemento al tope de la pila 1 es el elemento
     * anterior al tope de la pila 0 (ya que eso significa que las dos pilas se han encontrado en el vector y no queda
     * espacio entre ellas)
     *
     * @return top1==top0-1
     */
    bool lleno() const;

    /**
     * @brief comprueba si la pila numpila está vacía.
     *
     * @details devuelve true si la posición del tope de la pila numpila es la posición inicial con la que se construye
     * (-1 si numpila==1 o tam si numpila==0)
     *
     * @return numpila==1 && top1==-1 || numpila==0 && top0==tam;
     * @pre numpila == 0 || numpila == 1
     */
    bool vacio(int numpila) const;

    /**
     * @brief pone el elemento indicado en el tope de una de las pilas.
     * @details si !lleno(); entonces inserta el elemento en el vector en la posición top de la pila numpila (es decir,
     * en top1 o en top0) además si el elemento se ha insertado en la pila 1 se incrementa top1 y si es en la pila 0 se
     * decrementa top0.
     *
     * @param elem elemento a insertar en la pila
     * @param numpila pila en la que insertar el elemento. numpila puede ser 0 o 1.
     *
     * @pre numpila == 0 || numpila == 1
     * @throw std::out_of_range si el vector está lleno.
     */
    void push(T elem, int numpila);

    /**
     * @brief se elimina el elemento del tope de una de las pilas.
     * @details si !vacio(numpila) entonces si numpila==1 se decrementa top1, y si numpila==0 se incrementa top0.
     *
     * @param numpila pila de la que eliminar el tope. numpila puede ser 0 o 1.
     * @pre numpila == 0 || numpila == 1
     * @return el elemento en el tope de la pila indicada
     */
    T pop (int numpila);

    /**
     * @brief mirar al elemento en el tope de la pila
     *
     * @param numpila pila de la que obtener el tope.
     * @pre numpila == 0 || numpila == 1
     * @return una referencia constante al elemento en el tope de la pila indicada
     */
    const T & top (int numpila) const;

};


#endif