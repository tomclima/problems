/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll INF = (ll)MAXN;


struct Node{


    Node(){

    }

    Node(ll val, int pos){

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
            
            // If is leaf, store Node based on the array element and/or position
            if(l == r){
                seg[idx] = Node(arr[l]); // CAN BE CHANGED
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
            
            if(l > R or r < L ) return neutral_element(); 

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
            
            // If is leaf, store Node based on the array element and/or position
            if(l == r){
                seg[idx] = Node(val, l); // CAN BE CHANGED
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
        /*
            Necessary properties
            1 - join(join(a, b), c) = join(a, join(b, c))
            2 - join(a, neutral) = a
            3 - join(neutral, a) = a
            
            Obs:
            - commutativity is optional
            - This pattern can be used to enforce rules 2 and 3:{
                
                if(l_node.property == neutral_element().property) return r_node;
                if (r_node.property == neutral_element().property) return l_node;
                }

        */
            
            
            Node newnode;

            
            /*
                Add and change stuff here!
            */

            return newnode;
        }

        Node neutral_element(int l, int r){
            return Node();
        }

        int left_child(int idx) {return 2*idx+1;}
        int right_child(int idx) {return 2*idx+2;}
    
};


int main(){



    return 0;
}