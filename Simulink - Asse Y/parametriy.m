function [pary] = parametriy()

pary.Jm = 0.074*10^(-3);        %Kg*m^2 n    
% pary.Jm = 0.17*10^(-3);        %Kg*m^2 n    
pary.n = 4;                  %N*m
pary.Cm = 0.45;               %N*m
pary.Jp1 = (1.2135)*10^-4;   %kg*m^2
pary.Jp2 = (6.5420)*10^-4;   %kg*m^2
pary.Jp3 = (0.5990)*10^-4;   %kg*m^2
pary.Mx = 12;               %[Kg]
pary.d1 = (23.87)*10^-3;     %m  
pary.d2 = (76.39)*10^-3;     %m
pary.d3 = (31.83)*10^-3;     %m
pary.r1=pary.d1/2;            %m
pary.r2=pary.d2/2;            %m
pary.r3=pary.d3/2;            %m
pary.a1 = (119)*10^-3;        %m
pary.a2 = (1036)*10^-3;      %m
pary.L1 = calcolo_lunghezza(pary.d1,pary.d2,pary.a1);  %m
pary.L2 = calcolo_lunghezza(pary.d3,pary.d3,pary.a2);  %m
pary.kcs1 = (1.900)*10^7;    %N/m
pary.kcs2 = (2.34)*10^7;     %N/m
pary.W1 = (25)*10^-3;         %m
pary.W2 = (15)*10^-3;        %m

pary.k1 = pary.kcs1*(pary.W1/pary.L1);      %N/m
pary.k2 = pary.kcs2*2*(pary.W2/pary.L2);    %N/m
pary.k3 = pary.k2;                        %N/m
pary.k4 = pary.kcs2*(pary.W2/pary.L2);      %N/m

%calcolo matrice m che è sempre costante nel nel nostro caso
pary.My = [pary.Jm+pary.Jp1, 0, 0, 0;  %:theta1
   0, pary.Jp2+2*pary.Jp3, 0, 0; %:theta2
   0, 0, 2*pary.Jp3, 0;     %:theta3
   0, 0, 0, pary.Mx         ]; %:x
%Per il caso di K costante (approccio iniziale)


pary.Ky = [2*pary.k1*(pary.r1^2) , -2*pary.k1*pary.r2*pary.r1  ,                0,           0;
  -2*pary.k1*pary.r2*pary.r1     , 2*((pary.r3^2)*(pary.k4+pary.k2) + (pary.k1)*(pary.r2^2))   ,    -2*pary.k4*(pary.r3^2)  ,             -2*pary.k2*pary.r3;
   0              ,  -2*pary.k4*(pary.r3^2) ,            (pary.k3+pary.k4)*(pary.r3^2)*2       ,           -2*pary.k3*(pary.r3);
   0 ,                       -2*pary.k2*pary.r3 ,                        -2*pary.k3*(pary.r3) ,                2*(pary.k3+pary.k2)];

pary.z=0.7;
pary.tau = pary.r1*pary.r3/pary.r2;
[pary.Vy, pary.Dy]=show_mode(pary.My,pary.Ky);
% [Vy, Dy]=show_mode(pary.My,pary.Ky);
% pary.Vy = Vy;
% pary.Dy = Dy;

pary.i=3;

end

