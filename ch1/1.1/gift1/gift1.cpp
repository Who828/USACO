/*
USER: who8281
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    map<string, int> collection;
    vector<string> name_list;

    int np, amount, people;
    string name, line;

    fin >> np;

    for(int i=0; i < np; i++) {
        fin >> name;
        name_list.push_back(name);
        collection[name] = 0;
    }


    while(fin >> name >> amount >> people) {
        collection[name] -= amount;
        string other_name;
        for(int i=0; i< people; i++) {
            fin >> other_name;
            int value = amount / people;
            cout << name << " " << people << " " << other_name << endl;
            collection[other_name] += value; 
        }
        if (amount > 0)
            collection[name] += amount % people; 
    } 

      for (vector<string>::iterator it = name_list.begin() ; it != name_list.end(); ++it)
        fout << *it << " " << collection[*it] << endl;

    return 0;
}
