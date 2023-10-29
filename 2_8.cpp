#include <bits/stdc++.h>
#include <omp.h>
#include "help.h"

#define newline cout<<endl

using namespace std;

int main(){
    for(int k = 0;k<=14; k+=2){
    omp_set_num_threads(k);
    long n = 100000000;
    for(long long i = n;i<=n;i*=10){
    auto v1 = create_vec(i,1);
    auto v2 = create_vec(i,1);
    // print_vec(v1);
    // newline;
    // print_vec(v2);
    int sum = 0;
    int m = 0;

    double t1 = omp_get_wtime();
     #pragma omp parallel
    {
        #pragma omp for private(m) reduction(+:sum)
        for(int o = 0;o<i;o++){
            m = v1[o]*v2[o];
            sum = sum + m;
        };
    }
    
    double t2 = omp_get_wtime();
    cout<<t2-t1<<",";
    }
    }
    return 0;
}