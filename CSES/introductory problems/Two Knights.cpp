/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

float average_removal(int n){
    int total = 0;
    total += (n-2)*(n-2)*9; // centro
    total += (4*(n-1) - 4)*7; //precentro_lados
    total += (4)*5; // precentro_corners
    total += (4*(n) - 12)*5; // lados
    total += (8)*4; // precorners
    total += (4)*3; // corners   

    cout << total/(n*n) << endl;

    return (float)total/(n*n);
}

int calculate_ways(int n){
    if (n == 1){
        return 0;
    }
    if (n == 2){
        return 6;
    }
    if(n == 3){
        return 28;
    }
    if (n == 4){
        return 96;
    }
    if(n == 5){
        return 252;
    }
    else{
        return (n*n)*(n*n -round(average_removal(n)));
    }
}

int solve(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        cout << calculate_ways(i) << endl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}