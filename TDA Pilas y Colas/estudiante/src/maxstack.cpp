/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include <maxstack.h>
#include <iostream>

using namespace std;

elemento maxstack::pop() {

    for (int i = 0; i < pila.size() - 1; i++) {

        elemento cambiar = pila.pop;
        aux.push(cambiar);
    }
    elemento elem = pila.pop();
    for (int i = 0; i < aux.size(); i++) {

        elemento cambiar = aux.pop;
        pila.push(cambiar);
    }
    return elem;
}
