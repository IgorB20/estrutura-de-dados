#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <pilha.h>
#include <iostream>

using namespace std;

template <typename Type>
struct TNode{
    Type data;
    TNode<Type> *left, *right;
};

template <typename Type>
struct TBinaryTree{
    TNode<Type> *root;
};

template <typename Type>
void initTree(TBinaryTree<Type> &tree){
    tree.root = nullptr;
}

template <typename Type>
TNode<Type>* createNode(Type data){
    TNode<Type>* node = new TNode<Type>;
    node->data = data;
    node->left = node->right  = nullptr;
    return node;
}

string removeExternParentheses(string expression){
    string t = "";
    for(int i = 0;i<expression.length(); i++){
        if(i == 0 || i == expression.length()-1) continue;
        t += expression[i];
    }
    return t;
}

bool isOperador(char caractere)
{
    switch(caractere){
        case '+':
        return true;
        case '-':
        return true;
        case '*':
        return true;
        case '/':
        return true;
        default:
        return false;
    }
}

bool isOperando(string text){
    int notNumbersCount = 0;
    for(int i = 0; i<text.length();i++){
        if(text[i] == '(' || text[i] == ')' || text[i] == '*' ||
                text[i] == '/' || text[i] == '-' || text[i] == '+' ){
            notNumbersCount++;
            break;
        }
    }

    if(notNumbersCount > 0) return false;
    return true;
}

template <typename Type>
void insert(TNode<Type>* &node, string expression){

    if(isOperando(expression)){
        node = createNode(expression);
        return;
    }

     expression = removeExternParentheses(expression);

    int rightParenthesesCount = 0;
    int leftParenthesesCount = 0;
    string operandoExterno;
    string rightPart, leftPart;

    for(int i = 0; i< expression.length(); i++){
        if(expression[i] == '(') leftParenthesesCount++;
        if(expression[i] == ')') rightParenthesesCount++;

        if(isOperador(expression[i]) && ((leftParenthesesCount == rightParenthesesCount))){
            operandoExterno.push_back(expression[i]);

             leftPart = expression.substr(0, i);
             rightPart = expression.substr(i+1, expression.length());
        }


    }

    node = createNode(operandoExterno);

    //montar arvore da esquerda
    insert(node->left, leftPart);

    //montar arvore da direita
    insert(node->right, rightPart);

}


//adiciona os items na pilha com o algoritmo pós fixado
//de acordo com a notação polonesa inversa
template <typename Type>
void resolve(TStack<int> &stack, TNode<Type> *node){
    /*
        1. Esquerda
        2. Direita
        3. Visita
    */

    if(node != nullptr){

        resolve(stack, node->left);
        resolve(stack, node->right);

         if(isOperador(node->data[0])){
             int num1 = pop(stack);
             int num2 = pop(stack);
             int result;
             switch(node->data[0]){
                 case '+':
                    result = num2 + num1;
                    break;
                case '-':
                    result = num2 - num1;
                    break;
                case '/':
                    result = num2 / num1;
                    break;
                case '*':
                    result = num2 * num1;
                    break;
             }
             push(stack, result);
         }else{
             push(stack, stoi(node->data));
         }
    }
}

#endif // ARVOREBINARIA_H
