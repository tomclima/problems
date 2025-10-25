/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> prices;
        // get prices

        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll val; cin >> val;
            prices.push_back(val);
            sum += val;
        }
        sort(prices.begin(), prices.end());
        vector<ll> discounts;
        for(int i = 0; i < k; i++){
            ll val; cin >> val;
            discounts.push_back(val);
        }

        sort(discounts.begin(), discounts.end());

        int end_prices = n;
        int end_discounts = 0;

        while(end_prices >= 0 and end_discounts<k){
            end_prices -= discounts[end_discounts];
            if(end_prices >= 0){
                sum -= prices[end_prices];
                end_discounts++;
            }
        }

        cout << sum << endl;
        

    }
}