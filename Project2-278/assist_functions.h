// Copyright Robert Zank 2023

#ifndef ASSIST_FUNCTIONS_H_
#define ASSIST_FUNCTIONS_H_

#include <string>

void ShortenSpace(std::string& input);
void ReplaceExclamation(std::string& input);
int GetNumOfWords(const std::string input); 
int FindText(const std::string find, const std::string inputTxt);
int GetNumOfNonWSCharacters(const std::string input);
char PrintMenu();
void ExecuteMenu(const char& userEntry, std::string& inputTxt);

#endif  // ASSIST_FUNCTIONS_H_
