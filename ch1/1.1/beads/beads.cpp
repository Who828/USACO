/*
USER: who8281
LANG: C++
TASK: beads
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    int N ;
    int best = 0, current = 0, prev = 0, w = 0;
    char color;
    string beadsNecklace;
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    fin >> N;
    fin >> beadsNecklace;

    beadsNecklace += beadsNecklace;


    for(int i=0; i < 2*N; i++) {
        if (prev + current >= N)
            break;
        if (color != beadsNecklace[i] && beadsNecklace[i] != 'w') {
            color = beadsNecklace[i];
            best = max(best, prev + current);
            prev = current - w;
            current = w;
        } 
        w = (beadsNecklace[i] == 'w') ? w+1 : 0;
        current++;
    }

    fout << max(best, prev+current) << endl;

    return 0;
}
