/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

template<typename T>
class segTree{
     
    public:
        vector<T> seg;
        int n;
        vector<T> a;

        segTree(const vector<T> &arr){
            a = arr;
            seg.resize(4*a.size());
            n = a.size();
            build()
        }
        
        T query(const int L, const int R){
            return query_helper(L, R);
        }
        
        void update(){
            update_helper()
        }
        private:

        /*
        ------------------------------------------
        -------ATENTION----------------------
        ----------------------------------
        THIS CHANGES ACCORDING TO THE PROBLEM AND DATATYPE
        */
        void join(T a, T b){
            return a+b;
        }
    
        void neutral(){
            return 0;
        }
        
        /*
        
        THIS REMAINS MOSTLY THE SAME
        */
        
        void build(int l = 0, int r = n-1, int idx = 0){
            
            // if current node is a leaf
            if (l == r){
                seg[idx] = a[l];

                return;
            }
            
            int mid = (l + r)/2;
            // build left child
            build(l, mid, 2*idx + 1);
            // build right child
            build(mid+1, r,2*idx + 2);

            // build node
            seg[idx] = join(seg[2*idx+1], join(2*idx+2));
        }

        
        
        T query_helper(int L, int R, int l = 0, int r=n-1, int idx=0){
            
            // If outside range, return neutral element
            if(r < L || l > R) return neutral();
            
            // If wholly inside range, return node value
            if(l >= L && r <= R) return seg[idx];
            
            // else, join left and right queries
            int mid = (l + r)/2;
            
            return join(query(L, R, l, mid+1, 2*idx+1), query(L, R, mid+1, r, 2*idx+2));   
        }
        
        void update_helper(int I, T VAL, int l=0, int r = n-1, int idx=0){
            
            // If node is the leaf itself
            if (l == r){
                seg[idx] = VAL;
                return;
            }
            
            // otherwise, update left or right nodes
            int mid = (l + r)/2;
            
            // update left or right node 
            if(i <= mid) update(I, VAL, l, mid+1, 2*idx+1)
            else update(I, VAL, mid+1, r, 2*idx+2);
            
            // update node
            seg[idx] = join(seg[2*idx+1], seg[2*idx+2]);
            
        }
        
        
    };
    
    
    


int main(){



    return 0;
}