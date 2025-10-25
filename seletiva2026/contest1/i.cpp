/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int  t; cin >> t;
    while(t--){
        string time;cin>> time;
        
        bool prepend_0 = false;
        bool pm = false;
        //get hours
        int hours = stoi(time.substr(0, 2));
        string minutes = time.substr(3, 5);

        pm = hours >= 12;
        if(hours != 12) hours = hours % 12;
        if(hours == 0) hours = 12;
        

        if(hours < 10) prepend_0 = true;
        if(prepend_0) cout << "0";
        cout << hours << ":" << minutes << " ";
        if(pm) cout << "PM";
        else cout << "AM"; 
        cout << endl;
    }
}