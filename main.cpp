#include <iostream>
#include <exception>
#include <string>

using namespace std;

class invalidCharacterException{};

class invalidRangeException{};

char character(char, int);

int main()
{
    try
    {
        cout << character('a', 1) << endl;
    }
    catch(...)
    {
        cout << "Some exception was thrown for character('a', 1)" << endl;
    }
    try
    {
        cout << character('a', -1) << endl;
    }
    catch(invalidRangeException)
    {
        cout << "invalidRangeException for character('a', -1)" << endl;
    }
    try
    {
        cout << character('Z', -1) << endl;
    }
    catch(...)
    {
        cout << "Some exception was thrown for character('Z', -1)" << endl;
    }
    try
    {
        cout << character('?', 5) << endl;
    }
    catch(invalidCharacterException)
    {
        cout << "invalidCharacterException was thrown for character('?', 5)" << endl;
    }
    try
    {
        cout << character('A', 32) << endl;
    }
    catch(invalidRangeException)
    {
        cout << "invalidRangeException was thrown for character('A', 32)" << endl;
    }
    return 0;
}

char character(char start, int offset)
{
    //Checks if we're starting outside of the alphabet
    if (!isalpha(start))
    {
        throw invalidCharacterException();
    }
    char endChar = start + offset;
    if ((isupper(start) && !isupper(endChar)) || (islower(start) && !islower(endChar)))
    {
        throw invalidRangeException();
    }
    return endChar;
}
