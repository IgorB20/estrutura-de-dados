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
    TElement<Type> list[maxSize];
    int amount;
};

template <class Type, int maxSize>
void initList(TLista<Type, maxSize> &list){
    list.amount = 0;
}

template <class Type, int maxSize>
void showList(TLista<Type, maxSize> array){
    for(int i = 0; i < array.amount; i++){
        cout << array.list[i].data << endl;
    }
}

template <class Type, int maxSize>
bool belong(TLista<Type, maxSize> list, Type data){

    for(int i = 0; i< list.amount; i++){
        if(list.list[i].data == data) return true;
    }

    return false;
}

template <class Type, int maxSize>
int getIndex(TLista<Type, maxSize> list, Type data){

    for(int i = 0; i< list.amount; i++){
        if(list.list[i].data == data) return i;
    }

    return -1;
}

template <class Type, int maxSize>
void addToFinalOfList(TLista<Type, maxSize> &array, int value){
    array.list[array.amount].data = value;
    array.amount++;
}

template <class Type, int maxSize>
void addToStartOfList(TLista<Type, maxSize> &array, Type value){

    if(array.amount == maxSize) throw "A lista está cheia!";

    for(int i = array.amount-1; i >= 0; i--){
        array.list[i+1] = array.list[i];
    }
    array.list[0].data = value;
    array.amount++;
}

template <class Type, int maxSize>
void addToPosition(TLista<Type, maxSize> &array, Type value, int position){

    if(position < 0) throw "Posicao invalida!";
    if(position > array.amount) throw "Você não pode inserir nessa posição!";
    if(array.amount == maxSize) throw "A lista está cheia!";

    for(int i = array.amount-1; i >= position; i--){
        array.list[i+1] = array.list[i];
    }
    array.list[position].data = value;
    array.amount++;
}

template <class Type, int maxSize>
void removeFromFinalOfList(TLista<Type, maxSize> &array){
    if(array.amount == 0) throw "A lista está vazia!";
    array.amount--;
}

template <class Type, int maxSize>
void removeFromStartOfList(TLista<Type, maxSize> &list){
    if(list.amount == 0) throw "A lista está vazia!";

    for(int i = 0; i < list.amount-1; i++){
        list.list[i] = list.list[i+1];
    }
    list.amount--;
}

template <class Type, int maxSize>
void removeFromPositionOfList(TLista<Type, maxSize> &list, int position){
    if(list.amount == 0) throw "A lista está vazia!";
    if(position >= list.amount || position < 0) throw "Posicao invalida";

    for(int i = position; i < list.amount; i++){
        list.list[i] = list.list[i+1];
    }
    list.amount--;

}

template <class Type, int maxSize>
Type getItemFromList(TLista<Type, maxSize> &list, int position){
    if(list.amount == 0) throw "A lista está vazia!";
    if(position >= list.amount || position < 0) throw "Posicao invalida";

    return list.list[position].data;
}


#endif // LISTAESTATICA_H
