#ifndef LISTA_H
#define LISTA_H
#include <iostream>

template<typename Type>
struct TElement{
    Type data;
};

template <typename Type, int MAX>
struct TList{
    TElement<Type> elements[MAX];
    int amount;
};

template <typename Type, int MAX>
void showList(TList<Type, MAX> list){
    if(list.amount == 0) throw "Lista vazia!";

    for(int i = 0; i < list.amount; i++){
        std::cout << list.elements[i].data << ", " << std::endl;
    }
    std::cout << std::endl;
};

template <typename Type, int MAX>
void initList(TList<Type, MAX> &list){
    list.amount = 0;
};

template <typename Type, int MAX>
bool belong(TList<Type, MAX> &list, Type value){
    for(int i = 0; i< list.amount; i++){
        if(list.elements[i].data == value) return true;
    }

    return false;
};

template <typename Type, int MAX>
Type getData(TList<Type, MAX> &list, int position){
    if(position >= list.amount) throw "Posição inválida!";
    return list.elements[position].data;
};


//insere no final da lista
template <typename Type, int MAX>
void pushToList(TList<Type, MAX> &list, Type value){
    if(list.amount == MAX) throw "A lista está cheia!";

    TElement<Type> element;
    element.data = value;
    list.elements[list.amount] = element;
    list.amount++;
};


//insere no começo da lista
template <typename Type, int MAX>
void unshiftToList(TList<Type, MAX> &list, Type value){
    if(list.amount == MAX) throw "A lista está cheia!";

    TElement<Type> element;
    element.data = value;
    for(int i = list.amount-1; i >= 0; i--){
        list.elements[i+1] = list.elements[i];
    }

    list.elements[0] = element;
    list.amount++;
};

//insere em indice especifico da lista
template <typename Type, int MAX>
void pushToPositionOfList(TList<Type, MAX> &list, Type value, int position){

    if(position > list.amount) throw "Você não pode inserir nessa posição!";
    if(list.amount == MAX) throw "A lista está cheia!";

    TElement<Type> element;
    element.data = value;

    for(int i = list.amount-1; i >= position; i--){
        list.elements[i+1] = list.elements[i];
    }

    list.elements[position] = element;
    list.amount++;
};


//remove do começo da lista
template <typename Type, int MAX>
void removeFromStartOfList(TList<Type, MAX> &list){
    if(list.amount == 0) throw "A lista está vazia";

    if(list.amount > 1){
        for(int i = 1; i < list.amount; i++){
            list.elements[i-1] = list.elements[i];
        }
    }

    list.amount--;
};


//remove do final da lista
template <typename Type, int MAX>
void removeFromFinalOfList(TList<Type, MAX> &list){
    if(list.amount == 0) throw "A lista está vazia";
    list.amount--;
};

//remove de um indice especifico da lista
template <typename Type, int MAX>
void removeFromPositionOfList(TList<Type, MAX> &list, int position){

    if(position >= list.amount) throw "Você não pode remover desta posição!";
    if(list.amount == 0) throw "A lista está vazia!";

    for(int i = position+1; i < list.amount; i++){
        list.elements[i-1] = list.elements[i];
    }

    list.amount--;
};





#endif // LISTA_H
