#pragma once
#include <memory>

// Узел дерева выражения
struct TreeNode
{
    int value; // значение или код операции
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int value);
};

// Проверка: является ли узел операцией
bool isOperator(int value);

// Вычисление операции
int calculate(int op, int left, int right);

// Преобразование дерева (свёртка поддеревьев)
std::shared_ptr<TreeNode> simplifyTree(std::shared_ptr<TreeNode> node);