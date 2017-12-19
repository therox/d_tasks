// Удалить из заданной строки все символы, расположенные между первой и последней запятой

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
    string buf; // Буфер
    string res; // Строка с результатом
    int commaCount = 0;

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

        // Задача на вывод текста до первой запятой и после последней
        // Если нашли запятую
        if (currentChar == ",")
        {
            // увеличиваем количество найденных запятых
            commaCount++;
            // Если до первой запятой мы еще не добирались
            if (!firstComma)
            {
                // прибавляем содержимое буфера (который формируется ниже по коду) к резульрирующей строке
                res += buf;
                // обнуляем буфер
                buf = "";
                // выставляем признак того, что мы нашли первую запятую
                firstComma = true;
            }
            // если же это не первая запятая
            else
            {
                // просто обнуляем буфер, нас не интересует то, что было после первой запятой и перед последней
                buf = "";
            }
        }
        else
        {
            buf += currentChar;
        }

        //======================^^^^^^^^^^^^^^============================

        j += cplen;
    }
    // Для задачки 2 добавляем последний буфер (от последней запятой до конца строки) к результату
    res += buf;

    std::cout << "Задача 2: "
              << "Результат: " << res << std::endl;

    if (commaCount > 0)
    {
        std::cout << "Задача 6: "
                  << "Порядковый номер последней запятой в строке: " << commaCount << std::endl;
    }
    else
    {
        std::cout << "Задача 6: "
                  << "в тексте не обнаружено запятых" << std::endl;
    }

    return 0;
}