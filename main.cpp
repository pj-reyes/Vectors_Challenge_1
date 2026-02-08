/*
Precious Reyes
2/7/25
Purpose: allows the user to enter a number and display the corresponding day of the week or month
of the year using constant string arrays
Assignment - Lab Activities: Arrays & Vectors
Program - Challenge 1: Date Utilities with const Arrays
*/

#include <iostream>
#include <string>
#include <limits>

// Global const arrays
// provides a lookup table from a number to the matching day/month name
const std::string daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday"};

const std::string monthsOfTheYear[12] = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

// Displays the menu options
void displayMenu()
{
    std::cout << "\n1. Get Day Name by Number (1-7)\n";
    std::cout << "2. Get Month Name by Number (1-12)\n";
    std::cout << "3. Quit\n";
}

// Prompts until user enters a valid integer
int getValidInt(const std::string& prompt)
{
    int input;

    // displays prompt to user
    std::cout << prompt;

    while (!(std::cin >> input))
    {
        std::cout << "Invalid input. Please enter valid a number.\n";

        // resets input stream and discard invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return input;
}

// Gets user's valid menu choice (1-3)
int getMenuChoice()
{
    int choice = getValidInt("Enter your choice (1-3): ");

    while (choice < 1 || choice > 3)
    {
        std::cout << "Invalid choice.\n";
        choice = getValidInt("Enter a valid choice (1-3): ");
    }

    return choice;
}

// Main program loop
int main()
{
    int choice;

    do
    {
        // shows menu and gets valid menu choice (1-3)
        displayMenu();
        choice = getMenuChoice();

        // switch processes the user's menu choice
        switch (choice)
        {
        case 1:
            {
                // option 1: day name lookup (1-7)
                int dayNum = getValidInt("Enter a day number (1-7): ");

                // validates day range; arrays are 0-indexed, so 1-7 -> 0-6
                if (dayNum >= 1 && dayNum <= 7)
                {
                    std::cout << daysOfTheWeek[dayNum - 1] << std::endl;
                }
                else
                {
                    std::cout << "Invalid Day" << std::endl;
                }
                break;
            }
        case 2:
            {
                // option 2: month name lookup (1-12)
                int monthNum = getValidInt("Enter a month number (1-12): ");

                // validates month range; arrays are 0-indexed, so 1-12 -> 0-11
                if (monthNum >= 1 && monthNum <= 12)
                {
                    std::cout << monthsOfTheYear[monthNum - 1] << std::endl;
                }
                else
                {
                    std::cout << "Invalid Month" << std::endl;
                }
                break;
            }
        case 3:
            {
                // option 3: quit
                std::cout << "Exiting now, goodbye." << std::endl;
                break;
            }
        default:
            {
                // not necessary (getMenuChoice forces 1-3), but added for extra safety
                std::cout << "Error. Please try again." << std::endl;
                break;
            }
        }
    }
    while (choice != 3); // loops until user chooses Quit (option 3)

    return 0; // Ends program
}