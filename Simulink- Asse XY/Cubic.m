function [ G, F, f ] = Cubic( x )
% function [ G, F, f ] = Cubica( par, x )
% Progettazione Funzionale di Sistemi Meccanici e Meccatroncici
% prof. Paolo Righettini
% 
% Descrive la legge di moto cubica tagliata in forma adimensionale 
%
% ritorna il valore di accelerazione, velelocita'  spostameto adimensionali
% calcolati al tempo adimensionale x
% par: nessun parametro per configurarla
% x: tempo adimensionale a cui calcolare la ldm. 0 <= x <= 1
%
% G, F, f: Posizione, velocità, accelerazione adimensionale calcolati

if( x >= 0 && x <= 1 )
    f = -12*(x-1/2);
    F = -12*0.5*(x-1/2)^2 + 3/2;
    G = -6/3*(x-1/2)^3 + 3/2*(x-1/2) + 1/2;
else
    f=0;
    F=0;
    G=0;
end