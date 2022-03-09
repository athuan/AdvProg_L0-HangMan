#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "hangman.h"
#include <string>

using std::string;

struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool verifyUpdateSecretWord(string secretWord, const char ch, const string word, string answer) {
    updateSecretWord(secretWord, ch, word);
    return secretWord == answer;
}

bool verifyUpdateEnteredChars(const char ch, string chars, string answer) {
    updateEnteredChars(ch, chars);
    return chars == answer;
}

int verifyUpdateIncorrectGuess(int incorrectGuess) {
    updateIncorrectGuess(incorrectGuess);
    return incorrectGuess;
}

bool verifyGenerateHiddenCharacters(string secretWord, string answer) {
    string myAnswer = generateHiddenCharacters(secretWord);
    return myAnswer == answer;
}

void runTestLoop(TestStruct testCases[], int testSize){
    for (int i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << "PASSED!";
        }
        else
        {
            std::cout << "FAILED!\n";
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testUpdateSecretWord);
    CPPUNIT_TEST(testUpdateEnteredChars);
    CPPUNIT_TEST(testUpdateIncorrectGuess);
    CPPUNIT_TEST(testGenerateHiddenCharacters);
    CPPUNIT_TEST(successTestExit);
    CPPUNIT_TEST_SUITE_END();

    public:
      void setUp(void) {}
      void tearDown(void) {}

    protected:
      void testUpdateSecretWord(void) {
        int testSize = 5;
        std::string sharedName = "\n[checkUpdateSecretWord test] ";
        TestStruct checkUpdateSecretWord[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyUpdateSecretWord("-", 'a', "a", "a"), 
                true,
                "Character 'a' exist in secret word. Should return string 'a'."
            },
            {
                sharedName + "test normal 2", 
                verifyUpdateSecretWord("--t", 'c', "cat", "c-t"), 
                true,
                "Character 'c' exist in secret word. Should return string 'c-t'."
            },
            {
                sharedName + "test normal 3", 
                verifyUpdateSecretWord("ca---ag-", 'r', "carriage", "carr-ag-"), 
                true,
                "Character 'r' exist in secret word. Should return string 'carr-ag-'."
            },
            {
                sharedName + "test normal 4", 
                verifyUpdateSecretWord("s-iss--s", 's', "scissors", "s-iss--s"), 
                true,
                "Character 's' existed in secret word. Should return string 's-iss--s'."
            },
            {
                sharedName + "test normal 5", 
                verifyUpdateSecretWord("circumsta-ce", 'n', "circumstance", "circumstance"), 
                true,
                "Character 'n' exist in secret word. Should return string 'circumstance'."
            },
        };
        runTestLoop(checkUpdateSecretWord, testSize);
      }

    void testUpdateEnteredChars(void) {
        int testSize = 5;
        std::string sharedName = "\n[checkUpdateEnteredChars test] ";
        TestStruct checkUpdateEnteredChars[testSize]  = 
        {
          {
              sharedName + "test normal 1", 
              verifyUpdateEnteredChars('a', "s ", "s a "), 
            true,
            "Character 'a' is correct character. Should return string 's a '."
        },
        {
            sharedName + "test normal 2", 
            verifyUpdateEnteredChars('a', "a ", "a a "), 
            true,
            "Character 'a' is correct character. Should return string 'a a '."
        },
        {
            sharedName + "test normal 3", 
            verifyUpdateEnteredChars('r', "c a i a g e ", "c a i a g e r "), 
            true,
            "Character 'r' is correct character. Should return string 'c a i a g e r '."
        },
        {
            sharedName + "test normal 4", 
            verifyUpdateEnteredChars('o', "s c i ", "s c i o "), 
            true,
            "Character 'o' is correct character. Should return string 's c i o '."
        },
        {
            sharedName + "test normal 5", 
            verifyUpdateEnteredChars('n', "", "n "), 
            true,
            "Character 'n' is correct character. Should return string 'n '."
        },
      };
      runTestLoop(checkUpdateEnteredChars, testSize);
    }

    void testUpdateIncorrectGuess(void) {
        int testSize = 5;
        std::string sharedName = "[checkUpdateIncorrectGuess test] ";
        std::cout << "\n>> Testing the UpdateIncorrectGuess() function"<< std::endl;
        for(int incorrectGuess = 0; incorrectGuess < 5; incorrectGuess++){
            // TestStruct res;
            int youGot = verifyUpdateIncorrectGuess(incorrectGuess);
            int expected = incorrectGuess+1;
            if (youGot == expected){
                std::cout << sharedName << " test normal 1: "<< "PASSED!"<< std::endl; 
            }else{
                std::cout << sharedName << " test normal 1: "<< "FAILED!"<< std::endl;
                std::cout << "The current mistake is "<< incorrectGuess<< "! Got: " << youGot << ", Expected: "<< expected << " !"; 
                exit(1);
            }
        }
    }

    void testGenerateHiddenCharacters(void) {
        int testSize = 5;
        std::string sharedName = "\n[checkGenerateHiddenCharacters test] ";
        TestStruct checkGenerateHiddenCharacters[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyGenerateHiddenCharacters("a", "-"), 
                true,
                "Secret Word is 'a'. Should return string '-'."
            },
            {
                sharedName + "test normal 2", 
                verifyGenerateHiddenCharacters("cat", "---"), 
                true,
                "Secret Word is 'cat'. Should return string '---'."
            },
            {
                sharedName + "test normal 3", 
                verifyGenerateHiddenCharacters("carriage", "--------"), 
                true,
                "Secret Word is 'carriage'. Should return string '--------'."
            },
            {
                sharedName + "test normal 4", 
                verifyGenerateHiddenCharacters("scissors", "--------"), 
                true,
                "Secret Word is 'scissors'. Should return string '--------'."
            },
            {
                sharedName + "test normal 5", 
                verifyGenerateHiddenCharacters("circumstance", "------------"), 
                true,
                "Secret Word is 'circumstance'. Should return string '------------'."
            },
        };
        runTestLoop(checkGenerateHiddenCharacters, testSize);
    }   

    void successTestExit(void) {
        std::cout << "all tests passed! \n";
        exit(0);
    }   
};  


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}
