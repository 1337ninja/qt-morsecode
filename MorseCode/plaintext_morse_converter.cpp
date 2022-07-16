#include "plaintext_morse_converter.h"
#include <sstream>

PlaintextMorseConverter::PlaintextMorseConverter() : spaces(0), morseCharDelimiter('x'), morseWordDelimiter("xx"),
    plainTextToMorse ({
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
            {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
            {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
            {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},{'Z', "--.."},
            {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
            {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
            {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
            {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {' ', morseWordDelimiter},
            {'0', "-----"},	{'1', ".----"},	{'2', "..---"},	{'3', "...--"},	{'4', "....-"},
            {'5', "....."}, {'6', "-...."},	{'7', "--..."},	{'8', "---.."}, {'9', "----."}
        }),
    morseToPlainText ({
            {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
            {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
            {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}, {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
            {"--..", 'Z'}, {morseWordDelimiter, ' '},
            {"-----", '0'},	{".----", '1'},	{"..---", '2'},	{"...--", '3'},	{"....-", '4'},
            {".....", '5'}, {"-....", '6'},	{"--...", '7'},	{"---..", '8'}, {"----.", '9'}
        })
{}

const std::string PlaintextMorseConverter::convert(const std::string& plainText)
{
    std::string morse;
    for (int i = 0; i < plainText.size(); i++) {
        auto it = plainTextToMorse.find(plainText[i]);
        morse += (it != plainTextToMorse.end() ? it->second : "#");
        if (i != plainText.size() - 1) {
            if (plainText[i+1] != ' ')
                morse += morseCharDelimiter;
        }
    }
    return morse;
}

const std::string PlaintextMorseConverter::inverseConvert(const std::string& morseText)
{
    std::istringstream morse(morseText);
    std::string morseCode, plainText;
    while (std::getline(morse, morseCode, morseCharDelimiter)) {
        if (morseCode.empty()) {
            ++spaces;
            if (spaces % 2 != 0) {
                morseCode = morseWordDelimiter;
            }
            else {
                continue;
            }
        }
        else {
            spaces = 0;
        }
        auto it = morseToPlainText.find(morseCode);
        plainText +=  ( it != morseToPlainText.end() ? it->second : '#');
    }
    return plainText;
}