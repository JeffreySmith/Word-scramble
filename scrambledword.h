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
    void setCategory(std::string);
    std::string getCategory();
private:
    std::string regularString;
    std::string scrambledString;
    std::string category;
};

#endif // SCRAMBLEDWORD_H
