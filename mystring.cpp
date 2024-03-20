#include "mystring.h"

mString::mString()
{
    len = 0;
    text = new char[1];
    text[0] = '\0';
}
int mString::Length()
{
    return len;
}
char* mString::getText()
{
    return text;
}


int GetLen(const char* str)
{
    int len = 0;
    for(len = 0; str[len] != '\0'; len++);
    len++;

    return len;
}

char& mString::operator[](int index)
{
    if(index < len && index >= 0)
    {
        return text[index];
    }
}

mString& mString::operator=(mString& str)
{
    if(text != 0)
        delete[] text;

    int tLen = str.Length()+1;

    text = new char[tLen];

    for(int i = 0; i<tLen-1;i++)
    {
        text[i] = str[i];
    }
    text[tLen-1] = '\0';
    len = tLen-1;
    return *this;
}
mString& mString::operator=(const char* str)
{
    if(text != 0)
        delete[] text;

    int tLen = GetLen(str);

    text = new char[tLen];

    for(int i = 0; i<tLen-1;i++)
    {
        text[i] = str[i];
    }
    text[tLen-1] = '\0';
    len = tLen-1;
    return *this;
}

mString& mString::operator+(mString& str)
{
    int sLen = str.Length();

    char* temp = new char[sLen+len];

    int ind = 0;
    for(int i = 0; i<len; i++)
    {
        temp[ind] = text[i];
        ind++;
    }
    for(int i = 0; i<sLen; i++)
    {
        temp[ind] = str[i];
        ind++;
    }

    delete[] text;

    len =sLen+len;
    text = new char[len+1];

    for(int i = 0; i<len; i++)
    {
        text[i] = temp[i];
    }
    text[len] = '\0';

    return *this;
}
mString& mString::operator+(const char* str)
{
    int sLen = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        sLen++;
    }

    char* temp = new char[sLen+len];

    int ind = 0;
    for(int i = 0; i<len; i++)
    {
        temp[ind] = text[i];
        ind++;
    }
    for(int i = 0; i<sLen; i++)
    {
        temp[ind] = str[i];
        ind++;
    }

    delete[] text;

    len =sLen+len;
    text = new char[len+1];

    for(int i = 0; i<len; i++)
    {
        text[i] = temp[i];
    }
    text[len] = '\0';

    return *this;
}

mString& mString::operator+=(mString& str)
{
    int sLen = str.Length();

    char* temp = new char[sLen+len];

    int ind = 0;
    for(int i = 0; i<len; i++)
    {
        temp[ind] = text[i];
        ind++;
    }
    for(int i = 0; i<sLen; i++)
    {
        temp[ind] = str[i];
        ind++;
    }

    delete[] text;

    len =sLen+len;
    text = new char[len+1];

    for(int i = 0; i<len; i++)
    {
        text[i] = temp[i];
    }
    text[len] = '\0';

    return *this;
}
mString& mString::operator+=(const char* str)
{
    int sLen = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        sLen++;
    }

    char* temp = new char[sLen+len];

    int ind = 0;
    for(int i = 0; i<len; i++)
    {
        temp[ind] = text[i];
        ind++;
    }
    for(int i = 0; i<sLen; i++)
    {
        temp[ind] = str[i];
        ind++;
    }

    delete[] text;

    len =sLen+len;
    text = new char[len+1];

    for(int i = 0; i<len; i++)
    {
        text[i] = temp[i];
    }
    text[len] = '\0';

    return *this;
}

int mString::Split(char separator, mString*& out)
{
    int i = 0;
    int seps = 1;
    int* partLengths = new int[256];
    partLengths[0] = 1;

    int tLen = GetLen(text);

    for(int i = 0; i<len; i++)
    {
        if(text[i] != separator && text[i+1]==separator)
        {
            partLengths[seps] = 1;
            seps++;
        }
        else if(text[i] != separator)
        {
            partLengths[seps-1]++;
        }
    }

    char** res = new char*[seps];
    int sIndex = 0;
    int partIndex = 0;

    res[0] = new char[partLengths[0]+1];

    for(int i = 0; i<len; i++)
    {
        if(text[i] != separator)
        {
            res[sIndex][partIndex] = text[i];
            cout<<res[sIndex][partIndex]<<" ";
            partIndex++;
        }

        if(text[i] != separator && text[i+1]==separator)
        {
            res[sIndex][partIndex] = '\0';
            sIndex++;
            res[sIndex] = new char[partLengths[sIndex]+1];
            partIndex = 0;
        }
    }

    res[sIndex][partIndex] = '\0';

    out = new mString[seps];

    for(int i = 0; i<seps; i++)
    {
        out[i]=res[i];
    }

    delete[] res;
    return seps;
}

void mString::RemoveAt(int startIndex, int endIndex)
{
    int s = (len-((endIndex-startIndex)+1))+2;

    char* t = new char[s];

    int ind = 0;

    for(int i = 0; i<len+1; i++)
    {
        if(i < startIndex || i > endIndex)
        {
            t[ind] = text[i];
            ind++;
        }
    }
    t[s-1] = '\0';

    delete[] text;
    text = t;
    len = s-1;
}


ostream& operator<<(ostream& os, mString& str)
{
    os << str.getText();
    return os;
}
