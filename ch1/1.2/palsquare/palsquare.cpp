/*
USER: who8281
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
string converstion[21] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
string baseConverter(const int& number, const int&base)
{
    ostringstream convertedNumber;
    vector<int> numbers;
    int num = number;

    while(num > 0) {
        numbers.insert(numbers.begin(), num % base);
        num /= base;
    }

    for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it){
        convertedNumber << converstion[*it];
    }

    return convertedNumber.str();
}

int square(const int& x)
{
    return x * x;
}

bool isPalindromeSquare(const string& number)
{
    string reverseNumber = number;
    reverse(reverseNumber.begin(), reverseNumber.end());
    return number == reverseNumber;
}

int main()
{
    int base;
    string convertedNumber;
    vector <pair <string, string> > output;
    ostringstream number;

    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");

    fin >> base;

    for(int i=1; i < 301; i++) {
        convertedNumber = baseConverter(square(i), base);
        if(isPalindromeSquare(convertedNumber))
            output.push_back(make_pair(baseConverter(i, base), convertedNumber));
    }

    for(vector<pair <string, string> >::iterator it = output.begin(); it != output.end(); ++it){
        fout << (*it).first << " " << (*it).second << endl;
    }

}
