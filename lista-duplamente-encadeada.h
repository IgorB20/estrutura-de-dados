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
bool isEmpty(TList<Type> list){
    if(list.first == nullptr && list.last == nullptr) return true;
    return false;
}

template <class Type>
bool belong(TList<Type> list, Type element){
    TElement<Type> *nav = list.first;
    while(nav != nullptr){
        if(nav->data == element) return true;
        nav = nav->next;
    }

    return false;
}

template <class Type>
int getIndex(TList<Type> list, Type element){
    TElement<Type> *nav = list.first;
    int index = 0;
    while(nav != nullptr){
        if(nav->data == element) return index;
        nav = nav->next;
        index++;
    }

    return -1;
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
template <class Type>
void insertOnStartOfList(TList<Type> &list, Type data){

    TElement<Type> *element = createElement(data);
    if(list.first == nullptr && list.last == nullptr){
         list.first = element;
         list.last = element;
    }else{
        list.first->previous = element;
        element->next = list.first;
        list.first = element;
    }
}

template <class Type>
void insertOnListPos(TList<Type> &list, Type data, int pos){

    if(pos < 0) throw "Tentativa de insercao em uma posicao invalida da lista!";

    if(pos == 0){
        insertOnStartOfList(list, data);
        return;
    }

    TElement<Type> *element = createElement(data);

    TElement<Type> *nav = list.first;
    int count = 0;
    while(nav != nullptr && count < (pos-1)){
        nav = nav->next;
        count++;
    }
    if(nav == nullptr) throw "A posição informada é maior do que o tamanho atual da lista";

    if(nav->next == nullptr){//inserir na posicao final
        insertOnList(list, data);
        return;
    }

    element->next = nav->next;
    nav->next->previous = element;
    nav->next = element;
    element->previous = nav;

}


template <class Type>
void removeFromFinalOfList(TList<Type> &list){

    if(isEmpty(list)) throw "Lista vazia!";

    TElement<Type> *elementToRemove = list.last;

    if(elementToRemove->next == nullptr && elementToRemove->previous == nullptr){
       list.first = nullptr;
       list.last = nullptr;
       delete elementToRemove;
       return;
    }

    elementToRemove->previous->next = nullptr;
    list.last = elementToRemove->previous;
    delete elementToRemove;
}

template <class Type>
void removeFromStartOfList(TList<Type> &list){

     if(isEmpty(list)) throw "Lista vazia!";

     TElement<Type> *elementToRemove = list.first;
     if(elementToRemove->next == nullptr && elementToRemove->previous == nullptr){
        list.first = nullptr;
        list.last = nullptr;
        delete elementToRemove;
        return;
     }
     elementToRemove->next->previous = nullptr;
     list.first = elementToRemove->next;
     delete elementToRemove;
}


template <class Type>
void removeFromListPosition(TList<Type> &list, int pos){

    if(pos < 0) throw "Tentativa de remocao em uma posicao invalida da lista!";

    if(pos == 0){
        removeFromStartOfList(list);
        return;
    }

    TElement<Type> *nav = list.first;
    int count = 0;
    while(nav != nullptr && count < (pos-1)){
        nav = nav->next;
        count++;
    }

    if(nav == nullptr) throw "A posição informada é maior do que o tamanho atual da lista";

    if(nav->next->next == nullptr){//remover da posicao final
        removeFromFinalOfList(list);
        return;
    }

    TElement<Type> *elementToRemove = nav->next;

    nav->next = elementToRemove->next;
    elementToRemove->next->previous = nav;
    delete elementToRemove;
}


template <class Type>
Type getItemFromList(TList<Type> &list, int pos){
    if(pos < 0) throw "Posicao invalida da lista!";
    TElement<Type> *nav = list.first;
    int count = 0;
    while(nav != nullptr && count < pos){
        nav = nav->next;
        count++;
    }
    if(nav == nullptr) throw "Posicao invalida da lista!";
    return nav->data;
}
#endif // LISTADUPLAMENTEENCADEADA_H
