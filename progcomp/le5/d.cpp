/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int


void count_sort(vector<int> &p, vector<int> &c){
    int n = p.size();

    vector<int> new_p(n, 0);
    vector<int> cnt(n, 0); 

    for(auto e = c.begin(); e != c.end(); e++) cnt[*e]++;

    vector<int> pos(n); pos[0] = 0;
    for(int i = 1; i < n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }

    for(int i = 0; i < n; i++){
        int e = p[i];
        int idx = c[e];
        new_p[pos[idx]] = e;
        pos[idx]++;
    }

    p = new_p;
}

void SuffixArray(vector<int> &p, string s){
    

    s = s.append("$");
    
    int n = s.length();
    p.resize(n);
    vector<int> c(n);

    vector<pair<char, int>> a(n);

    for(int i = 0; i < n; i++){
        a[i] = {s[i], i};
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }

    c[p[0]] = 0;

    for(int i = 1; i < n; i++){
        
        if(a[i].first == a[i-1].first){
            
            c[p[i]] = c[p[i- 1]];

        } 
        
        else{

            c[p[i]] = c[p[i-1]] +1;
        }
    }

    lng power = 1; //  value to be doubled
    while(power < n){
        for(int i = 0; i < n; i++){
            p[i] = (p[i] - power + n) % n;
        }

        count_sort(p, c);

        vector<int> new_c(n);
        new_c[p[0]] = 0;

        for(int i = 1; i < n; i++){
            pair<int, int> prv = {c[p[i]-1], c[(p[i-1] + power) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + power) % n]};
            if(now == prv) new_c[p[i]] = new_c[p[i-1]];
            else new_c[p[i]] = new_c[p[i-1]] + 1;
        }

        c = new_c;
        power *= 2;
    }


}

void lcp(vector<int> &l, vector<int> &p, string &s){
    int n = p.size();
    
    vector<int> c = p;
    reverse(c.begin(), c.end());

    l.resize(n);

    int k = 0;
    for(int i = 0; i < n -1; i++){
        int posi = c[i];
        int j = p[posi-1];

        while( s[i+k] == s[j+k]) k++;
        l[posi] = k;
        k = max(k-1, 0);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    string s;
    int q;
    cin >> s >> q;

    vector<int> p;
    vector<int> l;

    SuffixArray(p, s);
    lcp(l, p, s);

    vector<int> ord(p.size());
    ord[0] = 0;
    for(int i = 2; i < p.size(); i++){
        ord[i] = ord[i-1] + (s.length() - p[i-1] - l[i-2]) + 1;
    }

    for(int i = 0; i < q; i++){
        
        int x;
        cin >> x;

        auto a = lower_bound(ord.begin(), ord.end(), x);
        if(a != ord.end() and *a == x) continue;
        else{
            a--;
        }
        int k = distance(ord.begin(), a);
        int begin = p[k];
        int end = p[k] + (x - ord[k]) + 1;

        for(int i = begin; i<= end; i++){
            cout << s[i];
        }
        cout << endl;
    }
}