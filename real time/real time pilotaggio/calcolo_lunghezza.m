function [lunghezza] = calcolo_lunghezza(diametro1,diametro2,interasse)
raggio1 = diametro1/2;
raggio2 = diametro2/2;

lunghezza_tot=(2*interasse)+(pi/2)*(diametro1+diametro2)+(((diametro1-diametro2)^2)/(4*interasse));
lunghezza_intermedia=lunghezza_tot-pi*(raggio1+raggio2);
lunghezza=lunghezza_intermedia/2;

end

