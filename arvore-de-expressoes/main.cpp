#include <QCoreApplication>
#include <iostream>
#include <string>
#include <arvore-de-expressoes.h>
#include <pilha.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TStack<int> stack;
    initStack(stack);

    TBinaryTree<string> tree;
    initTree(tree);

    string expression = "((5+3)*(10-2))";

    insert(tree.root, expression);

    resolve(stack, tree.root);

    showStack(stack);



    return a.exec();
}
