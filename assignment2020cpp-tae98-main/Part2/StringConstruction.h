

#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <iostream>
#include <string>
#include <vector>
using std::string;


// TODO: your code goes here:
std::vector<char> appendList;
std::string clones;
std::string word;
int totalCost;
std::string target;

/*
make a appendList which stores unique alphabets
*/
void makeAppendList(std::string target) {
    for (int i = 0; i < target.size(); i++) {
        if (appendList.size() > 0) {
            int cnt = 0;
            for (int j = 0; j < appendList.size(); j++) {
                if (target[i] == appendList[j]) {
                    cnt = cnt + 1;
                }
            }
            if (cnt == 0) {
                appendList.push_back(target[i]);
            }
        }
        else {
            appendList.push_back(target[i]);
        }
    }
}

/*
print out all in appendList
*/
void printAppendList() {
    for (int i = 0; i < appendList.size(); i++) {
        if (i != appendList.size() - 1) {
            
        }
        else {
           
        }
    }
}

/*
return clone
*/
std::string getClone() {
    return clones;
}

/*
return the total cost
*/
int getTotalCost() {
    return totalCost;
}

/*
check if clone is available.
This has to meet the condition as below.
The first alphabet in clone must be equal to the given
*/
bool isCloneAvialble(char c) {
    if (clones.size() == 0) {
        return false;
    }
    else {
        for (int i = 0; i < clones.size(); i++) {
            if (c == clones[i]) {
                return true;
            }
        }
        return false;
    }// else
}

/*
do append
*/
void doAppend(char c) {
    for (int i = 0; i < appendList.size(); i++) {
        if (c == appendList[i]) {
            word = word + c;
            clones = clones + c;
            break;
        }
    }
   
}

/*
do clone
*/
void doClone(std::string str) {
    word = word + str;
    clones = clones + str;
    

}

/*
return a string which can be used as clone
*/
std::string cloneHelper(int target_index) {
    std::string temp = "";
    // 1. collect all possible temps
    // 2. pick the longest one and save it as temp
    for (int i = 0; i < clones.size(); i++) {
        if (::target[target_index] == clones[i]) {
            int k_index = 0;
            while (::target[target_index + k_index] == clones[i + k_index] && (target_index + k_index <= ::target.size() - 1 && i + k_index <= clones.size() - 1)) {
                temp = temp + clones[i + k_index];
                k_index = k_index + 1;
            }
            if (k_index != 0) {
                break;
            }
        }
    } // for i
   
    return temp;
}

/*
initialise all members
*/
void ready(std::string target) {
    word = "";
    clones = "";
    appendList = {};
    totalCost = 0;
    ::target = target;
}


int stringConstruction(std::string target, int cloneCost, int appendCost) {
    ready(target);
    makeAppendList(target);

    for (int i = 0; i < target.size(); i++) {
        if (!isCloneAvialble(target[i])) {  
            doAppend(target[i]);
            totalCost = totalCost + appendCost;
           

        }
        else {
            std::string output = cloneHelper(i);
            if (output.size() == 1) {
                if (appendCost < cloneCost) {
                    doAppend(target[i]);
                    totalCost = totalCost + appendCost;                    
                }
                else {
                    doClone(output);
                    i = i + output.size() - 1;
                    totalCost = totalCost + cloneCost;
                                    }
            }
            else {
                doClone(output);
                i = i + output.size() - 1;
                totalCost = totalCost + cloneCost;
                          }
        } 
    }
    printAppendList();
       return totalCost;
}

// do not write or edit anything below this line

#endif
