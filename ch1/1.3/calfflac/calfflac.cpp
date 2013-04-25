/*
USER: who8281
LANG: C++
TASK: calfflac
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string stripLine(const string& line)
{
    string strippedLine = "";
    for (int i = 0; i < line.length(); i++)
        if (isalpha(line[i]))
            strippedLine += tolower(line[i]);

    return strippedLine;
}


string stripSpecialChar(const string line)
{
    int start = 0, end = line.length();
    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line[i])) {
            start = i;
            break;
        }
    }

    for (int i = line.length();!isalpha(line[i]); i--)
            end = i;
    

    return line.substr(start, end - start);
}

string grow (const string& text, const int& i, const int& j)
{
    int start = i, end = j;

    while(start > 0 && end < text.length()) {
        if (isalpha(text[start - 1]) && isalpha(text[end])) {
            if (tolower(text[start - 1]) == tolower(text[end])) {
                start--;
                end++;
            } else
                break;
        } else if(!isalpha(text[start -1]))
                start--;
        else if(!isalpha(text[end]))
            end++;
    }

    return stripSpecialChar(text.substr(start, end - start));
}

pair<int, string> palindrome(const string& text)
{
    int max;
    string tmp, max_substr;

    for (int i = 0; i < text.length(); i++)
        for(int j=i; j< i+2; j++){
            tmp = grow(text, i, j); 
            if (stripLine(tmp).length() > max) {
                max = stripLine(tmp).length();
                max_substr = tmp;
            }
        }
    pair <int, string> tmp_pair;
    tmp_pair.first = max;
    tmp_pair.second = max_substr;
    return tmp_pair;
}

int main()
{
    string text;
    ifstream fin ("calfflac.in");
    ofstream fout ("calfflac.out");
    pair <int, string> collection;

    for(string line; getline(fin, line); ) {
        text += line;
        text += '\n';
    }

    collection = palindrome(text);

    fout << collection.first << endl;
    fout << collection.second << endl;
}
