#include <bits/stdc++.h>
using namespace std;

bool is_beautiful(string str){
    bool answer = true;
    for(int i = 0; i < str.length() -1; i++){
        if(str[i] == str[i+1]){
            answer = false;
            break;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        int nl, nr;
        cin >> nl >> nr;

        string l, r;

        cin >> l >> r;

        bool possible = true;
        bool l_beautiful = is_beautiful(l);
        bool r_beautiful = is_beautiful(r);

        if(!l_beautiful and !r_beautiful){
            possible = false;
        }

        else if(r_beautiful){
            while(l.back() != r.back() and l.length() > 1){
                r.push_back(l.back());
                l.pop_back();
            }
        }
        else if(l_beautiful){
            while(r.back() != l.back() and r.length() > 1){
                l.push_back(r.back());
                r.pop_back();
            }
        }

        l_beautiful = is_beautiful(l);
        r_beautiful = is_beautiful(r);

        if(!l_beautiful or !r_beautiful){
            possible = false;
        }

        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
}