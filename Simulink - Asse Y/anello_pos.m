function [ap] = anello_pos(m, av)

%function [ap] = anello_pos(m, av)
%m: motore
%av: parametri anello di velocita
%uscita
% ap: parametri anello di posizione


fcp = av.fc/10;
wcp = 2*pi*fcp;
wcv = 2*pi*av.fc;

%guadango
kgp = wcp*sqrt(1 + (wcp/wcv)^2);

%fdt semplificata anello di velocita
H_W_simple = tf([1],[1/wcv, 1]);

%f.anello semplificata
L_simple = kgp * H_W_simple * tf([1],[1, 0]);

L = kgp * av.H_W * tf([1],[1, 0]);

%fdt anello chiuso
H_P_simple = feedback(L_simple,1);

H_P = feedback(L,1);

% %diagrammi
% figure
% bode(H_P_simple,H_P);
% grid on;
% legend('simple','completa')
% title('fdt anello chiuso in posizione')

%salvo
ap.fc = fcp;
ap.P = kgp*tf(1,1);
ap.H_P_simple = H_P_simple;
ap.H_P = H_P;




end

