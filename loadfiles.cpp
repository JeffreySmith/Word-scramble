#include "loadfiles.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
loadFiles::loadFiles()
{

    ifstream file("wordlist.txt");
    if(file.is_open())
    {

        while(!file.eof())
        {
            getline(file,line);
            parsedText.push_back(line);

        }
        for(int i=0;i<parsedText.size();i++)
        {
            cout<<parsedText[i]<<endl;
        }
        file.close();
    }
    else
    {
        cout<<"file not found\n";
    }

}
