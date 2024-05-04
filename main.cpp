// Kareem

// Chapter20ProgrammingAssignment

// 5/3/2024
#include <iostream>
#include <string>
#include "DisplayMenu.h"
#include "BinaryTree.h"
#include <limits>
using namespace std;


int main() {
    int menuChoice; // make a menuchoice var
    DisplayMenu m1; // create new objects
    BinaryTree b1;

    do {
        m1.menuMsg();
        // get the user's menu choice
        while (!(cin >> menuChoice)) {
            // validate that the input is a number
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a number only please. " << endl;
        }

        // switch to handle the user's choice.

        switch (menuChoice) {
            case 1: {
                int input;
                cout << "Please enter the number you want to insert: " << endl;
                while (!(cin >> input)) {
                    // validate that the input is a number
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Enter a number only please. " << endl;
                }
                cout << endl;
                // once input is validated, call method
                cout << "Adding..." << endl;
                b1.insertNode(input);
                break;
            }
            case 2: {
                b1.display();
                break;
            }

            case 3: {
                b1.displayNumberOfLeafs();
                break;
            }
            case 4: {

                break;
            }
            case 5: {


                break;
            }
            case 6: {
                // print exit statement
                cout << "Exiting..." << endl;
                cout << "Thanks for using the menu system and have a nice day." << endl;
                exit(0);
            }
            default: {
                // handle invalid menu option entries
                cout << "That Is Not A Valid Option, Please Choose An Option From The Numbered Menu Below: "
                     << endl;
                cout << endl;
                break;
            }
        }

    } while (menuChoice != 6); // continue presenting the menu until the user chooses to exit
    return 0;
}