// C++17. Rebuild the four signed matrices and check every entry and row pair.
// With --emit ORDER, print that sign matrix in border-first order after validation.
#include <array>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Seed { int p, generator; std::array<unsigned,4> masks; };
constexpr Seed seeds[]={
    {1009,11,{255,13973,48322,47288}},
    {1297,10,{765,31425,21866,38610}},
    {1489,14,{765,13916,7507,25542}},
    {1553,3,{11475,13005,19125,21675}}
};
constexpr int corner[4][4]={{1,1,1,1},{-1,1,-1,1},{-1,1,1,-1},{-1,-1,1,1}};
constexpr int upper[4][4]={{-1,-1,-1,-1},{-1,-1,1,1},{-1,1,1,-1},{-1,1,-1,1}};
constexpr int core[4][4]={{1,2,3,4},{-2,1,-4,3},{-3,4,1,-2},{-4,-3,2,1}};

void check(const Seed &seed,bool emit){
    const int p=seed.p,n=4*(p+1),words=(n+63)/64;
    std::vector<std::array<int,4>> f(p);
    f[0].fill(1);
    int x=1;
    for(int j=0;j<p-1;++j){
        if(f[x][0]) throw std::logic_error("generator repeats");
        for(int b=0;b<4;++b) f[x][b]=2*int((seed.masks[b]>>(j%16))&1u)-1;
        x=int64_t(x)*seed.generator%p;
    }
    if(x!=1) throw std::logic_error("generator period");
    auto entry=[&](int i,int j){
        if(i<4 && j<4) return corner[i][j];
        if(i<4) return upper[i][(j-4)/p];
        if(j<4) return -upper[j][(i-4)/p];
        const int a=(i-4)/p,b=(j-4)/p,r=(i-4)%p,s=(j-4)%p;
        if(a==b) return f[(s-r+p)%p][0];
        int label=core[a][b];
        int pos=(!a || !b)?(2*p-r-s)%p:(r+s)%p;
        return (label>0?1:-1)*f[pos][std::abs(label)-1];
    };
    std::vector<uint64_t> bits(size_t(n)*words);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j){
        int v=entry(i,j);
        if((i==j && v!=1)||(i<j && v!=-entry(j,i))) throw std::logic_error("skew");
        if(v==1) bits[size_t(i)*words+j/64]|=uint64_t(1)<<(j%64);
    }
    for(int i=1;i<n;++i) for(int j=0;j<i;++j){
        int distance=0;
        auto a=&bits[size_t(i)*words], b=&bits[size_t(j)*words];
        for(int w=0;w<words;++w) distance+=__builtin_popcountll(a[w]^b[w]);
        if(distance!=n/2) throw std::logic_error("row distance");
    }
    std::cerr<<n<<" verified: "<<int64_t(n)*(n-1)/2<<" pairs, distance "<<n/2<<"\n";
    if(emit) for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) std::cout<<(entry(i,j)>0?'+':'-');
        std::cout<<'\n';
    }
}
int main(int argc,char**argv){
    if(argc==1){for(const Seed &s:seeds) check(s,false);return 0;}
    if(argc==3 && std::string(argv[1])=="--emit"){
        for(const Seed &s:seeds) if(4*(s.p+1)==std::atoi(argv[2])){check(s,true);return 0;}
    }
    std::cerr<<"Use no arguments, or --emit 4040|5192|5960|6216\n";return 2;
}
