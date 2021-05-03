#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

using namespace std;

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
    if(tree.root == nullptr){//nao precisa desse if
        tree.root = createNode(data, key);
    }else{
        insertNode(tree.root, data, key);
    }
}

template <typename Type>
bool searchNode(TNode<Type> *&node, int key){
    if(key == node->key){
        return true;
    }

    if(node->left == nullptr && node->right == nullptr){
        return false;
    }

    if(key < node->key){//go to left
        return searchNode(node->left, key);
    }
    if(key > node->key){//go to right
        return searchNode(node->right, key);
    }


}

template <typename Type>
bool search(TBinaryTree<Type> &tree, int key){
   if(tree.root == nullptr) return false;
   return searchNode(tree.root, key);
}



template <typename Type>
void remove(TNode<Type>* &node){

   TNode<Type>* apagar;

   TNode<Type>* greaterNode = node->left;
   if(greaterNode == nullptr){
        apagar = node;
        node = node->right;
        delete apagar;
        return;
   }

   TNode<Type>* pai = nullptr;
   while(greaterNode->right != nullptr){
       pai = greaterNode;
       greaterNode = greaterNode->right;
   }

     greaterNode->right = node->right;
     if(pai != nullptr){
         pai->right = greaterNode->left;
         greaterNode->left = node->left;
     }

  apagar = node;
  node = greaterNode;
  delete apagar;

}

template <typename Type>
void search_remove(TNode<Type>* &node, int key){
    if(node != nullptr){
        if(node->key == key){
            remove(node);
        }else{
            if(key > node->key){
                search_remove(node->right, key);
            }else{
                search_remove(node->left, key);
            }
        }
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
