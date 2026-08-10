/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    

    int n; cin >> n;
    int a, b; cin >> a >> b;

    int draws = n - (a + b);

    bool is_possible = true;
    if (n < a + b) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<int, int>> games;
    for(int i = 0; i < draws; i++){
        games.push_back({n - i, n-i});
    }

    vector<int> deck_a;
    vector<int> deck_b;
    for(int i =0; i < a + b; i++){
        deck_a.push_back(i + 1);

        deck_b.push_back(i+1);
    }

    

    rotate(deck_b.begin(), deck_b.end() - b, deck_b.end());
    for(int i = 0; i < a+b; i++){
        games.push_back({deck_a[i], deck_b[i]});
    }
    int actual_a = 0;
    int actual_b = 0;
    // check correctness
    for(int i = 0; i < a + b; i++){
        actual_a += deck_a[i] > deck_b[i];
        actual_b += deck_b[i] > deck_a[i];
    }
    if(actual_a != a or actual_b != b){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for(int i =0; i < n; i++){
        cout << games[i].first << " ";
    
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << games[i].second << " ";
    }
    cout << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}