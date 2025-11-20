/*
1 1 1 1
0 0 0 0
1 2 1 2

se a paridade dos dois é a mesma, toda jogada os manterá ainda com a mesma paridade. Logo será um empate

se a paridade dos dois é diferente, o último com a jogada notória ganha


se as paridades são diferentes, quem tiver a ímpar ganha
a cada jogada executada, a paridade de cada jogador se inverte

você nunca quer ir de uma ímpar para uma par

a partir do primeiro estado em que as paridades são diferentes
quem tem a ultima jogada notoria ganha sempre?


1 2 1 2 1

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    int xor1 = 0;
    int xor2 = 0;

    vector<int> vec1;


    int notorious_index = -1;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        xor1 ^= val;
        vec1.push_back(val);
    }
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        xor2 ^= val;
        if(val != vec1[i]) notorious_index = i;
    }

    if(xor1 == xor2) cout << "Tie" << endl;
    else if(notorious_index == -1){
        if (xor1 > xor2) cout << "Ajisai" << endl;
        else cout << "Mai" << endl;
    }
    else{
        if (notorious_index % 2 == 0) cout << "Ajisai" << endl;
        else cout << "Mai" << endl;
    }
    
    
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}