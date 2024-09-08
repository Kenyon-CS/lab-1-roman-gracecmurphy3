#include "roman.h"
#include <unordered_map>

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
}


