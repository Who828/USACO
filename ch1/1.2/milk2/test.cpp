/*
USER: who8281
LANG: C++
TASK: test
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int, int> > times;

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N; // 1 - 5000
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int left, right;
        fin >> left >> right;
        times.push_back(make_pair(left, 0));
        times.push_back(make_pair(right, 1));
    }
    sort(times.begin(), times.end());
    int t1 = 0, t2 = 0;
    int start = times[0].first;
    int cnt = 0;
    for (int i = 0; i < times.size(); i++)
    {
        int t = times[i].first;
        int flag = times[i].second;
        if (flag == 0)
        {
            if (cnt == 0)
            {
                t1 = max(t1, t-start);
                start = t;
            }
            cnt++;
        }
        else if (flag == 1)
        {
            cnt--;
            if (cnt == 0)
            {
                t2 = max(t2, t-start);
                start = t;
            }
        }
    }
    fout << t2 << " " << t1 << endl;
    return 0;
}
