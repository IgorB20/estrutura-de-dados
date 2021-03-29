#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H
#include <iostream>

using namespace std;

template <class Type>
struct TElement{
    Type data;
    TElement<Type>* previous;
    TElement<Type>* next;
};

template <class Type>
struct TList{
    TElement<Type>* first;
    TElement<Type>* last;
};

template <class Type>
void initList(TList<Type> &list){
    list.first = nullptr;
    list.last = nullptr;
}

template <class Type>
void showList(TList<Type> list){
    TElement<Type> *nav = list.first;
    while(nav != nullptr){
        cout << nav->data << endl;
        nav = nav->next;
    }
}

template <class Type>
TElement<Type>* createElement(Type data){
    TElement<Type> *element = new TElement<Type>;
    element->data = data;
    element->next = nullptr;
    element->previous = nullptr;
    return element;
}


template <class Type>
void insertOnList(TList<Type> &list, Type data){

    TElement<Type> *element = createElement(data);

    if(list.first == nullptr && list.last == nullptr){//lista vazia
        list.first = element;
        list.last = element;

    }else{//lista nao esta vazia
        element->previous = list.last;
        list.last->next = element;
        list.last = element;
    }
}

#endif // LISTADUPLAMENTEENCADEADA_H
