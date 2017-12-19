
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку:";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Задание с двоеточиями
    string resTillColon = "";
    bool colonFound = false;

    for (size_t j = 0; j < text.length();)
    {
        int cplen = 1;
        if ((text[j] & 0xf8) == 0xf0)
            cplen = 4;
        else if ((text[j] & 0xf0) == 0xe0)
            cplen = 3;
        else if ((text[j] & 0xe0) == 0xc0)
            cplen = 2;
        if ((j + cplen) > text.length())
            cplen = 1;
        // Текущий символ text.substr(i, cplen)
        string currentChar = text.substr(j, cplen);

        // Задача на текст до двоеточия
        // Если текущий символ - двоеточие
        if (currentChar == ":")
        {
            // устанавливаем признак того, что нашли двоеточие
            colonFound = true;
        }
        // если признак, что мы нашли двоеточие не стоит
        if (!colonFound)
        {
            //прибавляем к результирующей строчке текущий символ
            resTillColon += currentChar;
        }
        //======================^^^^^^^^^^^^^^============================

        j += cplen;
    }

    if (colonFound)
    {
        std::cout << "Задача 5: "
                  << "Текст до первого двоеточия: \"" << resTillColon << "\"" << std::endl;
    }
    else
    {
        std::cout << "Задача 5: "
                  << "в тексте не обнаружено двоеточий" << std::endl;
    }

    return 0;
}