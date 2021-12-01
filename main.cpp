#include <iostream>
#include <exception>
#include <string>

using namespace std;

class invalidCharacterException
{
};

class invalidRangeException
{
};

char character(char, int);

int main()
{
    cout << "Hello world!" << endl;
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
