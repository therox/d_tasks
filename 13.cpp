
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку: ";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    // Задача про замену буквы А на группу символов НЕ
    string replacedString = "";

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

        // Задача про замену А на НЕ
        // Если текущий символ - А
        if (currentChar == "А")
        {
            // то к результирующей строчке вместо неё добавляем НЕ
            replacedString += "НЕ";
        }
        else
        {
            // А иначе, приплюсовываем текущую букву к результирующей строке
            replacedString += currentChar;
        }

        j += cplen;
    }

    std::cout << "Задача 13: "
              << "Результат: " << replacedString << std::endl;
    return 0;
}