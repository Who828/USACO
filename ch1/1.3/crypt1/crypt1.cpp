/*
USER: who8281
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool validateNumbers(const string& number, const vector<int>& set)
{
    for (int i = 0; i < number.length(); i++){
       if (count(set.begin(), set.end(), number[i] - '0') == 0)
           return false;
    }

    return true;
}

bool validatePartialProduct(const int&i, const string&j , const vector<int>& set)
{
    ostringstream a,b;

    a << (i * (j[0] - '0'));
    b << (i * (j[1] - '0'));

    string num1 = a.str(), num2 = b.str();


    if (num1.length() > 3 || num2.length() > 3)
        return false;

    for (int i=0; i < 3; i++)
       if ((count(set.begin(), set.end(), num1[i] - '0') == 0) || count(set.begin(), set.end(), num2[i] - '0') == 0)
           return false;

    return true;
}

bool validateProduct(const int& product, const vector<int>& set)
{
    ostringstream prod;
    prod << product;
    string answer = prod.str();

    for (int i = 0; i < answer.length(); i++){
       if (count(set.begin(), set.end(), answer[i] - '0') == 0)
           return false;
    }
    return true;
}

bool validNumber(const int& i, const int& j, const vector<int>& set)
{
    ostringstream a, b;
    a << i;
    b << j;

    if (validateNumbers(a.str(), set) && validateNumbers(b.str(), set))
        return validatePartialProduct(i, b.str(), set) && validateProduct(i * j, set);
    else
        return false;
}

int main()
{
    ifstream fin ("crypt1.in");
    ofstream fout ("crypt1.out");

    int N, value;
    vector<int> set;

    fin >> N;

    for (int i = 0; i < N; i++){
        fin >> value;
        set.push_back(value); 
    }

    int count = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = 10; j < 99; j++)
            if (validNumber(i, j, set))
                count++;

    fout << count << endl;


}

