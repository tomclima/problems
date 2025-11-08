/*link*/

#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define ll long long int

/*
temos uma quantidade de árvores com alturas h e frutas a

queremos escolher um subarray de tal forma que, para todo hi, hi é divisível por hi+1 (hi % hi+1 = 0)

ele vai pegar todas as frutas desse subarray, mas não pode pegar mais que k

qual o tamanho do maior subarray que ele pode pegar?

calculo eficiente de intervalos -> prefix sum

como verificar eficientemente subarrays divisíveis? se {l, r} são divisíveis, todos entre são também -> tempo linear

para cada subarray divisível, podemos fazer uma busca binária até k e calculamos r - l.
*/


int solve(){

    ll n, k; cin >> n >> k;
    vector<ll> heights;
    vector<ll> fruits;

    
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        fruits.push_back(val);
    }
    
    
    
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        heights.push_back(val);
    }
    
    
    vector<pair<ll, ll>> divisible_subarrays;
    int curr_l = 0;
    int curr_r = 0;
    for(int i = 0; i+1 < n; i++){
        if(heights[i] % heights[i+1] == 0) curr_r = i+1;
        else{
            divisible_subarrays.push_back({curr_l, curr_r});
            curr_l = i+1;
            curr_r = i+1;
        }
    }
    divisible_subarrays.push_back({curr_l, curr_r});
    
    
    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = (fruits[i-1] + prefix[i-1]);
    }

    
    int max_len = 0;
    prefix.push_back(1e18);

    for(int i = 0; i < divisible_subarrays.size(); i++){
        
        for(int j = divisible_subarrays[i].first; j < divisible_subarrays[i].second; j++){

            ll l = 0;
            ll r = divisible_subarrays[i].second - j+1;
            ll ans = r+1;
            while (l <= r){
                ll middle = (r + l)/2;
                if (prefix[j + middle] - prefix[j] > k){
                    r = middle-1;
                    ans = middle;
                }
                else{
                    l = middle+1;
                }
            }
            
            if(ans > max_len) max_len = ans-1;  
        }
    }

    cout << max_len << endl;
        return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}