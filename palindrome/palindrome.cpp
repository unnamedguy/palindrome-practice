// palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, uint32_t> letters;
    int n;
    string str;

    cin >> n >> str;
    for (int i = 0; i < n; i++)
        letters.find(str[i]) == letters.end() ? letters[str[i]] = 1 : letters[str[i]] += 1;

    str = "";

    map<char, uint32_t>::iterator firstodd = letters.end();
    for (map<char, uint32_t>::iterator i = letters.begin(); i != letters.end(); i++)
    {
        str += string(i->second / 2, i->first);
        if (i->second % 2)
        {
            firstodd = i;
            break;
        }
    }

    if (firstodd == letters.end())
    {
        for (int i = str.size() - 1; i >= 0; i--)
            str += str[i];
    }
    else
    {
        char fOddCh = firstodd->first;

        if (++firstodd != letters.end())
        {
            for (map<char, uint32_t>::iterator i = firstodd; i != letters.end(); i++)
            {
                if (i->second % 2) i->second--;
                str += string(i->second / 2, i->first);
            }
        }

        str += fOddCh;

        for (int i = str.size() - 2; i >= 0; i--)
            str += str[i];
    }

    cout << str << '\n';
}