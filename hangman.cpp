#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

// Function 1: Generate a random integer number between min and max.
int generateRandomNumber(const int min, const int max)
{
    //srand((int)time(0)); // It is a bug if putting this line here.
    // Your code here
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

// Function 2: Check if a character is in a string or not.
bool isCharInWord(const char ch, const string& word)
{
    // Your code here
}

// Function 3: Return a lowercase word in a certain position of a list.
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    // Your code here
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

// Function 4: Update the secret word if the character ch is in the answer word.
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // Your code here
}

// Function 5 + 6 +7: processData
// If ch in word:
//     update secretWord
//     update correctChars
// Else:
//     update incorrectGuess
//     update incorrectChars

// Function 5: this function is used to update correctChars and incorrectChars
void updateEnteredChars(const char ch, string& chars){
    // Your code here
}

// Function 6: Update incorrectGuess
void updateIncorrectGuess(int& incorrectGuess){
    // Your code here
}

// Function 7: processData
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    // Your code here
}

// Function 8: Based on secretWord's length, generate hidden characters in form of "---"
string generateHiddenCharacters(string secretWord){
    // Your code here
}
