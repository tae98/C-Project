#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::string;
// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {

private:
    std::string solution;
    int value;

public:

    CountdownSolution() : solution(), value(0) {}

    CountdownSolution(const std::string& solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }

    const std::string& getSolution() const {
        return solution;
    }

    int getValue() const {
        return value;
    }

};

// Do not edit above this line

// TODO: write code here:
double evaluateCountdown(string mathExpression) {
    vector<string> listOfWord;
    string word = "";

    for (int i = 0; i < mathExpression.size(); ++i) {
        //get 1 character from string
        char a = mathExpression[i];
        if (a == ' ') {
            listOfWord.push_back(word);
            word = "";
        }
        else {
            word += a;
            if (i == mathExpression.size() - 1) {
                listOfWord.push_back(word);
            }
        }
    }
    stack<double> listOfNumber;
    for (int i = 0; i < listOfWord.size(); ++i) {
        string tokken = listOfWord[i];
        if (tokken == "+" || tokken == "/" || tokken == "*" || tokken == "-") {
            double a = listOfNumber.top();
            listOfNumber.pop();
            double b = listOfNumber.top();
            listOfNumber.pop();

            if (tokken == "+") {
                listOfNumber.push(b + a);
            }
            else if (tokken == "/") {
                listOfNumber.push(b / a);
            }
            else if (tokken == "*") {
                listOfNumber.push(b * a);
            }
            else if (tokken == "-") {
                listOfNumber.push(b - a);
            }
        }
        else {
            listOfNumber.push(stod(tokken));
        }
    }
    return listOfNumber.top();
}

// Do not edit below this line


#endif
