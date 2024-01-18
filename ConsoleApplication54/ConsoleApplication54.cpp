#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string combineWords(const string& first, const string& second) {
    return first.substr(0, first.length() - 3) + second;
}

int main() {
    setlocale (LC_ALL, "");
    ifstream dictionaryFile("dictionary.txt");

    ifstream dictionaryFile("C:/Users/ваше_имя_пользователя/Desktop/dictionary.txt");

    if (!dictionaryFile.is_open()) {
        cerr << "Помилка відкриття файлу словника.\n";
        return 1;
    }

    vector<string> words;
    string word;

    while (dictionaryFile >> word) {
        words.push_back(word);
    }

    dictionaryFile.close();

    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cerr << "Помилка відкриття файлу для запису результатів.\n";
        return 1;
    }

    for (const auto& firstWord : words) {
        for (const auto& secondWord : words) {
            if (firstWord != secondWord && firstWord.substr(firstWord.length() - 3) == secondWord.substr(0, 3)) {
                string result = combineWords(firstWord, secondWord);
                cout << result << endl;
                outputFile << result << endl;
            }
        }
    }

    outputFile.close();

    cout << "Результати записано в output.txt\n";

    return 0;
}
