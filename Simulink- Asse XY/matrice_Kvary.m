function [KKy] = matrice_Kvary(pary,yy)
%mi serve la posizione della massa M per determinare la effettiva lunghezza
%dei due lati...
%ltot2 
k1 = pary.kcs1*(pary.W1/pary.L1);
k2 = pary.kcs2*(pary.W2/(pary.L2+yy));
k3 = pary.kcs2*(pary.W2/(pary.L2 - yy));
k4 = pary.kcs2*(pary.W2/pary.L2);

pary.Ky = [2*k1*(pary.r1^2) , -2*k1*pary.r2*pary.r1  ,                0,           0;
  -2*k1*pary.r2*pary.r1     , 2*((pary.r3^2)*(k4+k2) + (k1)*(pary.r2^2))   ,    -2*k4*(pary.r3^2)  ,             -2*k2*pary.r3;
   0              ,  -2*k4*(pary.r3^2) ,            (k3+k4)*(pary.r3^2)*2       ,           -2*k3*(pary.r3);
   0 ,                       -2*k2*pary.r3 ,                        -2*k3*(pary.r3) ,                2*(k3+k2)];
KKy=pary.Ky; 

end

