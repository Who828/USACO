
/*
USER: who8281
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int findMaxAdj(const vector<int>& stalls, const int& C)
{
    int maxAdj = 0, adj;

    for(int i=1; i < C; i++){
        adj = stalls[i] - (stalls[i-1] - 1);
        if (maxAdj < adj)
            maxAdj = adj;
    }

    return maxAdj;
}

int findIndexBasedOnAdj(const vector<int>& stalls, const int& value, const int& C)
{
    int index = 0;

    for(int i=0; i < C; i++){
      if (stalls[i+1] > value || i+1 >= C) {
          index = i;
          break;
      }
    }

    return index;
}

int main()
{
    int S, M, C;
    vector<int> stalls;
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");

    fin >> M >> S >> C;

    int tempStall;
    for (int i=0; i < C; i++){
        fin >> tempStall;
        stalls.push_back(tempStall);
    }

    sort(stalls.begin(), stalls.end());

    int adj;
    vector<int> gaps;

    for(int i=1; i < C; i++){
        adj = stalls[i] - (stalls[i-1]);
        if (adj > 1) {
            gaps.push_back(adj - 1);
        }
    }

    sort(gaps.begin(), gaps.end());

    for (int i = 0; i < gaps.size(); i++)
        cout << gaps[i] << endl;

    int boards = gaps.size() + 1, g, stallsCovered = C;


    while (boards > M) {
        g = gaps[0];
        gaps.erase(gaps.begin());
        stallsCovered += g;
        boards--;
    }

    fout << stallsCovered << endl;
}
