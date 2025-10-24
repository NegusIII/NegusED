/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include <maxstack.h>
#include <iostream>

using namespace std;

void elemento::setmax(int max) {
    this->max = max;
}

int elemento::getvalor() const {
    return valor;
}

int elemento::getmax() const {

    return max;
}


elemento::elemento(int _valor, int _max) : valor(_valor), max(_max){}


maxstack::maxstack() {
}

void maxstack::pop() {
    while (pila.size() > 1) {
        elemento cambiar = pila.front();
        pila.pop();
        aux.push(cambiar);
    }
    pila.pop();
    while (!aux.empty()) {
        elemento cambiar = aux.front();
        aux.pop();
        pila.push(cambiar);
    }
}

void maxstack::push(int i) {
    int max = top().getmax();
    if (i > max) max = i;
    pila.push(elemento{i, max});
}

elemento maxstack::top() {
    while (pila.size() > 1) {
        elemento cambiar = pila.front();
        pila.pop();
        aux.push(cambiar);
    }
    elemento elem = pila.front();
    aux.push(elem);
    pila.pop();
    while (!aux.empty()) {
        elemento cambiar = aux.front();
        aux.pop();
        pila.push(cambiar);
    }
    return elem;
}

int maxstack::size() {
    return pila.size();
}

bool maxstack::empty() {
    return pila.empty();
}

std::ostream & operator<<(std::ostream & os, const elemento & elem) {
    os << elem.valor << ", " << elem.max;
    return os;
}