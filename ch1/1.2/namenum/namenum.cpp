/*
USER: who8281
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

bool condition_check(const char& a, const char& b, const char& c, const char& n)
{
    return (n == a || n == b || n == c);
}

string pattern_matching(const string& pattern, const string keypad[], const vector<int>& numbers)
{
    for(int i=0; i < numbers.size(); i++) {
        if (condition_check(keypad[numbers[i]][0], keypad[numbers[i]][1], keypad[numbers[i]][2], pattern[i]))
            continue;
        else
            return "";
    }

    return pattern;
}

int main()
{
    string name;
    string keypad[10] = {"","", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUW", "WXY"};
    long long N;
    string num;
    vector<int> numbers;
    vector<string> names;
    map<int, vector<string> > dict;
    ifstream fin ("namenum.in");
    ifstream dictin ("dict.txt");
    ofstream fout ("namenum.out");

    for(int i=0; i < 4618; i++){
        dictin >> name;
        for(int j=2; j < 10; j++) {
            if (condition_check(keypad[j][0], keypad[j][1], keypad[j][2], name[0])) {
                dict[j].push_back(name);
                break;
            }
        }
    }

    fin >> N;
    ostringstream ostr;
    ostr << N;
    num = ostr.str();
    for(int i=0; i < num.length(); i++)
        numbers.push_back(num[i] - '0');

    names = dict[numbers[0]];

    set<string> output;
    set<string>::iterator it;
    name = "";

    for(int i=0; i < names.size(); i++) {
        if (names[i].length() == num.length())
            name = pattern_matching(names[i], keypad, numbers);

        if (name.length() == num.length()) {
            output.insert(name);
            name = "";
        }
    }

    if (output.empty())
        fout << "NONE" << endl;
    else {
        for(it = output.begin(); it != output.end(); it++)
            fout << *it << endl;
    }
}

