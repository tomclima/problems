/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define vec vector<double> 



double vec_dot_product(vec vec1, vec vec2){

    double prod = 0;
    for(int i = 0; i < vec1.size(); i++){
        prod += vec1[i] * vec2[i];
    }
    
    return prod;
}



double vec_mod(vec vec1){
    return sqrt(vec_dot_product(vec1, vec1));
}



void vec_by_scalar(vec vec1, double scal){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] *= scal;
    }
}


void vec_diff(vec vec1, vec vec2, vec diff){
    diff.resize(vec1.size());

    for(int i = 0; i < diff.size(); i++){
        diff[i] = vec1[i] - vec2[i];
    }

}

void vec_sum(vec vec1, vec vec2, vec sum){
    sum.resize(vec1.size());

    vec inverted = vec2;
    vec_by_scalar(inverted, -1);
    vec_diff(vec1, inverted, sum);
}


double vec_dist(vec p1, vec p2){
    
    vec diff;
    vec_diff(p1, p2, diff);

    return sqrt(vec_dot_product(diff, diff));
}

double cosine(vec vec1, vec vec2){
    
    double scal = vec_dot_product(vec1, vec2);

    double mod1 = sqrt(vec_dot_product(vec1, vec1));
    double mod2 = sqrt(vec_dot_product(vec2, vec2));

    return abs((mod1 * mod2)/scal);
}


void vec_proj(vec vec1, vec vec2, vec proj){
    
    double cos = cosine(vec1, vec2);

    double dotvec2 = vec_dot_product(vec2, vec2);

    double dot = vec_dot_product(vec1, vec2);

    proj.resize(vec1.size( ));
    for(int i = 0; i < proj.size(); i++){
        proj[i] = vec2[i] * (dot/dotvec2);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double xm;
    while(cin >> xm){
        double ym;
        int n;
        cin >> ym >> n;
        
        vec m(2);
        m[0] = xm; m[1] = ym;

        priority_queue<double> heap;
        vec best = {INFINITY, INFINITY};
        
        vec last_point(2);
        cin >> last_point[0] >> last_point[1];
        

        double best_dist = INFINITY;
        best = last_point;
        
        for(int i = 1; i < 2 * (n + 1); i++){
            
            vec curr_point(2);
            cin >> curr_point[0] >> curr_point[1];
            double curr_dist = vec_dist(m, curr_point);

            if(curr_dist < heap.top()){
                best = curr_point;
                best_dist = curr_dist;
            }

            vec line(2); vec_diff(last_point, curr_point, line);
            
            vec diff(2); vec_diff(m, curr_point, diff);

            vec proj(2); vec_proj(diff, line, proj);

            if(vec_mod(proj) < vec )
            

            

            

            

        }
        
    }
}