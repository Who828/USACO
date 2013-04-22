/*
USER: who8281
LANG: C++
TASK: dualpal
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

bool isPalindrome(const string& number)
{
    int length = number.length();

    if (number[0] == '0' || number[length - 1] == '0')
        return false;

    string reverseNumber = number;
    reverse(reverseNumber.begin(), reverseNumber.end());
    return number == reverseNumber;
}

int main()
{
    int N, S;
    string convertedNumber;
    vector <int> output;
    ostringstream number;

    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");

    fin >> N >> S;

    int i = S+1, j = 0;
    int count;
    while(j < N) {
        count = 0;
        for (int base = 2; base < 11; base++) {
            convertedNumber = baseConverter(i, base);
            if(isPalindrome(convertedNumber))
                count++;
            if (count == 2) {
                output.push_back(i);
                j++;
                break;
            }
        }
        i++;
    }

    for(vector<int>::iterator it = output.begin(); it != output.end(); ++it){
        fout << (*it) << endl;
    }

}
