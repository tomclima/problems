/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

// caso par: trivial -> escolhe gulosamente todos os pares já feitos
// caso ímpar: não feito -> não sei como escolher sistematicamente qual excluir
// soma menor + maior -> não!
// choose() -> não
// 

int solve(){

    int n, k; cin >> n >> k;
    vector<int> missing;
    missing.push_back(1e18); // confia 
    for(int i = 0; i < k; i++){
        int val; cin >> val;
        missing.push_back(val);
    }   
    missing.push_back(1e18); // confia

    // com o prepend e append de 1e18, o nosso intervarlo vai de 1 a k, mas com posições legais em 0 e k+1
    // assim, temos k+2 elementos

    vector<int> choose(0, k+2); 
    for(int i = 1; i <= k; i++){
        if(missing[i+1] < missing)
    }

    vector<int> chosen(k, 0);





    cout << sum_weirdness << endl;
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