/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#include <stack>
#include <iostream>

struct elemento {
private:

    int valor;
    int max;
public:
    int getvalor() const;
    int getmax() const;
    void setmax(int max);
    elemento(int _valor, int _max);

    friend std::ostream & operator<<(std::ostream & os, const elemento & elem);
};



/**
 * @brief Clase que representa una cola con máximo
 */
class maxqueue {

private:
    std::stack<elemento> cola;
    std::stack<elemento> aux;

public:
    /**
     * @brief Constructor por defecto
     */
    maxqueue();

    /**
     * @brief consulta el elemento al frente de la cola (el primero colocado)
     */
    elemento front();

    /**
     * @brief saca al elemento al frente de la cola
     */
    void pop();

    /**
     * @brief coloca un elemento al final de la cola
     */
    void push(int i);

    /**
     *
     * @return el tamaño de la cola
     */
    int size();

    /**
     *
     * @return true si la cola está vacía
     */
    bool empty();
};
