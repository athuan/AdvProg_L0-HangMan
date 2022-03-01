#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

// Test 1.
int generateRandomNumber(const int min, const int max)
{
    //srand((int)time(0)); // It is a bug if putting this line here.
    return rand() % (max - min + 1) + min;
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile (filePath);
    if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }

    //while ( getline (wordFile, word) ){  // Thong thuong doc tung line. 
                                           // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
                                // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        //cout << word << '\n';
    }
    wordFile.close();

    return wordList;
}

// Test 2.
bool isCharInWord(const char ch, const string& word)
{
  return (word.find_first_of(ch) != string::npos);
    /*
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            return true;
        }
    }
    return false;
    */
}

// Test 3.
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    if (wordList.empty()) return "";

    string word = wordList[index];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

// Test 4.
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
}

// Test 5.
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    if (isCharInWord(ch, word)) {
        updateSecretWord(secretWord, ch, word);
        correctChars +=  ch; correctChars += " "; 
    } else {
        incorrectGuess += 1;
        incorrectChars += ch; incorrectChars += " ";
    }
}

// Test 6.
string generateHiddenCharacters(string secretWord){
    string hiddenCharacters(secretWord.length(), '-');
    return hiddenCharacters;
}