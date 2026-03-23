/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define ld long double
#define vec vector<ld>
#define pll pair<ld, ld>


double vec_cross_product(vec v1, vec v2, vec v3){
    return (v2[0] - v1[0]) * (v3[1] - v1[1]) - (v2[1] - v1[1]) * (v3[0] - v1[0]);
}

int orientation(vec &p1, vec &p2, vec &p3){
    
    double cross = vec_cross_product(p1, p2, p3);

    if (cross < 0) return -1;  // to the right
    if(cross > 0) return 1;  // to the left
    return 0;
}

bool cw(vec &p1, vec &p2, vec &p3, bool include_colinear){
    
    int o = orientation(p1, p2, p3);

    return (o < 0 or (o == 0 and include_colinear));
}

bool ccw(vec &p1, vec &p2, vec &p3, bool include_colinear){
    
    int o = orientation(p1, p2, p3);

    return (o > 0 or (o == 0 and include_colinear));
}


void convex_hull(vector<vec>& a, bool include_colinear, vector<vec> &up, vector<vec> &down){
    
    if(a.size() == 1){
        return;
    }

    sort(a.begin(), a.end());

    vec p1 = a[0], p2 = a.back();
    
    
    up.push_back(p1); down.push_back(p1);

    for(int i = 1; i < a.size(); i++){
        
        if(i == a.size() -1 or cw(p1, a[i], p2, include_colinear)){
            while(up.size() >= 2 and !cw(up[up.size() -2], up[up.size()-1], a[i], include_colinear)){
                up.pop_back();
            }
            up.push_back(a[i]);
            
        }

        if(i == a.size() -1 or ccw(p1, a[i], p2, include_colinear)){
            while(down.size() >= 2 and !ccw(down[down.size() -2], down[down.size() -1], a[i], include_colinear)){
                down.pop_back();
            }
            down.push_back(a[i]);
            
        }

    }

}

int solve(){
    int n; cin >> n;
    vector<vec> kingdoms;
    for(int i = 0; i < n;  i++){
        int a, b; cin >> a >> b;
        kingdoms.push_back({(ld)a, (ld)b, (ld)i+1});
    }
    
    vector<vec> up, down;
    convex_hull(kingdoms, 1,up, down );
    set<int> ans;
    for(auto p : up) ans.insert((int)p[2]);
    for(auto p : down) ans.insert((int)p[2]);


    for(auto i : ans) cout << i << " ";

    
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