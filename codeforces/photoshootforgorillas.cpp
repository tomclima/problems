/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

// lembrar de ler os contraints com CALMA

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n, m, k; 
        cin >> n >> m >> k;
        int w; 
        cin >> w;
        priority_queue<int> gorillas;
        while(w--){
            ll weight; 
            cin >> weight;
            gorillas.push(weight);
        }

        priority_queue<ll> intersections;
        for(int i = 0; i < n; i++){ // the SUM of n*m does not exceed 2*10^5 across all testcases, so the total number of operations wont be 10^3*2*10^5
            for (int j = 0; j < m; j++){ // but only 2*10^5, which is quite small :)
                ll vertical = k - (max(k - (i+1), 0) + max(k - (n-i), 0));
                ll horizontal = k - (max(k - (j+1), 0) + max(k - (m-j), 0));
                intersections.push(vertical*horizontal);
            }
        }

        ll best = 0;
        ll original_size = gorillas.size();
        for(int i = 0; i < original_size; i++){
            best += gorillas.top()*intersections.top();
            gorillas.pop();
            intersections.pop();
        }

        cout << best  << endl;

    }
}