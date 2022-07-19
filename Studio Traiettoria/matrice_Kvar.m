function [K] = matrice_Kvar(par,x)
%mi serve la posizione della massa M per determinare la effettiva lunghezza
%dei due lati...
%ltot2 
k1 = par.kcs1*(par.W1/par.L1);
k2 = par.kcs2*(par.W2/(par.L2+x));
k3 = par.kcs2*(par.W2/(par.L2 - x));
k4 = par.kcs2*(par.W2/par.L2);

  K = [2*k1*(par.r1^2) , -2*k1*par.r2*par.r1  ,  0,           0;
  -2*k1*par.r2*par.r1 , (2*k1*(par.r2^2))+(k2+k4)*(par.r3^2)   ,    -k4*(par.r3^2)  ,  -k2*par.r3;
   0  ,  -k4*(par.r3^2) ,  (k3+k4)*(par.r3^2) ,   -k3*(par.r3);
   0 ,  -k2*par.r3 ,   -k3*(par.r3) ,  k3+k2];

end

