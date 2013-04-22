/*
USER: who8281
LANG: C++
TASK: transform
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<char> > rotateMatrix(vector< vector<char> > matrix, const int &N, const int &rotation)
{
    vector< vector<char> > ret(N, vector<char>(N));
    int k = 0;

    while(k < rotation) {
        for (int i=0; i < N; i++) {
            for (int j=0; j < N; j++) {
                ret[i][j] = matrix[N - j - 1][i];
            }
        }
        k++;
        matrix = ret;
    }

    return ret;
}

vector< vector<char> > reflectionMatrix(const vector< vector<char> >& matrix, const int &N)
{
    vector< vector<char> > ret(N, vector<char>(N));
    ret = matrix;

        for (int i=0; i < N; i++) {
            reverse(ret[i].begin(), ret[i].end());
        }

    return ret;
}
int main()
{
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    int N; 

    fin >> N;
    string symbol;

    vector< vector<char> > matrix(N, vector<char>(N));
    vector< vector<char> > ret(N, vector<char>(N));
    vector< vector<char> > output(N, vector<char>(N));

    for (int i=0; i < N; i++) {
        fin >> symbol;
        for (int j=0; j < N; j++) {
            matrix[i][j] = symbol[j];
        }
    }

    for (int i=0; i < N; i++) {
        fin >> symbol;
        for (int j=0; j < N; j++) {
            output[i][j] = symbol[j];
        }
    }
    ret = reflectionMatrix(matrix, N);

    if (output == rotateMatrix(matrix, N, 1))
        fout << 1 << endl;
    else if (output == rotateMatrix(matrix, N, 2))
        fout << 2 << endl;
    else if (output == rotateMatrix(matrix, N, 3))
        fout << 3 << endl;
    else if (output == ret)
        fout << 4 << endl;
    else if (output == rotateMatrix(ret, N, 1) || output == rotateMatrix(ret, N, 2) || output == rotateMatrix(ret, N, 3))
        fout << 5 << endl;
    else if (matrix == output)
        fout << 6 << endl;
    else
        fout << 7 << endl;

    return 0;
}
