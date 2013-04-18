/*
USER: who8281
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


bool myfunction(const pair<int, int>& i, const pair<int, int>& j)
{ 
    return (i.first < j.first); 
}

int main()
{
    int N;
    vector< pair<int, int> > milkTimes;
    map<int, pair<int, int> > farmers;
    int startTime, stopTime, minStartTime, maxStopTime, minInterval = 0, maxInterval = 0;
    vector<pair<int, int> >::iterator it;

    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    fin >> N;

    for(int i=0; i < N; i++) {
        fin >> startTime >> stopTime;
        milkTimes.push_back(make_pair(startTime, stopTime));
    }

    sort(milkTimes.begin(), milkTimes.end(), myfunction);

    int j = 0;
    for(it=milkTimes.begin(); it != milkTimes.end(); it++) {
        farmers[j] = *it;
        j++;
    }

    minStartTime = farmers[0].first;
    maxStopTime = farmers[0].second;
    maxInterval = maxStopTime - minStartTime;

    for(int i=0; i < N; i++) {
        if (farmers[i].first <= maxStopTime) {
            maxStopTime = max(maxStopTime, farmers[i].second);
        } else {
            maxInterval = max(maxInterval, maxStopTime - minStartTime);
            minInterval = max(minInterval, farmers[i].first - maxStopTime);
            minStartTime = farmers[i].first;
            maxStopTime = farmers[i].second;
        }
    }


    fout << maxInterval << " " << minInterval << endl;
}

