/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

class Node{
    public:
        vector<Node*> to;
        bool isLeaf = false;

        Node(int size){
            vector<Node*> sz(size);
            to = sz;
        }
};

class Trie{
    public:
        int size_;
        Node *root;

        Trie(int sz){
            size_ = sz;
            root = new Node(sz);
        }

    private:
        void insert_(Node *rt, string value, int idx){
            if(idx == value.size()){
                rt->isLeaf = true;
                return;
            }

            int i = value[idx] - 'a';

            if(rt->to[i] == nullptr) rt->to[i] = new Node(size_);

            return insert_(rt->to[i], value, idx + 1);
        }

    private:
        Node *search_(Node *rt, string value, int idx){
            if(idx == value.size()){                
                return rt;
            }

            int i = value[idx] - 'a';

            if(rt->to[i] == nullptr) return NULL;

            return search_(rt->to[i], value, idx + 1);
        }


    public:
        void insert(string v){
            return insert_(root, v, 0);
        }

        Node *search(string v){
            return search_(root, v, 0);
        }
        
        void prefix_words(vector<string> &results, Node *rt, string &prefix, int size){
            if(rt->isLeaf){
                if(prefix.size() != size) results.push_back(prefix);

            }

            for(int i = 0; i < size_; i++){
                string prev = prefix;
                if(rt->to[i] != NULL){
                    prev += i + 'a';
                    prefix_words(results, rt->to[i], prev, size);
                }
            }

        }
        


};

int main(){
    int n;
    cin >> n;
    Trie dict(26);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        dict.insert(s);
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        string prefix;
        cin >> prefix;

        int size = prefix.size();
        
        Node *pre = dict.search(prefix);

        vector<string> all;
        if(pre) dict.prefix_words(all, pre, prefix, size);
        
        cout << "Case #" << i+1 << ":" << endl;
        for(int j = 0; j < all.size(); j++){
            cout << all[j] << endl;
        }
        if(all.size() == 0) cout << "No match.";
    }
}