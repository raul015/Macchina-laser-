function [G,F,f] = Constant_Acceleration_ADIM_par(x,par)
% function [G,F,f] = Constant_Acceleration_ADIM_par(x,par)
% prof. Paolo Righettini
% Progettazione Funzionale di Sistemi Meccanici e Meccatronici
%
% x = t/td
% par(1) = adimensional time (start point at maximum velocity)
% par(2) = adimensional time (end point at maximum velocity)
% G = adimensionalized displacement
% F = adimensionalized velocity
% f = adimensionalized acceleration

%la funzione identifica in modo adimensionale una accele
%razione costante --> profilo di moto ad acc. costante
%profili di moto che vanno da Vel=0 e arrivano a Vel=0.
%xv,xw 2 tempi adimensionali
%che identificano quanto dura l'acc + e acc-
G=0; F=0; f=0;
%xv e xw ci permette di fare profili di moto asimmetrici
xv = par(1);  % tempo ad. e identifica quanto dura acc+
xw = par(2);  % tempo ad. e identifica quanto dura acc-

A = 2/(xv *(1-xv+xw));
B = 2/((1-xw)*(1-xv+xw));

if x>=0 & x<=xv
   f=A;
   F=A*x;
   G=.5*A*x^2;
elseif x>xv & x<xw
   f=0;
   F=A*xv;
   G=A*xv*(x-xv/2);
elseif x>=xw & x<=1
   f=-B;
   F=A*xv-B*(x-xw);
   G=A*xv*(x-xv/2)-B/2*(x-xw)^2;
end
