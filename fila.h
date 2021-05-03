#ifndef FILA_H
#define FILA_H
#include <iostream>

using namespace std;

template <typename Type>
struct TElement{
    Type data;
    TElement<Type>* next;
};

template <typename Type>
struct Queue{
    TElement<Type>* first;
};

template <typename Type>
void initQueue(Queue<Type> &fila){
    fila.first = nullptr;
}

template <typename Type>
void showQueue(Queue<Type> fila){
    TElement<Type>* nav = fila.first;
    while(nav != nullptr){
        cout << nav->data << endl;
        nav = nav->next;
    }
}

template <typename Type>
TElement<Type>* createElement(Type data){
    TElement<Type>* element = new TElement<Type>;
    element->data = data;
    element->next = nullptr;
    return element;
}

template <typename Type>
void queue(Queue<Type> &fila, Type data){
    TElement<Type>* element = createElement(data);

    if(fila.first == nullptr){
        fila.first = element;
        return;
    }

    TElement<Type>* nav = fila.first;
    while(nav->next != nullptr){
        nav = nav->next;
    }

    nav->next = element;
}

template <typename Type>
Type dequeue(Queue<Type> &fila){
    if(fila.first == nullptr) throw "List underflow";
    Type dataCopy = fila.first->data;
    TElement<Type>* remove = fila.first;

    fila.first = fila.first->next;
    delete remove;
    return dataCopy;
}






#endif // FILA_H
