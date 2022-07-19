close all
clc
clear

global parx;
global pary;
%parametri del sistema

[parx,pary]= parametri();
%parametri del motore 
mx = config_dc_x(parx);
my = config_dc_y(pary);
%anello di corrente
acx = anello_corrente( mx );
acy = anello_corrente( my );
%anello di velocita
avx = anello_velocita( mx, acx );
avy = anello_velocita( my, acy );

%anello di posizione
apx = anello_pos(mx, avx);
apy = anello_pos(my, avy);

%posizionamento poli con retroazione sul motore
ppx_m = pos_poli_cc_x(mx, acx, 1);
ppy_m = pos_poli_cc_y(my, acy, 1);

%posizionamento poli con retroazione sul carrello 
ppx_c = pos_poli_cc_x(mx, acx, 2);
ppy_c = pos_poli_cc_y(my, acy, 2);

% sceltax = 1; %1=motore / 2=carrello
% ppx = pos_poli_cc(mx, acx,sceltax);
% sceltay = 1; %1=motore / 2=carrello
% ppy = pos_poli_cc(my, acy,sceltay);

