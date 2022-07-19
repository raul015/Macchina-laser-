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

xv = par(1);
xw = par(2);
  


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
