#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

template <typename Type>
struct TNode{
    int key;
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
TNode<Type>* createNode(Type data, int key){
    TNode<Type>* node = new TNode<Type>;
    node->data = data;
    node->key = key;
    node->left = node->right  = nullptr;
    return node;
}

template <typename Type>
void insertNode(TNode<Type> *&node, Type data, int key){
    if(node == nullptr){ //fazer inserção
        node = createNode(data, key);
    }else{
        if(key < node->key){//go to left
              insertNode(node->left, data, key);
        }else{
            if(key > node->key){ //go to right
                insertNode(node->right, data, key);
            }else{
                throw  "Nó já existe na árvore";
            }
        }
    }
}

template <typename Type>
void insert(TBinaryTree<Type> &tree, Type data, int key){
    if(tree.root == nullptr){
        tree.root = createNode(data, key);
    }else{
        insertNode(tree.root, data, key);
    }
}

//FUNÇÕES PARA IMPRIMIR
template <typename Type>
void pre_fixa(TNode<Type> *node){
    /*
        1. Visita
        2. Esquerda
        3. Direita
    */

    if(node != nullptr){
        std::cout << "Visitando no {" << node->key <<", "<< node->data << "}\n";
        pre_fixa(node->left);
        pre_fixa(node->right);
    }
}

template <typename Type>
void in_fixa(TNode<Type> *node){
    /*
        1. Esquerda
        2. Visita
        3. Direita
    */

    if(node != nullptr){
        in_fixa(node->left);
        std::cout << "Visitando no {" << node->key <<", "<< node->data << "}\n";
        in_fixa(node->right);
    }
}

template <typename Type>
void pos_fixa(TNode<Type> *node){
    /*
        1. Esquerda
        2. Direita
        3. Visita
    */

    if(node != nullptr){
        pos_fixa(node->left);
        pos_fixa(node->right);
        std::cout << "Visitando no {" << node->key <<", "<< node->data << "}\n";
    }
}






#endif // BINARYTREE_H

