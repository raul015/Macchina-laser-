close all
clc
clear

global parx;

%parametri del sistema
parx = parametri();

%parametri del motore 
m = config_dc(parx);

%anello di corrente
ac = anello_corrente( m );

%anello di velocita
av = anello_velocita( m, ac );

%anello di posizione
ap = anello_pos(m, av);

scelta = 2; %1=motore / 2=carrello
pp_m = pos_poli_cc_x(m, ac,1);
pp_c = pos_poli_cc_x(m, ac,2);