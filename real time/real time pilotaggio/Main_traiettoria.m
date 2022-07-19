clc
clear all
close all

%parametri del sistema
global parx;
global pary;
%% script per  lo studio della traiettoria

file='.\zig.dxf';
                 %file,passo di campionamento,visualizazzione ok
[trajectory, errore]=dxf_box_3(file,1,1);
trajectory.l
axis equal; % mette in scala la figura
figure;
plot(trajectory.x,trajectory.y,'r.'); %figure 2

%inizializzazione di s,x,y
npt=trajectory.nPti;
S=trajectory.s;   %ascissa curvilinea 504X1
                  %percorrenza traiettoria,parte da 0
X=trajectory.x;   % Coordinate X,Y che individuano il punto S 
Y=trajectory.y;   % c'è correlazione tra coordinate 
n=length(S);      %stessa cosa per X o Y
%questa la vedo come una matrice il quale mi consente tramite
%interpolazione di determinare x,y

%equazione matriciale del testo (vedi appunti Prof. Strada)


%% Legge di moto poli_quinto_grado
% t0=0;
% tf=3; %tempo di stop simulazione, come quello simulink
% alzata=S(n);
% np = 1000;
% time = t0:(tf-t0)/np:tf;
% 
% 
%     for i =1:length(time)
%         sp(i,:) = poli_quinto_grado(t0,tf,alzata,time(i));
%         %sp(i,:) = Evaluate_Trajectory(tf,alzata)
%     end
    
%% Legge di moto Constant acceleration adim + Evaluate_Trajectory
%voglio che la traiettoria sia eseguita con una legge di moto
%devo assegnare una legge di moto all'ascissa curvilinea

tf=3; %tempo di stop simulazione, come quello simulink
h=S(n); %alzata, o meglio spostamento richiesto
np = 1000; %numeri di punti presenti nella traiettoria
time = 0:tf/np:tf; % divido la finestra temporale in più finestre temporali
 
%sto definendo la legge di moto in quanto ho un vettore dei tempi
%in corrispondenza di un certo andamento di s.
%ovvero una volta impostato lo spostamento obiettivo e il tempo
%che incrementa ottengo pos,vel,acc per la percorrenza della traiettoria
for i =1:length(time)
    sp(i,:) = Evaluate_Trajectory(time(i),h);
end
%sp cambia in base alla legge di moto 
%legge di moto fatto in modo tale che una volta raggiunto lo spostamento
%obiettivo ritorni a 0 in modo analogo...comportamento simmetrico

%% Plot andamento
%figure 3
figure('Name','Legge di moto polinomiale')
% figure('Name','Legge di ad accelerazione costante simmetrica')
plot(time,sp(:,1),'k')
hold on
plot(time,sp(:,2),'g')
plot(time,sp(:,3),'r')
grid on
legend('posizione[rad]',' Velocità [rad/s]', ' Accelerazione [rad/s^2]')
legend('Location' , 'NorthWest')


%legge di moto ascissa curvilinea --> info nel tempo di pos,vel,acc
s_ldm = sp (:,1);   %vettore posizione di s
v_ldm = sp (:,2);   %vettore velocita di s
a_ldm = sp (:,3);   %vettore accelerazione di s 
%vettore di dimensione uguale ai tempi di visione
x=zeros(length(time),1); 
y=zeros(length(time),1);
%n = npt = numero punti traiettoria del punto 1 
%il -1 perchè la prima riga sono tutti settatit a 0

    %   calcolo velocità e accelerazioni geometriche X,Y
    %   ovvero in funzione della posizione
for i=1: (npt-1)
    %delta proviene dalla formula pdf pag.2 in fondo
    delta(i) = S(i+1)-S(i); 
    %formule a pag.3 in fondo alla pagina

    X_primo(i+1) = (X(i+1)-X(i))/(delta(i)); 
    Y_primo(i+1) = (Y(i+1)-Y(i))/(delta(i)); 
    X_secondo(i+1) = (X_primo(i+1)-X_primo(i))/(delta(i)); 
    Y_secondo(i+1) = (Y_primo(i+1)-Y_primo(i))/(delta(i)); 
end

%adesso mediante interpolazione lineare posso determinare coordinate
%X,X',X'',Y,Y',Y''(geometriche) per valori di ascissa s intermedi tra
%quelli indicati nel vettore S

for i=1:length(time) %pagina 2/7 dispense Strada - sistema strategia di pilotaggio traiettoria
 %funzione interpolazione
 %argomenti funzione interp1:
 %  -vettore s(ascissa curvilinea) 
 %  -vettore coordinate traiettoria 
 %  -elemento Si in corrispondenza della
 %   quale voglio trovare la S ed X
 
 %inoltre so che il tempo è di 3 secondi e lo raggiungo il mille passi 
 %quindi 1001 punti (per lo zero)
 
 %s_ldm -> legge oraria posizione -> nel tempo
    %interpolazione spostamento
    x(i)=interp1(S,X,s_ldm(i),'Linear'); 
    y(i)=interp1(S,Y,s_ldm(i),'Linear');
    %interpolazione velocità
    x_primo(i)=interp1(S,X_primo,s_ldm(i),'Linear');
    y_primo(i)=interp1(S,Y_primo,s_ldm(i),'Linear');
    %interpolazione accelerazione
    x_secondo(i)=interp1(S,X_secondo,s_ldm(i),'Linear');
    y_secondo(i)=interp1(S,Y_secondo,s_ldm(i),'Linear');
    
    %formule velocità e accelerazione lungo gli assi 
    %pagina 2 evidenziato in rosso
    %velocita e accelerazioni lungo gli assi x,y
    x_p(i) = x_primo(i)*v_ldm(i);
    x_pp(i) = x_secondo(i)*v_ldm(i)^2+x_primo(i)+a_ldm(i);
    y_p(i) = y_primo(i)*v_ldm(i);
    y_pp(i) = y_secondo(i)*v_ldm(i)^2+y_primo(i)+a_ldm(i);
end
%figure 4
figure('Name','Verifica interpolazione')
plot(x,y) % verifica dei valori interpolati

figure('Name','Posizione asse x')
plot(time,x,'r')
hold on
figure('Name','Velocità asse x')
plot(time,x_p,'b')
hold on
figure('Name','Accelerazione asse x')
plot(time,x_pp,'g')
hold on

figure('Name','Posizione asse y')
plot(time,y,'r')
hold on
figure('Name','Velocità asse y')
plot(time,y_p,'b')
hold on
figure('Name','Accelerazione asse y')
plot(time,y_pp,'g')
hold on

%% definizione parametri caretteristici del sistema
[parx,pary]= parametri();
%parametri del motore 
mx = config_dc_x(parx);
my = config_dc_y(pary);
%anello di corrente
acx = anello_corrente( mx );
acy = anello_corrente( my );
%anello di velocita
avx = anello_velocita( mx, acx );
avy = anello_velocita( my, acy );

%anello di posizione
apx = anello_pos(mx, avx);
apy = anello_pos(my, avy);

% sceltax = 1; %1=motore / 2=carrello
% ppx = pos_poli_cc(mx, acx,sceltax);
% 
% sceltay = 1; %1=motore / 2=carrello
% ppy = pos_poli_cc(my, acy,sceltay);
%% definizione dei limiti

