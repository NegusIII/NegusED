/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */


#include "maxqueue.h"
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


ostream & operator<<(std::ostream &os, const elemento & elem) {
    os << elem.valor << ", " << elem.max;
    return os;
}

maxqueue::maxqueue() {
}

elemento maxqueue::front() {

    return cola.top();
}

void maxqueue::pop() {

    if (!empty()) cola.pop();
}

void maxqueue::push(int i) {

    while (!empty()) {
        elemento cambiar =  cola.top();
        cola.pop();
        aux.push(cambiar);
    }
    int max = i;
    if (!empty()) {
        int antiguo = aux.top().getmax();
        if (max < antiguo) max = antiguo;
    }

    cola.push(elemento(i, max));

    while (!aux.empty()) {
        elemento cambiar(aux.top().getvalor(), max);
        aux.pop();
        cola.push(cambiar);
    }
}

int maxqueue::size() {
    return cola.size();
}

bool maxqueue::empty() {
    return cola.empty();
}