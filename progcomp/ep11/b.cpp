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

bool vec_equal(vec &vec1, vec &vec2){
    

    for(int i = 0; i < vec1.size(); i++){
        if(vec1[i] != vec2[i]) return false;
    }

    return true;
}

double vec_cross_product(vec &v1, vec &v2){
    return v1[0] * v2[1] - v2[0] * v1[1];
}   

double vec_cross_product(vec &v1, vec &v2, vec &v3){
    return (v2[0] - v1[0]) * (v3[1] - v1[1]) - (v2[1] - v1[1]) * (v3[0] - v1[0]);
}

int point_in_triangle(vector<vec> &triangle, vec &ponto){
    
    bool is_in_triangle = false;

    vec side; vec_diff(triangle[0], triangle[0 + 1 % 3], side);

    vec ori_to_point; vec_diff(triangle[0], ponto, ori_to_point);

    double orientation_last = vec_cross_product(side, ori_to_point);

    if(orientation_last == 0) return -1;

    bool left = orientation_last > 0;


    for(int i = 1; i < 3; i++){ 
        
        vec side_curr; vec_diff(triangle[i], triangle[(i + 1) % 3], side_curr);

        vec ori_to_point_curr; vec_diff(triangle[i], ponto, ori_to_point_curr);

        int orientation = vec_cross_product(side_curr, ori_to_point_curr);

        if(orientation == 0) return -1;
        if(left != (orientation > 0)) return 0;
    }

    return 1;
}

bool point_in_polygon(vector<vec> &polygon, vec &ponto){

    int n = polygon.size();

    int l = 1;
    int r = n-1;

    while(abs(r - l) > 1){
        
        int m = l + (r - l)/2;
        
        if(vec_cross_product(polygon[0], polygon[m], ponto) < 0) r = m;
        else l = m;

        

    }
    vector<vec> triangle;
    triangle.push_back(polygon[0]); triangle.push_back(polygon[l]); triangle.push_back(polygon[r]);
    return point_in_triangle(triangle, ponto) != 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d, m;
    cin >> n >> d >> m;

    vec s1(2), s2(2), s3(2), s4(2);

    s1[0] = 0; s1[1] = d;
    s2[0] = d; s2[1] = 0;
    s3[0] = n; s3[1] = n -d;
    s4[0] = n-d; s4[1] = n;

    vector<vec> polygon;
    polygon.push_back(s1);
    polygon.push_back(s2);
    polygon.push_back(s3);
    polygon.push_back(s4);
    

    while(m--){

        vec point(2);
        cin >> point[0] >> point[1];

        if(point_in_polygon(polygon, point)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
