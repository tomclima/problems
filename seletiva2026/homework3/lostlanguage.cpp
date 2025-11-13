/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define ALPHABET_SIZE 26



int encode_letter(char letter){
    return letter - 'a';
}

char decode_letter(int ord){
    return ord+'a';
}

int solve(){
    int n; cin >> n;
    vector<string> words;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        words.push_back(str);
    }

    vector<vector<int>> graph(ALPHABET_SIZE);
    vector<int> deg(ALPHABET_SIZE);
    for(string word :words){
        for(int i = 0; i+1 < word.length(); i++){
            int a = encode_letter(word[i]);
            int b = encode_letter(word[i+1]);
            if(a != b and find(graph[a].begin(), graph[a].end(), b) == graph[a].end()){
                graph[a].push_back(b);
                deg[b]++;

            }
        }   
    }


    queue<int> queue;
    for(int i = 0; i < 26; i++){
        if(deg[i] == 0){
            queue.push(i);
        }
    }

    vector<int> ord;

    while(!queue.empty()){
        int u = queue.front(); queue.pop();
        ord.push_back(u);
        for(auto i : graph[u]){
            deg[i]--;
            if(deg[i] == 0) queue.push(i);
        
        }
    }

    if(ord.size() < ALPHABET_SIZE){
        cout << "NAO";
        return 0;
    }

    cout << "SIM" << endl;
    for(int i : ord){
        cout << decode_letter(i);
    }

    
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