/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define vec vector<double> 



double vec_dot_product(vec &vec1, vec &vec2){

    double prod = 0;
    for(int i = 0; i < vec1.size(); i++){
        prod += vec1[i] * vec2[i];
    }
    
    return prod;
}



double vec_mod(vec &vec1){
    return sqrt(vec_dot_product(vec1, vec1));
}



void vec_by_scalar(vec &vec1, double scal){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] *= scal;
    }
}


void vec_diff(vec &vec1, vec &vec2, vec &diff){
    diff.resize(vec1.size());

    for(int i = 0; i < diff.size(); i++){
        diff[i] = vec1[i] - vec2[i];
    }

}

void vec_sum(vec &vec1, vec &vec2, vec &sum){
    sum.resize(vec1.size());

    vec inverted = vec2;
    vec_by_scalar(inverted, -1);
    vec_diff(vec1, inverted, sum);
}


double vec_dist(vec &p1, vec &p2){
    
    vec diff;
    vec_diff(p1, p2, diff);

    return sqrt(vec_dot_product(diff, diff));
}

double cosine(vec &vec1, vec &vec2){
    
    double scal = vec_dot_product(vec1, vec2);

    double mod1 = sqrt(vec_dot_product(vec1, vec1));
    double mod2 = sqrt(vec_dot_product(vec2, vec2));

    return (mod1 * mod2)/scal;
}


void vec_proj(vec &vec1, vec &vec2, vec &proj){
    
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

    double xm, ym;
    int n;
    while(cin >> xm >> ym >> n){
    
        
        vec m(2);
        m[0] = xm; m[1] = ym;

        vec best = {INFINITY, INFINITY};
        
        vec last_point(2);
        cin >> last_point[0] >> last_point[1];
        

        double best_dist = vec_dist(last_point, m);
        best = last_point;

        
        for(int i = 0; i < n; i++){
            
            vec curr_point(2);
            cin >> curr_point[0] >> curr_point[1];
            double curr_dist = vec_dist(m, curr_point);

            if(curr_dist < best_dist){
                best = curr_point;
                best_dist = curr_dist;
            }

            vec line(2); vec_diff(curr_point, last_point, line);
            
            vec diff(2); vec_diff(m, last_point , diff);

            vec proj(2); vec_proj(diff, line, proj);

            if(cosine(proj, line) >= 0 and vec_mod(proj) < vec_mod(line)){

                vec min_dist(2); vec_diff(diff, proj, min_dist);

                double min_dist_mod = vec_mod(min_dist);
                
                if(min_dist_mod < best_dist){

                    vec_sum(last_point, proj, best);
                    best_dist = min_dist_mod;

                }
                
            }

            last_point = curr_point;

        }

        cout << fixed << setprecision(4) <<   best[0] << endl << best[1] << endl;
        
    }
}