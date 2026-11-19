Q=x^8+1;
L(m,u)=sum(j=0,7,(1-2*bittest(m,j))*Mod(x,Q)^(u*j));
P=[y^2-2*y-1,y^2+2*y-1,y^2-14*y-1,17*y^4-44*y^3+66*y^2-52*y+17];
ms=[48,12,252,192];
{forstep(d=2,14,2,forstep(u=1,d\2,2,
  v=d-u; C=sum(i=1,4,L(ms[i],u)*L(ms[i],v));
  want=if(d!=8,0,if(u==1,16*(x+x^7),16*(x^3+x^5)));
  if(C!=Mod(want,Q),error("fixed quartet",d,u))))}
{forstep(m=0,254,2,
  A=L(m,1)*L(m,7); B=L(m,3)*L(m,5);
  N=polresultant(Q,lift(A)+y*lift(B),x);
  j=if(N==2^14*P[2]^4,2,if(N==2^14*P[3]^4,3,if(N==2^14*P[4]^2,4,0)));
  if(!j,error("unclassified mask ",m));
  if(m==0 || m==2 || m==4,if(j!=(m/2+2),error("wrong representative ",m)));)}
print("All fixed-mask products and 128 rotation-mask resultants verified.");
