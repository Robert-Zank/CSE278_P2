// Copyright Robert Zank

/* Define your functions here. */
#include <iostream>
#include <vector>
#include <string>
#include "assist_functions.h"

void ShortenSpace(std::string& input) {
    std::string result;
    bool previousSpace = false;

    for (char c : input) {
        if (c != ' ') {
            result += c;
            previousSpace = false;
        } else {
            if (!previousSpace) {
                result += c;
            }
            previousSpace = true;
        }
    }

    input = result;
}

void ReplaceExclamation(std::string& input) {
    for (unsigned int i = 0; i < input.length(); i++) {
        if (input.at(i) == '!') {
            input.at(i) = '.';
        }
    }
}

int GetNumOfWords(const std::string input) {
    int count = 0;
    // bool to check if the current index is in a word
    bool in = false;

    for (unsigned int i = 0; i < input.length(); i++) {
        // if at index i isnt a whitespace, we are in a word
        if (input.at(i) != ' ') {
            in = true;
        } else {  // if at index i is a character
            if (in) {  // and we are in a word
                count++;  // add one
                /* set in to false, 
                because counted the first letter in the current word */ 
                in = false;
            }
        }
        // add 1 if the input doesnt end in whitespace
        if (in && i == input.length() - 1) {
            count++;
        }
    }
    return count;
}

int FindText(const std::string find, const std::string inputTxt) {
    std::vector<std::string> words;
    std::string word;

    for (char c : inputTxt) {
        if (isalpha(c) || isdigit(c) || c == '\'') {
            // If the character is a letter, digit, or an apostrophe, add it to the current word.
            word += tolower(c);
        } else if (!word.empty()) {
            // If we've collected a word, add it to the vector and reset the word variable.
            words.push_back(word);
            word.clear();
        }
    }

    // Handle the last word in the text.
    if (!word.empty()) {
        words.push_back(word);
    }

    std::vector<std::string> keys;
    word.clear();  // Reset word for the key to find.

    for (char c : find) {
        if (isalpha(c) || isdigit(c) || c == '\'') {
            // If the character is a letter, digit, or an apostrophe, add it to the current word.
            word += tolower(c);
        } else if (!word.empty()) {
            // If we've collected a word, add it to the vector and reset the word variable.
            keys.push_back(word);
            word.clear();
        }
    }

    // Handle the last word in the find key.
    if (!word.empty()) {
        keys.push_back(word);
    }

    int count = 0;
    int keySize = keys.size();

    for (size_t i = 0; i < words.size(); i++) {
        if (i + keySize <= words.size()) {
            bool isMatch = true;
            for (size_t j = 0; j < keySize; j++) {
                if (words[i + j] != keys[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                count++;
                i += keySize - 1;  // move the index to the end of the matched phrase.
            }
        }
    }

    return count;
}

int GetNumOfNonWSCharacters(const std::string input) {
    // loop thru the string
    int count = 0;
    for (unsigned int i = 0; i < input.length(); i++) {
        if (input.at(i) != ' ') {
            // count each character that isn't whitespace
            count++;
        }
    }
    return count;
}

char PrintMenu() {
    char entry;

    std::cout << "MENU" << std::endl;
    std::cout << "c - Number of non-whitespace characters" << std::endl;
    std::cout << "w - Number of words" << std::endl;
    std::cout << "f - Find text" << std::endl;
    std::cout << "r - Replace all !'s" << std::endl;
    std::cout << "s - Shorten spaces" << std::endl;
    std::cout << "q - Quit" << std::endl;

    std::cin >> entry;

    return entry;
}

void ExecuteMenu(const char& userEntry, std::string& inputTxt) {
    if (userEntry == 'c') {
        std::cout << "Number of non-whitespace characters: " <<
            GetNumOfNonWSCharacters(inputTxt) << std::endl;
    } else if (userEntry == 'w') {
        std::cout << "Number of words: " << GetNumOfWords(inputTxt) << std::endl;
    } else if (userEntry == 'f') {
        std::cin.ignore();
        std::string find;
        std::cout << "Enter a word or phrase to be found: " << std::endl;
        getline(std::cin, find);
        std::cout << "\"" << find << "\"" << " instances: "
            << FindText(find, inputTxt) << std::endl;
    } else if (userEntry == 'r') {
        ReplaceExclamation(inputTxt);
        std::cout << "Edited text: " << inputTxt << std::endl;
    } else if (userEntry == 's') {
        ShortenSpace(inputTxt);
        std::cout << "Edited text: " << inputTxt << std::endl;
    } else {
        exit(0);
    }
}
