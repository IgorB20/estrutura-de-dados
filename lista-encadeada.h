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
void removeFromStartOfList(TList<Type> &list){
   if(list.first == nullptr) throw "List underflow";

   TElement<Type>* elementToRemove = list.first;
   list.first = elementToRemove->next;
   delete elementToRemove;
}

template <class Type>
void removeFromPosOfList(TList<Type> &list, int position){

    //TRATAR ERROS

    TElement<Type>* nav = list.first;
    for(int i = 0; i<(position-1); i++){
        nav = nav->next;
    }

    TElement<Type>* elementToDelete = nav->next;
    nav->next = elementToDelete->next;
    delete elementToDelete;

}


#endif // LISTA_H
