#ifndef PILHA_H
#define PILHA_H
#include <iostream>

template <typename Type>
struct TElement{
    Type data;
    TElement<Type> *next;
};

template <typename Type>
struct TStack{
    TElement<Type> *top;
};

template <typename Type>
void initStack(TStack<Type> &stack){
    stack.top = nullptr;
}


template <typename Type>
void showStack(TStack<Type> stack){
    TElement<Type> *nav = stack.top;
    while(nav != nullptr){
        std::cout << nav->data << std::endl;
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
void push(TStack<Type> &stack, Type data){
    TElement<Type>* element = createElement(data);
    if(stack.top == nullptr){
        stack.top = element;
        return;
    }

    element->next = stack.top;
    stack.top = element;
}

template <typename Type>
Type pop(TStack<Type> &stack){
    if(stack.top == nullptr) throw "A lista está vazia!";

   TElement<Type>* elementToRemove = stack.top;
   Type data = elementToRemove->data;
   stack.top = elementToRemove->next;
   delete elementToRemove;
   return data;
}








#endif // PILHA_H
