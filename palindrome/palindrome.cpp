// palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <map>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

bool checkWord(const char* word, int n);


int main()
{
    map<char, uint32_t> letters;
    int n;
    string str = "";

    
    n = fs::file_size("E:\\Projects\\Pract\\test11.txt");

    if (n == 0 && n > 100000)
    {
        ofstream out("E:\\Projects\\Pract\\out.txt", ios::trunc);
        out.close();
        return 0;
    }

    char* masCh = new char[n + 1];
    ifstream myin("E:\\Projects\\Pract\\test11.txt");
    if (myin.is_open())
    {
        myin >> masCh;
    }
    
    
    masCh[n] = 0;

    if (!checkWord(masCh, n))
    {
        ofstream out("E:\\Projects\\Pract\\out.txt", ios::trunc);
        out.close();
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        char ch = masCh[i];
 
        letters.find(ch) == letters.end() ? letters[ch] = 1 : letters[ch] += 1;
        //if (letters.find(-51) != letters.end())
        //{
        //    cout << i << masCh[i];
        //}
    }

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

    ofstream out("E:\\Projects\\Pract\\out.txt");
    out << str;
    out.close();
}

bool checkWord(const char* word, int n)
{
    for (int i = 0; i < n; i++)
        if (word[i] < 'A' || word[i] > 'Z')
            return false;

    return true;
}