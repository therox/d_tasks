
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку:";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Следующая конструкция разбивает строку на массив по запятым
    bool firstComma = false;

    // Задание про последовательность из 5 букв А
    int aCount = 0;
    bool fiveA = false;

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

        // Задача на подсчет рядомстоящих букв А
        // Если текущий символ - буква А
        if (currentChar == "А")
        {
            // увеличиваем счетчик найденных букв А
            std::cout << aCount;
            aCount++;
            // Если их 5 подряд,
            if (aCount == 5)
            {
                // выставляем признак того, что нашли 5 букв А подряд
                fiveA = true;
            }
        }
        else
        {
            // Обнуляем счетчик букв А
            aCount = 0;
        }
        //======================^^^^^^^^^^^^^^============================

        j += cplen;
    }

    if (fiveA)
    {
        std::cout << "Задача 4: "
                  << "В строке обнаружена последовательность из 5 букв \"А\"" << std::endl;
    }
    else
    {
        std::cout << "Задача 4: "
                  << "В строке не обнаружена последовательность из 5 букв \"А\"" << std::endl;
    }

    return 0;
}