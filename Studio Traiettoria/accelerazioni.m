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

KK = matrice_Kvar(parx,xx);
parx.KK = KK;
CC = matrice_Cvar(parx,KK);

%C = matrice_C(parx);

F = zeros(4,1);
F(1)=ft1;

%XPP = (par.M^(-1))*(-(par.K*X)-(C*XP)+F);

XPP = (parx.M^(-1))*(-(KK*X)-(CC*XP)+F);

%XPP = (parx.M^(-1))*(-(parx.K*X)-(C*XP)+F);
%K = matrice_Kvar(par,X(4));
%C = matrice_Cvar(par,K);
%XPP = (par.M^(-1))*(-(K*X)-(C*XP)+F);

end

