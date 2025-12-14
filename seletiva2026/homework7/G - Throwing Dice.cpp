/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
recorrência Q(x, n) -> de quantas formas conseguimos o número x jogando n dados?
mas queremos já computar o numero de formas com "até" n dados, já que somar tudo no final vai dar trabalho 



Q(x, n) = Q(x, n-1) + 
    (Q(x-1, n-1) - Q(x-1, n-2)) + 
    (Q(x-2, n-1) - Q(x-2, n-2)) + 
    (Q(x-3, n-1) - Q(x-3, n-2)) + 
    (Q(x-4, n-1) - Q(x-4, n-2)) + 
    (Q(x-5, n-1) - Q(x-5, n-2)) +
    (Q(x-6, n-1) - Q(x-6, n-2))

transformada de estado grande do inferno. So dp normal não passa -





qual q quantidade mínima de dados? n/6
quantidade máxima? n
muitos estados para considerar...

qual o vetor de estado?


*/

int solve(){
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}