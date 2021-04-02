#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class Type>
struct TElement{
    Type data;
    TElement<Type> *next;
};

template <class Type>
struct TList{
    TElement<Type> *first;
};

template <class Type>
void initList(TList<Type> &list){
    list.first = nullptr;
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
bool belong(TList<Type> list, Type data){
    TElement<Type> *nav = list.first;
    while(nav != nullptr){
        if(nav->data == data) return true;
        nav = nav->next;
    }

    return false;
}

template <class Type>
int getIndex(TList<Type> list, Type data){
    TElement<Type> *nav = list.first;
    int index = 0;
    while(nav != nullptr){
        if(nav->data == data) return index;
        nav = nav->next;
        index++;
    }

    return -1;
}

template <class Type>
TElement<Type>* createElement(Type data){
    TElement<Type> *element = new TElement<Type>;
    element->data = data;
    element->next = nullptr;
    return element;
}

template <class Type>
void insertOnList(TList<Type> &list, Type data){

    TElement<Type> *element = createElement(data);

    if(list.first){//lista nao está vazia
        TElement<Type> *nav = list.first;
        while(nav->next != nullptr){
            nav = nav->next;
        }
        nav->next = element;
    }else{//lista esta vazia
        list.first = element;
    }
}

template <class Type>
void insertOnStartOfList(TList<Type> &list, Type data){
   TElement<Type> *element = createElement(data);
   element->next = list.first;
   list.first = element;
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

    element->next = nav->next;
    nav->next = element;

}



template <class Type>
void removeFromStartOfList(TList<Type> &list){
   if(list.first == nullptr) throw "List underflow";

   TElement<Type>* elementToRemove = list.first;
   list.first = elementToRemove->next;
   delete elementToRemove;
}

template <class Type>
void removeFromFinalOfList(TList<Type> &list){
    if(list.first == nullptr) throw "List underflow";

    if(list.first->next == nullptr){
        delete list.first;
        list.first = nullptr;
        return;
    }


    TElement<Type> *nav = list.first;

    while(nav->next->next != nullptr){
        nav = nav->next;
    }

    TElement<Type>* elementToRemove = nav->next;
    nav->next = nullptr;
    delete elementToRemove;


}

template <class Type>
void removeFromPosOfList(TList<Type> &list, int position){

    if(position < 0) throw "Tentativa de remocao em uma posicao invalida da lista!";

    if(position == 0){
        removeFromStartOfList(list);
        return;
    }

    TElement<Type>* nav = list.first;
    int count = 0;
    while(nav != nullptr && count < (position-1)){
        nav = nav->next;
        count++;
    }

    if(nav->next == nullptr) throw "A posição informada é maior do que o tamanho atual da lista";

    TElement<Type>* elementToDelete = nav->next;
    nav->next = elementToDelete->next;
    delete elementToDelete;

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


#endif // LISTA_H
