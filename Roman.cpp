#include "Roman.h"
#include <unordered_map>
#include <iostream>

using namespace std;
// initializes an empty string for the roman numeral to fill and return as well as a 0 value for the integer return
Roman::Roman() : romanNumeral(""), integerValue(0){}

// initializes variable to be used in romanToInt
Roman::Roman(const string& roman){
    romanNumeral = roman;
    integerValue = romanToInt(roman);
}
//initializes variable to be used in intToRoman
Roman::Roman(int value){
    integerValue = value;
    romanNumeral = intToRoman(value);
}
//calls and prints the roman numeral that getRoman returns
void Roman::printRoman() const {
    cout << romanNumeral << endl;
}
// calls and prints the value that getInt returns
void Roman::printDec() const {
    cout << integerValue << endl;
}
// calls getRoman function
string Roman::getRoman() const {
    return romanNumeral;
}
// calls getInt function
int Roman::getInt() const {
    return integerValue;
}

int Roman::romanToInt(const string& roman) {
    unordered_map<char, int> romanDict = { //dictionary of all roman numerals and their numerical values
        {'I', 1}, {'i', 1}, {'V', 5}, {'v', 5}, 
        {'X', 10}, {'x',10}, {'L',50}, {'l',50},
        {'C',100}, {'c',100}, {'D',500}, {'d',500},
        {'M',1000}, {'m',1000}
    };

    int tot = 0;
    int prior = 0;
// loops through the inputed roman numeral from the end to calculate its numerical value
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

    string Roman::intToRoman(int num) {
        pair <int, string> romanPairs[] = { // dictionary for the corresponding roman symbol for different numerical values
            {1000, "M"}, {900, "CM"}, {500, "D"},{400, "CD"}, {100, "C"}, 
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
            {4, "IV"}, {1, "I"}
            };
        string result = "";
        for (const auto& pair : romanPairs){ // loops through the dictionary pairs to append values whern they're larger than the previous
            while (num >= pair.first){
                result += pair.second;
                num -= pair.first;
            }
        }
          return result;  
}
    



