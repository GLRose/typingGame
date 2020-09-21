#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <math.h>
#include <chrono>

using namespace std;

int main()
{
    //initialize clock from chronos to use timer
    using Clock = std::chrono::high_resolution_clock;
    //our first random num for number of names that the user will input
    int randomNum;

    //generates random number as time allotted for user input
    double randomNumTimer;
    const int max = 3000;
    const int min = 1500;
    srand(time(NULL));
    randomNum = rand() % 30 + 1;
    randomNumTimer = rand() % (max - min + 1) + min;
    string firstName;
    string nameInput;
    string temp;
    //array
    vector<string> names;

    ifstream nameFile("../txt_files/names.txt");
    string here;
    int i = 0;
    int countdown = randomNum; //testing
    int correct = 0;
    int wrong = 0;

    if (nameFile.is_open())
    {
        while (nameFile >> here)
        {
            names.push_back(here);
            i++;
        }
    }
    do
    {
        //the strings are already stored in our vector after the loop
        temp = names[randomNum];
        cout << "Name: " << temp << "\n"
             << "Type the name quick!"
             << "\n";
        auto start = Clock::now();
        cin >> nameInput;
        auto end = Clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Your input took " << ms << " milliseconds" << std::endl;

        if (ms > randomNumTimer)
        {
            cout << "You lose"
                 << " "
                 << "the time limit was: "
                 << " " << randomNumTimer << "ms" << endl;
            cout << "You got: " << correct << " "
                 << "correct!"
                 << " "
                 << "and"
                 << " " << wrong << " "
                 << "wrong!"
                 << " " << endl;
            return 0;
        }
        //for compare function 0 means "match"
        if (nameInput.compare(temp) == 0)
        {
            cout << "CORRECT"
                 << "\n";
            correct++;
        }
        else
        {
            cout << "Wrong"
                 << "\n";
            wrong++;
        }
        cout << "You got: " << correct << " "
             << "correct!"
             << " "
             << "and"
             << " " << wrong << " "
             << "wrong!"
             << " " << endl;
        countdown--;
        randomNum = rand() % 30 + 1;
    } while (countdown > 0);
}