// Copyright Robert Zank

#include <iostream>
#include <vector>
#include <string>
#include "assist_functions.h"


/* Current entry difference from last entery:
    none
*/

int main() {
    // Get the text from the user
    std::string inputTxt;
    std::cout << "Enter a sample text:\n" << std::endl;
    getline(std::cin, inputTxt);

    // Output what the user etered
    std::cout << "You entered: ";
    std::cout << inputTxt << "\n" << std::endl;

    // char for user selection
    char option = ' ';

    // Call ExecuteMenu()
    while (option != 'q') {
        option = PrintMenu();
        std::cout << "\nChoose an option:" << std::endl;
        ExecuteMenu(option, inputTxt);
    }

    return 0;
}
