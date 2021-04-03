#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include <iostream>

using namespace std;

template <class Type>
struct TElement{
    Type data;
};

template <class Type, int maxSize>
struct TLista{
    TElement<Type> elements[maxSize];
    int amount;
};

template <class Type, int maxSize>
void initList(TLista<Type, maxSize> &list){
    list.amount = 0;
}

template <class Type, int maxSize>
void showList(TLista<Type, maxSize> list){
    for(int i = 0; i < list.amount; i++){
        cout << list.elements[i].data << endl;
    }
}

template <class Type, int maxSize>
bool belong(TLista<Type, maxSize> list, Type data){

    for(int i = 0; i< list.amount; i++){
        if(list.elements[i].data == data) return true;
    }

    return false;
}

template <class Type, int maxSize>
int getIndex(TLista<Type, maxSize> list, Type data){

    for(int i = 0; i< list.amount; i++){
        if(list.elements[i].data == data) return i;
    }

    return -1;
}

template <class Type, int maxSize>
void addToFinalOfList(TLista<Type, maxSize> &list, int value){
    list.elements[list.amount].data = value;
    list.amount++;
}

template <class Type, int maxSize>
void addToStartOfList(TLista<Type, maxSize> &list, Type value){

    if(list.amount == maxSize) throw "A lista está cheia!";

    for(int i = list.amount-1; i >= 0; i--){
        list.elements[i+1] = list.elements[i];
    }
    list.elements[0].data = value;
    list.amount++;
}

template <class Type, int maxSize>
void addToPosition(TLista<Type, maxSize> &list, Type value, int position){

    if(position < 0) throw "Posicao invalida!";
    if(position > list.amount) throw "Você não pode inserir nessa posição!";
    if(list.amount == maxSize) throw "A lista está cheia!";

    for(int i = list.amount-1; i >= position; i--){
        list.elements[i+1] = list.elements[i];
    }
    list.elements[position].data = value;
    list.amount++;
}

template <class Type, int maxSize>
void removeFromFinalOfList(TLista<Type, maxSize> &list){
    if(list.amount == 0) throw "A lista está vazia!";
    list.amount--;
}

template <class Type, int maxSize>
void removeFromStartOfList(TLista<Type, maxSize> &list){
    if(list.amount == 0) throw "A lista está vazia!";

    for(int i = 0; i < list.amount-1; i++){
        list.elements[i] = list.elements[i+1];
    }
    list.amount--;
}

template <class Type, int maxSize>
void removeFromPositionOfList(TLista<Type, maxSize> &list, int position){
    if(list.amount == 0) throw "A lista está vazia!";
    if(position >= list.amount || position < 0) throw "Posicao invalida";

    for(int i = position; i < list.amount; i++){
        list.elements[i] = list.elements[i+1];
    }
    list.amount--;

}

template <class Type, int maxSize>
Type getItemFromList(TLista<Type, maxSize> &list, int position){
    if(list.amount == 0) throw "A lista está vazia!";
    if(position >= list.amount || position < 0) throw "Posicao invalida";

    return list.elements[position].data;
}


#endif // LISTAESTATICA_H
