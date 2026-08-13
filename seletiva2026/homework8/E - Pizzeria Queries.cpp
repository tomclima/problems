/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll INF = (ll)MAXN;


struct Node{
    int left;
    int right;
    int min_pos_left;
    int min_pos_right;
    ll min_left_val;
    ll min_right_val;

    Node(){
        left = -1;
        right = -1;
        min_pos_left = -1;
        min_pos_right= -1;
        min_right_val = INF;
        min_left_val = INF;
    }

    Node(ll val, int pos){
        left = pos;
        right = pos;
        min_pos_left = pos;
        min_pos_right = pos;
        min_left_val = val;
        min_right_val = val;
    }
};

template<typename T>
struct segTree{
    
    public:

        vector<Node> seg;
        vector<T> arr;
        int n;

        segTree(vector<T> a){
            n = a.size();
            arr = a;
            seg.resize(4*n);
            build_seg(0, n-1, 0);
        }
        
        Node query(int L, int R){
            return query_helper(L, R, 0, n-1, 0);
        }

        void update(int pos, int val){
            update_helper(0, n-1, 0, pos, val);
        }

    private:
        void build_seg(int l, int r, int idx){
            
            if(l == r){
                seg[idx] = Node(arr[l], l);
                return;
            }

            int mid = (l + r)/2;
            int lc = left_child(idx);
            int rc = right_child(idx);

            build_seg(l, mid, lc);
            build_seg(mid+1, r, rc);

            seg[idx] = join(seg[lc], seg[rc]);
        }

        Node query_helper(int L, int R, int l, int r, int idx){
            
            if(l > R or r < L ) return neutral_element(); // neutral element

            if (l >= L and r <= R) return seg[idx];

            int mid = (l + r)/2;
            int lc = left_child(idx);
            int rc = right_child(idx);

            Node left_query = query_helper(L, R, l, mid, lc);
            Node right_query = query_helper(L, R, mid+1, r, rc);

            Node ans_query = join(left_query, right_query);
            return ans_query;
        }

        void update_helper(int l, int r, int idx, int pos, int val){
            
            if(l == r){
                seg[idx] = Node(val, l);
                return;
            }
            

            int mid = (l + r)/2;
            int lc = left_child(idx);
            int rc = right_child(idx);
            if(pos <= mid) update_helper(l, mid, lc, pos, val);
            else           update_helper(mid+1, r, rc, pos, val);

            seg[idx] = join(seg[lc], seg[rc]);
        }

        Node join(Node l_node, Node r_node){
            
            
            if(l_node.left < 0) return r_node;
            if(r_node.left < 0) return l_node;
            
            
            Node newnode;
            newnode.right = r_node.right;
            newnode.left = l_node.left;


            // left join
            ll min_left_candidate1 = l_node.min_left_val;
            ll min_left_candidate2 = r_node.min_left_val + (r_node.left - l_node.left);
            newnode.min_left_val = min(min_left_candidate1, min_left_candidate2);

            if(min_left_candidate1 <= min_left_candidate2) newnode.min_pos_left = l_node.min_pos_left;
            else if(min_left_candidate1 > min_left_candidate2) newnode.min_pos_left = r_node.min_pos_left;
            
            // right
            ll min_right_candidate1 = r_node.min_right_val;
            ll min_right_candidate2 = l_node.min_right_val + (r_node.right - l_node.right);
            newnode.min_right_val = min(min_right_candidate1, min_right_candidate2);

            if(min_right_candidate1 <= min_right_candidate2) newnode.min_pos_right = r_node.min_pos_right;
            else if(min_right_candidate1 > min_right_candidate2) newnode.min_pos_right = r_node.min_pos_right;
            
            return newnode;
        }

        Node neutral_element(int l, int r){
            return Node();
        }

        int left_child(int idx) {return 2*idx+1;}
        int right_child(int idx) {return 2*idx+2;}
    
};


int solve(){
    
    int n, q; cin >> n >>  q;

    vector<ll> prices(n);
    for(auto &i : prices) cin >> i;

    segTree<ll>  seg(prices);

    while(q--){
        
        int query_type; cin >> query_type;

        if(query_type == 2){
            int pos; cin >> pos;
            // get best value to the right
            ll left_ans = seg.query(pos-1, n-1).min_left_val;
            ll right_ans = seg.query(0, pos-1).min_right_val;

            cout << min(left_ans, right_ans) << endl;
        }

        if(query_type == 1){
            int building; cin >> building;
            int newprice; cin >> newprice;
            seg.update(building-1, newprice);
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}