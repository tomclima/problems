/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

void balance(multiset<ll> &u_half, multiset<ll> &l_half){ // acredito ser seguro
    if(u_half.size() > l_half.size() +1){
        l_half.insert(*u_half.begin());
        u_half.erase(u_half.begin());
    }
    else if(l_half.size() > u_half.size() +1){
        u_half.insert(*l_half.rbegin());
        l_half.erase(--l_half.end());
    }
}

ll get_median(multiset<ll> &u_half, multiset<ll> &l_half){
    balance(u_half, l_half); // por cause disso, so pode dar merda em uma situação: l_half e u_half estão vazios
    if(u_half.size() > l_half.size()) return *u_half.begin();
    return *l_half.rbegin();
    
}

int solve(){

    int n, k; cin >> n >> k;

    multiset<ll> u_half;
    multiset<ll> l_half;

    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        arr.push_back(val);
    }

    ll median_val = 1e18;
    //initial median initialization
    for(int i = 0; i < k; i++){
        if(arr[i] <= median_val) l_half.insert(arr[i]);
        else u_half.insert(arr[i]);
        median_val = get_median(u_half, l_half); // aqui
    }

    cout << median_val << " ";

    // slide the window
    for(int i = 1; i +k <= n; i++){
        if(arr[i+k-1] <= median_val) l_half.insert(arr[i+k-1]);
        else u_half.insert(arr[i+k-1]);

        if(l_half.find(arr[i-1]) != l_half.end() and arr[i-1] <= median_val) l_half.erase(l_half.lower_bound(arr[i-1]));
        else u_half.erase(u_half.lower_bound(arr[i-1])); // erase é safe
        median_val = get_median(u_half, l_half); // aqui podemos ter apagado e não adicionado nada


        cout << median_val << " ";
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t =1;// cin >> t;
    while(t--){
        solve();
    }
}