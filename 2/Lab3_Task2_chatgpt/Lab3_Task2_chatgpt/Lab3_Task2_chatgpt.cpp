#include <iostream>
#include <fstream>
#include "parser.h"
#include "tree.h"

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::string filename;
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл\n";
        return 1;
    }

    std::string expression;
    std::getline(file, expression);

    if (expression.empty())
    {
        std::cout << "Ошибка: файл пуст\n";
        return 1;
    }

    try
    {
        auto root = parseExpression(expression);
        root = simplifyTree(root);

        // Вывод указателя на корень
        std::cout << "Адрес корня дерева: " << root.get() << std::endl;

        //FIX_ME: отсутствует значение корня дерева для проверки
        std::cout << "Значение корня дерева: " << root->value << std::endl;

    }
    catch (const std::exception& ex)
    {
        std::cout << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}