#include "TreePrinter.h"
#include "Node.h"

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

void printTree(Node* node) 
{
    if (node->getType() == Node::Type::Operand) 
    {
        std::cout << node->getValue();
        return;
    }

    int op = node->getValue();
    switch (op) 
    {
    case -1: std::cout << "+"; break;
    case -2: std::cout << "-"; break;
    case -3: std::cout << "*"; break;
    case -4: std::cout << "/"; break;
    case -5: std::cout << "%"; break;
    case -6: std::cout << "^"; break;
    default: std::cout << "?"; break;
    }
    std::cout << " ";
    printTree(node->getLeft());
    std::cout << " ";
    printTree(node->getRight());
}