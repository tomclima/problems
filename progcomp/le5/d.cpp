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

void suffix_array(vector<int> &p, vector<int> &c, string s) {
    s.append("$");
    int n = s.size();
    const int alphabet = 256;
    vector<int> cnt(max(alphabet, n), 0);
    p.resize(n); c.resize(n);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

        vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
}


void lcp(vector<int> &l, vector<int> &p, string &s){
    
    int n = p.size();
    
    l.resize(n -1);
    vector<int> c(n, 0);

    for(int i = 0; i < n; i++){
        c[p[i]] = i;
    }

    n--;
    int k = 0;
    for(int i = 0; i < n; i++){
        
        if(c[i] == n-1) k = 0;

        int j = p[c[i] + 1];
        while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
        l[c[i]] = k;

        if(k) k--;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    string s;
    int q;
    cin >> s >> q;

    vector<int> p;
    vector<int> c;
    vector<int> l;

    suffix_array(p, c, s);
    lcp(l, p, s);

    vector<lng> ord(p.size());
    ord[0] = 0; ord[1] = 1;
    lng  distinct = 1;
    for(int i = 2; i < p.size(); i++){
        ord[i] = ord[i-1] + (s.length() - p[i-1] - l[i-2]);
        
        if(i == p.size() - 1) distinct = ord[i] + (s.length() - p[i] - l[i-1] -1);
    }


    for(int i = 0; i < q; i++){
        
        lng x;
        cin >> x;

        if(x > distinct) x = distinct;

        auto a = lower_bound(ord.begin(), ord.end(), x);
        if(a == ord.end() or *a != x) a--;
        lng k = distance(ord.begin(), a);
        lng begin = p[k];
        lng end = begin + l[k-1] + (x - ord[k]);

        
        cout << s.substr(begin, end - begin +1);
        cout << endl;
    }
}