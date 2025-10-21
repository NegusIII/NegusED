/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#include <queue>

struct elemento {
    int valor;
    int max;
};

/**
 * @brief clase maxtack, que representa una pila con máximo
 *
 * @details la clase está implementada con una cola principal, que actúa como pila, y una cola auxiliar, que  sirve
 * para asegurar el comportamiento de la clase como pila. Las colas guardan objetos de tipo elemento, que guardan
 * el valor de la posición actual de la pila junto con el valor del máximo actual.
 *
 */
class maxstack {
private:

    std::queue<elemento> pila;
    std::queue<elemento> aux;

public:

    /**
     * @brief metodo que saca el tope de la pila
     *
     * @return el elemento en la parte superior de la pila
     */
    elemento pop();

    /**
     * @brief coloca el elemento parámetro en lo alto de la pila
     */
    void push(elemento);

    /**
     *
     * @brief metodo que muestra el tope de la pila sin extraerlo
     *
     * @return referencia al tope de la pila
     */
    elemento &top();

    /**
     * @brief metodo que devuelve el tamaño de la pila
     */
    int size();

    /**
     * @brief metodo para comprobar si una pila está vacía
     *
     * @return true si la pila está vacía
     */
    bool empty();
};