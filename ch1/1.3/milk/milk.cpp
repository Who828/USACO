/*
USER: who8281
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main()
{
    int N, M;
    vector<int> prices;
    map<int, int> farmers;
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");

    fin >> N >> M;

    int price, milk;

    for (int i=0; i < M; i++){
        fin >> price >> milk;
        prices.push_back(price);
        if (farmers[price])
            farmers[price] += milk;
        else
            farmers[price] = milk;
    }

    sort(prices.begin(), prices.end());
    vector<int>::iterator it;
    it = unique(prices.begin(), prices.end());
    prices.resize(distance(prices.begin(),it));
    
    int totalPrice = 0, milkRemaning = N;


    for (int i=0; i < M && milkRemaning > 0; i++){
        if (farmers[prices[i]] >= milkRemaning){
            totalPrice += (milkRemaning * prices[i]);
            milkRemaning = 0;
        }
        else {
            totalPrice += (farmers[prices[i]] * prices[i]);
            milkRemaning -= farmers[prices[i]];
        }
    }

    fout << totalPrice << endl;

    return 0;
}
