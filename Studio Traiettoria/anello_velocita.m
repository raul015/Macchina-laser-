function [av] = anello_velocita(m, ac)
%ANELLO_VELOCITA Summary of this function goes here
%m: dato strutturato con i dati del motore
% ac: dato con i parametri anello in corrente
% parametro in uscita
% av: dati anello di velocita

%frequenza critica
fcv = ac.fc/10;
wcv = 2*pi*fcv; %puls. critica

%marigine di fase
phi = 80*pi/180; %in [rad]

tiv = tan(phi)/wcv; %costnte di tempo integrale

%guadagno
kgv = (wcv^2 * tiv * m.Jma)/(m.K * sqrt(1 + (wcv*tiv)^2));

%fdt del regolatore PI
PI_V = kgv * tf([tiv, 1],[tiv, 0]);

%funzione d'anello del sistema semplificato
L_simple = PI_V * m.K * tf([1],[m.Jma, 0]);

%completa
L = PI_V * ac.H_I * m.K * tf([1],[m.Jma, 0]);

%fdt ad anello chiuso
H_W_simple = feedback(L_simple,1);

H_W = feedback(L,1);

% % % % % % %diagrammi
% % % % % % figure
% % % % % % bode(H_W_simple,H_W);
% % % % % % grid on
% % % % % % legend('simple','completa')
% % % % % % title('fdt anello chiuso velocita');

% salvo le informazioni di intersse
av.fc = fcv;
av.kgv = kgv;
av.tiv = tiv;
av.PI_V = PI_V;
av.H_W = H_W;
av.H_W_simple = H_W_simple;


end

