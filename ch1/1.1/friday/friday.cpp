/*
USER: who8281
LANG: C++
TASK: friday
*/

#include <fstream>
#include <iostream>

using namespace std;

bool isLeapyear(int year)
{
    if (year % 100 == 0)
        return (year % 400) == 0;
    else
        return (year % 4) == 0;
}

int main()
{
    int N;
    int initial = 0;
    int year = 1900;
    int week[7] = { 0, 0, 0, 0, 0, 0, 0};
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");

    fin >> N;

    while(year < 1900+N)  {
        for(int i = 0; i < 12; i++) {
            week[initial % 7] += 1;
            if (i == 3 || i == 5 || i == 10 || i == 8)
                initial += 2;
            else if(i == 1 && isLeapyear(year))
                initial += 1;
            else if(i == 1 && !isLeapyear(year))
                initial += 0;
            else
                initial += 3;
        }
        year++;
    }

    for(int i =0; i < 7; i++) {
        if (i == 0)
            fout << week[i];
        else
            fout << " " << week[i];
    }
    fout << endl;
    fin.close();
    fout.close();

    return 0;
}
