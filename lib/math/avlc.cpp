/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll vec_dot(vector<int> v1, vector<int> v2){
    int dot = 0;
    for(int i = 0; i < v1.size(); i++){
        dot += v1[i]*v2[i];
    }

    return dot;
}