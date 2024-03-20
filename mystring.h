#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <iostream>

using namespace std;


int GetLen(const char*);

class mString
{
    char* text;
    int len = 0;

public:

    mString();

    int Length();
    char* getText();

    char& operator[](int);

    mString& operator=(mString&);
    mString& operator=(const char*);

    mString& operator+(mString&);
    mString& operator+(const char*);

    mString& operator+=(mString&);
    mString& operator+=(const char*);

    int Split(char separator,mString*&);
    void RemoveAt(int startIndex, int endIndex);

};



ostream& operator<<(ostream&, mString&);

#endif // MYSTRING_H_INCLUDED
