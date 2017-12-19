
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Введите, пожалуйста, строку:";
    string text;
    getline(std::cin, text);
    // string text = "Это должно входить, это не, должно, НЕТ, ДА, ДА, НЕТ, НЕТ, НЕТ , -., последовательность из 5 букв А: ААААА''', и это не должно, YXYXYЙ, а это должно остаться09";

    std::cout << "Строка на входе: " << text << std::endl;

    int yesStringCount = 0;
    string yesBuffer = "";
    int noStringCount = 0;
    string noBuffer = "";

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

        // Проверка на вхождение слова "ДА" или "НЕТ"
        // Если текущий символ - Д и буфер пустой
        if ((currentChar == "Д") && (yesBuffer == ""))
        {
            // добавляем текущий символ в буфер
            yesBuffer += currentChar;
        }
        // Если текущий символ А и буфер содержит "Д"
        if ((currentChar == "А") && (yesBuffer == "Д"))
        {
            // мы нашли слово ДА
            // обнуляем буфер
            yesBuffer = "";
            //  и увеличиваем счетчик найденных комбинаций слов ДА на 1
            yesStringCount++;
        }
        // Если текущий символ - Н и буфер пустой
        if ((currentChar == "Н") && (noBuffer == ""))
        {
            noBuffer += currentChar;
        }
        // Если текущий символ - Е и в буфере есть Н
        if ((currentChar == "Е") && (noBuffer == "Н"))
        {
            // добавляем Е в буфер (пока что похоже на слово НЕТ)
            noBuffer += currentChar;
        }
        // Если текущий символ Т и в буфере содержится "НЕ"
        if ((currentChar == "Т") && (noBuffer == "НЕ"))
        {
            // мы нашли слово НЕТ
            // обнуляем буфер
            noBuffer = "";
            // увеличиваем счетчик на 1
            noStringCount++;
        }

        j += cplen;
    }

    std::cout << "Задача 9: "
              << "В строке обнаружено " << yesStringCount << " вхождений слова \"ДА\" и " << noStringCount << " вхождений слова \"НЕТ\"" << std::endl;

    return 0;
}