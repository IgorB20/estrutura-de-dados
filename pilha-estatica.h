#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H
#include <iostream>

template <typename Type>
struct TElement{
    Type data;
};

template <typename Type, int SIZE>
struct TStaticStack{
    TElement<Type> elements[SIZE];
    int top;
};

template <typename Type, int SIZE>
void showStack(TStaticStack<Type, SIZE> stack){
    for(int i = stack.top; i>=0; i--){
        std::cout << stack.elements[i].data << std::endl;
    }
}

template <typename Type, int SIZE>
void initStack(TStaticStack<Type, SIZE> &stack){
    stack.top = -1;
}

template <typename Type, int SIZE>
void push(TStaticStack<Type, SIZE> &stack, Type data){
    if(stack.top+1 == SIZE) throw "List overflow";

    TElement<Type> element;
    element.data = data;

    stack.top++;
    stack.elements[stack.top] = element;
}

template <typename Type, int SIZE>
Type pop(TStaticStack<Type, SIZE> &stack){
    if(stack.top == -1) throw "List underflow";

    Type data = stack.elements[stack.top].data;
    stack.top--;

    return data;
}




#endif // PILHAESTATICA_H
