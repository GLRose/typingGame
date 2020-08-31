#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    //variable read into
    string firstName;
    //array
    vector<string> names;

    ifstream nameFile("names.txt");
    string here;
    int i = 0;
    cout << "Enter a string: " << endl;
    cin >> firstName;
    if (nameFile.is_open())
    {
        while (nameFile >> here)
        {
            names.push_back(here);
            if (firstName.compare(names[i]) == 0)
            {
                cout << "Match" << " at index: " << i;
            }
            i++;
        }
    }
}