#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    int randomNum;
    srand(time(NULL));
    randomNum = rand() % 30 + 1;
    //variable read into
    string firstName;
    string nameInput;
    string temp;
    //array
    vector<string> names;

    ifstream nameFile("../txt_files/names.txt");
    string here;
    int i = 0;
    int countdown = randomNum;//testing
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
        cin >> nameInput;

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