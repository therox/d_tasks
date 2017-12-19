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

    // Задание про убирание букв Е и Л
    string resEL; // Строка с результатом для задания 3

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

        // Проверка на наличие буквы Е или Л
        // Если текущй символ не Е и не Л, то добавляем его к результирующей строке
        if ((currentChar != "Е") && (currentChar != "Л"))
            resEL += currentChar;
        //======================^^^^^^^^^^^^^^============================

        //======================^^^^^^^^^^^^^^============================

        j += cplen;
    }

    std::cout << "Задача 3: "
              << "Результат: " << resEL << std::endl;
    return 0;
}