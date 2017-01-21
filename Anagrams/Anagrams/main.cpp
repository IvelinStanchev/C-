#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isAnagram(string first, string second) {
    std::map<char, int> mapFirstString;
    std::map<char, int> mapSecondString;

    for (int i = 0; i <= 255; i++) {
        mapFirstString[(char)i] = 0;
        mapSecondString[(char)i] = 0;
    }

    int counter;
    for (int i = 0; i < first.length(); i++) {
        counter = mapFirstString[first[i]];
        mapFirstString[first[i]] = ++counter;
    }

    counter = 0;
    for (int j = 0; j < second.length(); j++) {
        counter = mapSecondString[second[j]];
        mapSecondString[second[j]] = ++counter;
    }

    for (int i = 0; i <= 255; i++) {
        if (mapFirstString[(char)i] != mapSecondString[(char)i]) {
            return false;
        }
    }

    return true;
}

void processInput(vector<string> rowWords) {
    vector<string> elementForRemoval;

    for (int i = 0; i < rowWords.size(); i++) {
        for (int j = i + 1; j < rowWords.size(); j++) {
            if (isAnagram(rowWords[i], rowWords[j])) {
                elementForRemoval.push_back(rowWords[j]);
            }
        }

        for (int p = 0; p < elementForRemoval.size(); p++) {
            for (int j = 0; j < rowWords.size(); j++) {
                if (rowWords[j] == elementForRemoval[p]) {
                    rowWords.erase(rowWords.begin() + j);
                }
            }
        }

        elementForRemoval.clear();
    }

    cout<<rowWords.size()<<endl;
}

int main() {
    string input;
    vector<string> rowWords;
    string currentWord = "";

    while(getline(cin, input)) {
        rowWords.clear();

        for (int i = 0; i < input.length(); i++) {
            currentWord = "";
            while (!isspace(input[i]) && i < input.length()) {
                currentWord += input[i];
                i++;
            }

            if (!currentWord.empty()) {
                rowWords.push_back(currentWord);
            }

            //skip white spaces
            while (isspace(input[i]) && i < input.length()) {
                i++;
            }

            if (i < input.length() - 1) {
                i--;
            }
        }

        if (rowWords.size() > 0) {
            processInput(rowWords);
        } else {
            cout<<"0"<<endl;
        }
    }

    return 0;
}
