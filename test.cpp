#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    //Array implementation
    // string names[5];

    // ifstream nameFile("names.txt");

    // if (nameFile.is_open())
    // {
    //     for(int i=0; i < sizeof(names); i++)
    //     {
    //         nameFile >> names[i];
    //         cout << names[i];
    //     }
    // }
    //end

    //Vector implementation
    vector<string> names;

    ifstream nameFile("names.txt");
    string here;
    int i = 0;
    if (nameFile.is_open())
    {
        while(nameFile >> here)
        {
            names.push_back(here);
            cout << names[i] << "\n";
            i++;
        }
    }
}
