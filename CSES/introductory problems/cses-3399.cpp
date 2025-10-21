/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

void backtrack(int remaining, int const a_obj, const int b_obj, const int a_curr, const int b_curr, set<int> cards_a, set<int> cards_b){
    if(a_curr > a_obj) return;
    if(b_curr > b_obj) return;
    if(a_obj - a_curr + b_obj - b_curr < remaining) return;

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, a, b; cin >> n >> a >> b;

    }


}