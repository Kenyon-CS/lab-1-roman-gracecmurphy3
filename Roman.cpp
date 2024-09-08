#include "roman.h"
#include <unordered_map>

Roman::Roman() : romanNumeral(""), integerValue(0){}
Roman::Roman(const std::string& roman) : romanNumeral(roman), integerValue(romanToInt(roman)){}
Roman::Roman(int value) : integerValue(value), romanNumeral(intToRoman(value)){}

void Roman::printRoman() const {
    std::cout << romanNumeral << std::endl;
}

void Roman::printInteger() const {
    std::cout << integerValue << std::endl;
}

std::string Roman::getRoman() const {
    return romanNumeral;
}

int Roman::getInt() const {
    return integerValue;
}
int Roman::romanToInt(const std:: string& roman) {
    std::unordered_map<char, int> romanDict = {
        {'I', 1}, {'i', 1}, {'V', 5}, {'v', 5}, 
        {'X', 10}, {'x',10}, {'L',50}, {'l',50},
        {'C',100}, {'c',100}, {'D',500}, {'d',500},
        {'M',1000}, {'m',1000}
    };

    int tot = 0;
    int prior = 0;

    for (int i = roman.size() - 1; i>=0; --i){
        int value = romanDict[roman[i]];
        if (value < prior){
            tot -= value;
        }
        else{
            tot += value;
        }
        prior = value;
    }
    return tot;
    }

    std::string Roman::intToRoman(int Num) {
        std::pair <int, std::string> romanPairs[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"},{400, "CD"}, {100, "C"}, 
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
            {4, "IV"}, {1, "I"}
            };
        std::string result = "";
        for (const auto& pair : romanParis){
            while (num >= pair.first){
                result += pair.second;
                num -= pair.first;
            }
        }
          return result;  
        }
    }
}


