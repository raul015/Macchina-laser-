function [XPP] = accelerazioni(xpt1,xpt2,xpt3,xpx,xt1,xt2,xt3,xx,ft1)
global parx;
XP = zeros(4,1);

XP(1)=xpt1;
XP(2)=xpt2;
XP(3)=xpt3;
XP(4)=xpx;

X = zeros(4,1);

X(1)=xt1;
X(2)=xt2;
X(3)=xt3;
X(4)=xx;

%Equazioni per rigidezze e smorzamenti variabili

KK = matrice_Kvar(parx,xx);
parx.KK = KK;
CC = matrice_Cvar(parx,KK);
F = zeros(4,1);
F(1)=ft1;
XPP = (parx.M^(-1))*(-(KK*X)-(CC*XP)+F);

%Equazioni per le rigidezze e smorzamenti costanti

% C = matrice_C(parx);
% F = zeros(4,1);
% F(1)=ft1;
% XPP = (parx.M^(-1))*(-(parx.K*X)-(C*XP)+F);



end

