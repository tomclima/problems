#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<lng, greater<lng>> st;
    for(int i = 0; i < n; i++){
        lng x;
        cin >> x;
        st.insert(x);
    }
    vector<lng> b;
    for(int i = 0; i < n-1; i++){
        lng x;
        cin >> x;
        b.push_back(x);
    }
    sort(b.rbegin(), b.rend());

    bool possible = true;
    for(int i = 0; i < n - 1; i++){
        auto iter = st.lower_bound(b[i]); 
        if(iter != st.end()){
            st.erase(iter); 
        }
        else{
            possible = false;
        }
    }

    lng price;
    if(possible){
        price = *st.begin();
    }
    else{
        price = -1;
    }

    cout << price;
    
}