// Read p, R, rule (1..4) from ratio-scan output. R is ignored.
// Direct integer differences of the four sets, for every nonzero shift orbit.
#include <array>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
int main(){
    int p,ignored,rule;
    while(std::cin>>p>>ignored>>rule){
        if(p%32!=17 || rule<1 || rule>4) throw std::invalid_argument("bad row");
        for(int i=2;i<=p/i;++i) if(p%i==0) throw std::invalid_argument("composite");
        std::vector<int> label(p);int g=1;
        while(++g<p){
            int x=1,j=0;
            do{label[x]=j++%16;x=int64_t(x)*g%p;}while(x!=1);
            if(j==p-1) break;
        }
        int pairs[16][16]={};
        for(int x=1;x<p-1;++x) ++pairs[label[x]][label[x+1]];
        bool found=false;
        for(int k=1;k<16 && !found;k+=2){
            bool neg[4][16]={};
            for(int row=0;row<4;++row){
                constexpr int fixed[]={48,12,252,192}, masks[]={0,2,4};
                int m=rule==1?fixed[row]:masks[rule-2], count=0;
                for(int j=0;j<16;++j){
                    int i=(k*j+(rule==1?0:2*row))%16;
                    neg[row][j]=((m>>(i%8))&1) ^ (i>=8);
                    count+=neg[row][j];
                }
                if(count!=8) throw std::logic_error("row size");
                for(int j=0;j<8;++j) if(neg[row][j]==neg[row][j+8]) throw std::logic_error("skew");
            }
            bool correct=true;
            for(int t=0;t<16;++t){
                int total=0;
                for(int i=0;i<16;++i) for(int j=0;j<16;++j) for(int r=0;r<4;++r)
                    if(neg[r][(i+t)%16] && neg[r][(j+t)%16]) total+=pairs[i][j];
                if(total!=p-3) correct=false;
            }
            if(correct){std::cout<<p<<" "<<g<<" "<<k<<" "<<rule<<" "<<p-3<<"\n";found=true;}
        }
        if(!found) throw std::logic_error("no witnessed relabeling");
    }
}
