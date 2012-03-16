#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define MAX_STR_LENGTH 1024

// TAB style: Number of spaces
// 0 means tab chars are used
int tabStyle = 4;

bool emptyString(char str[MAX_STR_LENGTH] )
{
   for ( int ch=0; ch<MAX_STR_LENGTH; ch++)
   {
       char curr = str[ch];

       // ignore whitespace
       if ( curr == ' ' || curr == '\t' )
           continue;
       else if ( curr == '\0' || curr == '\n')
           return true;
       // else we met a non-whitespace char
       else
           return false;
   }
}

// count tabs, even if they are replaced with a number of
// space chars.
int countTabs(char line[MAX_STR_LENGTH])
{
    int ch = 0;
    int numTabs = 0;
    
    if ( tabStyle == 0)
    {
        while ( ch < MAX_STR_LENGTH )
        {
            // count tabs
            if ( line[ch] == '\t' )
                numTabs++;
            // eat whitespace
            else if ( line[ch] == ' ' )
            {}
            // terminate on first real character
            else
                return numTabs;

            ch++;
        }
    }
    else
    {
        int ch = 0;

        while ( true )
        {
            int initch = ch;
            for(; ch < initch+tabStyle; ch++)
            {
                // terminate on anything not space or if 
                // we run out of string
                if ( line[ch] != ' ' || ch > MAX_STR_LENGTH-1)
                    return numTabs;
            }
            numTabs++;
        }
    }
}

int main(int argc, char *argv[])
{
    int tabLevel = 0;

    while ( cin.eof() == false )
    {
        char str[MAX_STR_LENGTH];
        cin.getline(str, MAX_STR_LENGTH);
    
        // check if string is whitespace only
        // if it is, discard it
        if ( emptyString(str) )
            continue;

        int newTabLevel = countTabs(str);

        // get difference in tab level
        int diff = newTabLevel - tabLevel;

        if ( diff == 0 )
            cout << str << "\n";
        else if ( diff > 0 )
        {
            for(int i=0; i<diff; i++)
                cout << "{\n";
            
            cout << str << "\n";
        }
        else if ( diff < 0 )
        {
            for(int i=0; i>diff; i--)
                cout << "}\n";
            
            cout << str << "\n";
        }

        tabLevel = newTabLevel;
    }

    // if there are dangling closing brackets, add them in the end
    if ( tabLevel > 0 )
    {
        for(int i=0; i<tabLevel; i++)
            cout << "}";

        cout << "\n";
    }

}
