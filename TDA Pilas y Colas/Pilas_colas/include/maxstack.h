#ifndef MAXSTACK_H
#define MAXSTACK_H

/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#include <iostream>
#include <queue>

/**
 * @brief struct para almacenar el valor y el máximo hasta ese momento
 */
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
 * @brief TDA MaxStack
 *        Implementación de una pila con máximo
 */
class maxstack {
private:
    std::queue<elemento> pila;
    std::queue<elemento> aux;

public:
    /**
     * @brief Constructor por defecto
     */
    maxstack();

    /**
     * @brief metodo que saca el tope de la pila
     */
    void pop();

    /**
     * @brief coloca el elemento parámetro en lo alto de la pila
     * @param i valor a insertar
     */
    void push(int i);

    /**
     * @brief devuelve el elemento en el tope de la pila
     *
     * @return referencia al tope de la pila
     */
    elemento top();

    /**
     * @brief metodo que devuelve el tamaño de la pila
     * @return el tamaño de la pila
     */
    int size();

    /**
     * @brief comprueba si la pila está vacía
     * @return true si la pila está vacía, false en caso contrario
     */
    bool empty();
};

#endif //MAXSTACK_H