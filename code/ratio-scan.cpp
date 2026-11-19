// clang++ -O2 -std=c++17 prime-ratio-scan.cpp -o /tmp/ratio-scan
// Search the four proved polynomial criteria up to the requested inclusive bound.
#include <array>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
using i64 = std::int64_t;
i64 power(i64 a,int e,int p){
    i64 r=1;
    while(e){
        if(e&1) r=r*a%p;
        a=a*a%p; e>>=1;
    }
    return r;
}
int main(int argc,char **argv){
    int limit=argc>1?std::atoi(argv[1]):250000;
    if(limit<17 || limit>10000000) return 2;
    std::vector<bool> composite(limit+1);
    for(int j=2;j<=limit/j;++j) if(!composite[j])
        for(int k=j*j;k<=limit;k+=j) composite[k]=true;
    int tested=0;
    for(int p=17;p<=limit;p+=32) if(!composite[p]){
        ++tested;
        int h=(p-1)/16;
        i64 f=1;
        std::array<i64,8> fac{};
        for(int j=1;j<=7;++j){
            for(int k=(j-1)*h+1;k<=j*h;++k) f=f*k%p;
            fac[j]=f;
        }
        i64 r=(fac[1]*fac[7]%p)*power(fac[3]*fac[5]%p,p-2,p)%p;
        std::array<i64,4> polynomials={r*r-2*r-1,r*r+2*r-1,r*r-14*r-1,
            (((17*r-44)*r%p+66)*r%p-52)*r%p+17};
        for(int j=0;j<4;++j) if(polynomials[j]%p==0)
            std::cout<<p<<" "<<r<<" "<<j+1<<"\n";
    }
    std::cerr<<"eligible primes checked: "<<tested<<"\n";
}
