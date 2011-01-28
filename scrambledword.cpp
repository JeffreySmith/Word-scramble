#include "scrambledWord.h"
#include <iostream>
#include <ctime>
using namespace std;
scrambledWord::scrambledWord()
{
    srand(time(NULL));
}

string scrambledWord::getWord()
{
    return regularString;
}
string scrambledWord::getScrambledWord()
{
    return scrambledString;
}
void scrambledWord::setWord(std::string word)
{
    regularString=word;
    wordLength=regularString.length();
    bool positions[regularString.length()];
    int counter=regularString.length();
    for(int i=0;i<regularString.length();i++)
    {
            positions[i]=true;
    }



    while(counter>0 && regularString!=scrambledString)
    {

            int randNum=rand()%regularString.length();
            if(positions[randNum])
            {
                    positions[randNum]=false;
                    scrambledString+=regularString[randNum];
                    counter--;
            }
    }
}
