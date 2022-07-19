function s = poli_quinto_grado(to,tf,alzata,xloc)

% polinomiale di 5° grado
% Restituisce il vettore s = [posizione,velocità,accelerazione]

AAy= [  1, to, to^2, to^3,   to^4,    to^5;
        0, 1,  2*to, 3*to^2, 4*to^3,  5*to^4;
        0, 0,  2,    6*to,   12*to^2, 20*to^3;
        1, tf, tf^2, tf^3,   tf^4,    tf^5;
        0, 1,  2*tf, 3*tf^2, 4*tf^3,  5*tf^4;
        0, 0,  2,    6*tf,   12*tf^2, 20*tf^3];
BBy = [0;0;0;alzata;0;0];
CCy = AAy\BBy; %[f,e,d,c,b,a]

a = 2*CCy(3)+6*CCy(4)*xloc+12*CCy(5)*xloc^2+20*CCy(6)*xloc^3;
v = CCy(2)+2*CCy(3)*xloc+3*CCy(4)*xloc^2+4*CCy(5)*xloc^3+5*CCy(6)*xloc^4;
p = CCy(1)+CCy(2)*xloc+CCy(3)*xloc^2+CCy(4)*xloc^3+CCy(5)*xloc^4+CCy(6)*xloc^5;

s = [p,v,a];