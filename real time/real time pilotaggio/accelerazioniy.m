function [YPP] = accelerazioniy(ypt1,ypt2,ypt3,ypy,yt1,yt2,yt3,yy,ft1)
global pary;
YP = zeros(4,1);

YP(1)=ypt1;
YP(2)=ypt2;
YP(3)=ypt3;
YP(4)=ypy;

Y = zeros(4,1);

Y(1)=yt1;
Y(2)=yt2;
Y(3)=yt3;
Y(4)=yy;

KKy = matrice_Kvary(pary,yy);
pary.KKy = KKy;
CCy = matrice_Cvary(pary,KKy);
% Cy = matrice_Cy(pary);

F = zeros(4,1);
F(1)=ft1;

% YPP = (pary.My^(-1))*(-(pary.Ky*Y)-(Cy*YP)+F); %rigidezze non variabili
YPP = (pary.My^(-1))*(-(KKy*Y)-(CCy*YP)+F); %rigidezze variabili

end

