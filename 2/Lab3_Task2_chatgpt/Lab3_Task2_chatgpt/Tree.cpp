#include "tree.h"
#include <cmath>
#include <stdexcept>

TreeNode::TreeNode(int value)
    : value(value), left(nullptr), right(nullptr)
{
}

bool isOperator(int value)
{
    return value < 0;
}

/**
 * Выполняет вычисление операции.
 * Бросает исключение при некорректных данных (деление на 0).
 */
int calculate(int op, int left, int right)
{
    switch (op)
    {
    case -1: return left + right;
    case -2: return left - right;
    case -3: return left * right;
    case -4:
        //FIX_ME: необходимо отделять if-else фигурными скобками
        /*if (right == 0)
            throw std::runtime_error("Ошибка: деление на ноль");*/
        if (right == 0)
        {
            throw std::runtime_error("Ошибка: деление на ноль");
        }
        return left / right;
    case -5:
        //FIX_ME: необходимо отделять if-else фигурными скобками
        /*if (right == 0)
            throw std::runtime_error("Ошибка: остаток от деления на ноль");*/
        if (right == 0)
        {
            throw std::runtime_error("Ошибка: остаток от деления на ноль");
        }
        return left % right;
    case -6:
        return static_cast<int>(std::pow(left, right));
    default:
        throw std::runtime_error("Неизвестная операция");
    }
}

/**
 * Рекурсивно упрощает дерево:
 * если поддерево даёт результат [0..9], заменяет его числом
 */
std::shared_ptr<TreeNode> simplifyTree(std::shared_ptr<TreeNode> node)
{
    //FIX_ME: необходимо отделять if-else фигурными скобками
    /*if (!node)
        return nullptr;*/
    if (!node)
    {
        return nullptr;
    }

    //FIX_ME: необходимо отделять if-else фигурными скобками
    /*if (!isOperator(node->value))
        return node;*/
    if (!isOperator(node->value))
    {
        return node;
    }

    node->left = simplifyTree(node->left);
    node->right = simplifyTree(node->right);

    if (node->left && node->right &&
        !isOperator(node->left->value) &&
        !isOperator(node->right->value))
    {
        try
        {
            int result = calculate(node->value,
                node->left->value,
                node->right->value);

            if (result >= 0 && result <= 9)
            {
                return std::make_shared<TreeNode>(result);
            }
        }
        catch (...)
        {
            // Игнорируем ошибки и оставляем дерево как есть
        }
    }

    return node;
}