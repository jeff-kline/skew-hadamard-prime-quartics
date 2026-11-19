\\ Run from the repository root with gp -q code/quartic-counts.gp.
forms = [[1,8,8],[1,16,32],[49,80,32],[1,80,1568]];
limit = 250000;
primecut = 100000;
value(f,u,v) = f[1]*u^4 + f[2]*u^2*v^2 + f[3]*v^4;
area(a,b,c) = intnum(t=0,1,1/sqrt(a+b*t^2+c*t^4)+1/sqrt(c+b*t^2+a*t^4))/2;
localfactor(ell,k) = (1-(1+(ell-1)*k)/ell^2)/(1-1/ell);
{
  my(product = 1.0);
  forprime(ell = 3, primecut,
    my(roots = if(ell%16 == 1 || ell%16 == 7, 4, 0));
    product *= localfactor(ell, roots)
  );
  my(witnesses = readstr("evidence/ratio-witnesses.txt"));
  my(rulehits = vector(3, j, List()));
  for(index = 1, #forms,
    my(f = forms[index], hits = List());
    for(u = 1, sqrtint(sqrtint(limit)),
      for(v = 1, sqrtint(sqrtint(limit)),
        my(p = value(f,u,v));
        if(p <= limit && p%32 == 17 && isprime(p), listput(hits,p))
      )
    );
    my(sorted = vecsort(Vec(hits)));
    if(#sorted != #Set(sorted), error("repeated positive representation"));
    foreach(sorted,p,listput(rulehits[min(index,3)],p));
    my(correction = if(index<3,1,localfactor(7,3)/localfactor(7,4)));
    my(estimate = area(f[1],f[2],f[3])*product*correction*sqrt(limit)/(2*log(limit)));
    print("form ",index,": ",sorted,"  leading estimate = ",precision(estimate,5))
  );
  for(rule = 1, 3,
    my(recorded = List());
    foreach(witnesses,line,
      my(fields = strsplit(line," "));
      if(#fields == 5 && eval(fields[4]) == rule, listput(recorded,eval(fields[1])))
    );
    if(vecsort(Vec(rulehits[rule])) != vecsort(Vec(recorded)), error("witness mismatch"));
  );
  print("All three rule lists agree with the modular scan.")
}
