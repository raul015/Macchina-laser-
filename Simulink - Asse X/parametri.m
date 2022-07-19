function [par] = parametri()

par.Jm = (15.2)*10^-6;        %Kg*m^2 n    
par.n = 4;                  %N*m
par.Cm = 1.7;               %N*m
par.Jp1 = (0.2006)*10^-4;   %kg*m^2
par.Jp2 = (0.5194)*10^-4;   %kg*m^2
par.Jp3 = (0.1086)*10^-4;   %kg*m^2
par.m = 1.55;               %[Kg]
par.d1 = (23.87)*10^-3;     %m  
par.d2 = (54.12)*10^-3;     %m
par.d3 = (25.46)*10^-3;     %m
par.r1=par.d1/2;            %m
par.r2=par.d2/2;            %m
par.r3=par.d3/2;            %m
par.a1 = (76)*10^-3;        %m
par.a2 = (1275)*10^-3;      %m
par.L1 = calcolo_lunghezza(par.d1,par.d2,par.a1);  %m
par.L2 = calcolo_lunghezza(par.d3,par.d3,par.a2);  %m
par.kcs1 = (1.622)*10^7;    %N/m
par.kcs2 = (2.34)*10^7;     %N/m
par.W1 = (9)*10^-3;         %m
par.W2 = (10)*10^-3;        %m

par.k1 = par.kcs1*(par.W1/par.L1);      %N/m
par.k2 = par.kcs2*2*(par.W2/par.L2);    %N/m
par.k3 = par.k2;                        %N/m
par.k4 = par.kcs2*(par.W2/par.L2);      %N/m

%calcolo matrice m che è sempre costante nel nel nostro caso
par.M = [par.Jm+par.Jp1, 0, 0, 0;  %:theta1
   0, par.Jp2+par.Jp3, 0, 0; %:theta2
   0, 0, par.Jp3, 0;     %:theta3
   0, 0, 0, par.m        %:x
   ];
%Per il caso di K costante (approccio iniziale)
par.K = [2*par.k1*(par.r1^2) , -2*par.k1*par.r2*par.r1  ,                0,           0;
  -2*par.k1*par.r2*par.r1     , (2*par.k1*(par.r2^2))+(par.k2+par.k4)*(par.r3^2)   ,    -par.k4*(par.r3^2)  ,             -par.k2*par.r3;
   0              ,  -par.k4*(par.r3^2) ,            (par.k3+par.k4)*(par.r3^2)       ,           -par.k3*(par.r3);
   0 ,                       -par.k2*par.r3 ,                        -par.k3*(par.r3) ,                par.k3+par.k2];
par.z=0.7;
par.tau = (par.r1*par.r3)/par.r2;  %rapporto di trasmissione carrello e theta1
[par.V, par.D]=show_mode(par.M,par.K);

par.i=3;

end

