function [G,F,f,J] = Polinomiale_7g(x)
%ex Polinomiale2 
% punto di partenza : 
% esercitazione n°2 sulla polinomiale (G fino al% 7°ordine)

if (x>=0 && x<=1)    

G=35*(x)^4-84*(x)^5+70*(x)^6-20*(x)^7;
F=140*(x)^3-420*(x)^4+420*(x)^5-140*(x)^6;
f=420*(x)^2-1680*(x)^3+2100*(x)^4-840*(x)^5;
J=840*(x)-5040*(x)^2+8400*(x)^3-4200*(x)^4;

else
    f=0;     F=0;     G=0;

end

