#ifndef SCRAMBLEDWORD_H
#define SCRAMBLEDWORD_H
#include <iostream>
class scrambledWord
{
public:
    scrambledWord();
    std::string getWord();
    std::string getScrambledWord();
    void setWord(std::string);
    int wordLength;
private:
    std::string regularString;
    std::string scrambledString;
};

#endif // SCRAMBLEDWORD_H
