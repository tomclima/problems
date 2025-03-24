/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define vec vector<long int>


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

bool vec_equal(vec &vec1, vec &vec2){
    

    for(int i = 0; i < vec1.size(); i++){
        if(vec1[i] != vec2[i]) return false;
    }

    return true;
}

double vec_cross_product(vec v1, vec v2, vec v3){
    return (v2[0] - v1[0]) * (v3[1] - v1[1]) - (v2[1] - v1[1]) * (v3[0] - v1[0]);
}


int point_in_polygon(vector<vec> polygon, vec point){
    
    int n = polygon.size();
    int widing_number = 0;

    for(int i = 0; i < n; i++){
        
        if(vec_equal(point, polygon[i])) return 0;

        int j = (i+1) % polygon.size();
        if(polygon[i][1] == point[1] and polygon[j][1] == point[1]){
            if(min(polygon[i][0], polygon[j][0]) <= point[0] and point[0] <= max(polygon[i][0], polygon[j][0])) return 0;
        }

        else{

            bool below = polygon[i][1]< point[1];

            if(below != polygon[j][1] < point[1]){
                int orientation = vec_cross_product(polygon[i], polygon[j], point);
                if(orientation == 0) return 0;
                if(below == (orientation >  0)){
                    if(below) widing_number++;
                    else widing_number--;
                }
            }
        }
    }
    if(widing_number == 0) return 1;
    else return -1;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vec> polygon;
    polygon.resize(n);
    for(int i = 0; i < n; i++){
        polygon[i].resize(2);
        cin >> polygon[i][0] >> polygon[i][1];
    }
    for(int i = 0; i < m; i++){
        vec point(2);
        cin >> point[0] >> point[1];
        int widing = point_in_polygon(polygon, point);
        if(widing == 0) cout << "BOUNDARY" << endl;
        else if(widing == 1) cout << "OUTSIDE" << endl;
        else cout << "INSIDE" << endl;
    }
}