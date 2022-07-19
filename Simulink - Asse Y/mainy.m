clc
clear
close all
global pary;

pary = parametriy ();
%faccio cercare i dati del motore
my=config_dc(pary);

% Cy = matrice_Cy(pary);
%faccio calcolare i dati dell'anello di corrente
ac=anello_corrente(my);
%faccio calcolare i dati dell'anello di velocità
av=anello_velocita(my,ac);
%faccio calcolare i dati dell'anello di posizione
ap=anello_pos(my,av);


scelta = 2; %1=motore / 2=carrello
ppy_m = pos_poli_cc_y(my, ac, 1);
ppy_c = pos_poli_cc_y(my, ac, 2);

