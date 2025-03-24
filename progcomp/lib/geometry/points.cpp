/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int



double vec_dot_product(vector<double> vec1, vector<double> vec2){

    double prod = 0;
    for(int i = 0; i < vec1.size(); i++){
        prod += vec1[i] * vec2[i];
    }
    
    return prod;
}



double vec_module(vector<double> vec){
    return sqrt(vec_dot_product(vec, vec));
}



void vec_by_scalar(vector<double> vec1, double scal){
    for(int i = 0; i < vec1.size(); i++){
        vec1[i] *= scal;
    }
}


void vector_diff(vector<double> vec1, vector<double> vec2, vector<double> diff){
    diff.resize(vec1.size());

    for(int i = 0; i < diff.size(); i++){
        diff[i] = vec1[i] - vec2[i];
    }

}


double vec_dist(vector<double> p1, vector <double> p2){
    
    vector<double> diff;
    vector_diff(p1, p2, diff);

    return sqrt(vec_dot_product(diff, diff));
}

double cosine(vector<double> vec1, vector<double> vec2){
    
    double scal = vec_dot_product(vec1, vec2);

    double mod1 = sqrt(vec_dot_product(vec1, vec1));
    double mod2 = sqrt(vec_dot_product(vec2, vec2));

    return abs((mod1 * mod2)/scal);
}


void proj(vector<double> vec1, vector<double>vec2, vector<double> proj){
    
    double cos = cosine(vec1, vec2);

    double dotvec2 = vec_dot_product(vec2, vec2);

    double dot = vec_dot_product(vec1, vec2);

    proj.resize(vec1.size( ));
    for(int i = 0; i < proj.size(); i++){
        proj[i] = vec2[i] * (dot/dotvec2);
    }
}


void vector_sum(vector<double> vec1, vector<double> vec2, vector<double> sum){
    sum.resize(vec1.size());

    vector<double> inverted = vec2;
    vec_by_scalar(inverted, -1);
    vector_diff(vec1, inverted, sum);
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}