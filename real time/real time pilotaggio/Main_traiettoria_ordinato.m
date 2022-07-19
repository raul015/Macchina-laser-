clc
clear 
close all

%% Defizione dei parametri del sistema 
global parx;
global pary;
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
%TODO inserire controllo tramitee posizionamento dei poli
sceltax = 2; %1=motore / 2=carrello
ppx = pos_poli_cc_x(mx, acx,sceltax);

sceltay = 2; %1=motore / 2=carrello
ppy = pos_poli_cc_y(my, acy,sceltay);

%% Script per  lo studio della traiettoria

file='.\zig.dxf';
                 %file,passo di campionamento,visualizazzione ok
[trajectory, errore]=dxf_box_3(file,1,1);
trajectory.l;
axis equal; % mette in scala la figura
figure;
plot(trajectory.x,trajectory.y,'r.'); %figure 2

npt=trajectory.nPti;    % numero punti traiettoria
S=trajectory.s;         % ascissa curvilinea 504X1,percorrenza traiettoria parte da 0
X=trajectory.x;         % Coordinate X,Y che individuano il punto S 
Y=trajectory.y;         % c'è correlazione tra coordinate 
n=length(S);            %stessa cosa per X o Y
%% Calcolo accelerazione e velocità geometria 
delta = zeros(npt,1);
X_primo = zeros(npt,1);
X_secondo = zeros(npt,1);
Y_primo = zeros(npt,1);
Y_secondo = zeros(npt,1);
for i=1: (npt-1)
    %delta proviene dalla formula pdf pag.2 in fondo
    delta(i) = S(i+1)-S(i); 
    %formule a pag.3 in fondo alla pagina
    X_primo(i+1) = (X(i+1)-X(i))/(delta(i)); 
    Y_primo(i+1) = (Y(i+1)-Y(i))/(delta(i)); 
    X_secondo(i+1) = (X_primo(i+1)-X_primo(i))/(delta(i)); 
    Y_secondo(i+1) = (Y_primo(i+1)-Y_primo(i))/(delta(i)); 
end

%% Legge di moto polinomio settimo grado + Evaluate_Trajectory

tsim=3; %tempo di stop simulazione, come quello simulink
h=S(n); %alzata, o meglio spostamento richiesto
np = 1000; %numeri di punti presenti nella traiettoria
passo = tsim/np; %0.0003
time = 0:passo:tsim; % divido la finestra temporale in più finestre temporali
%0,-0.003-0.006
%time=time';
sp=zeros(length(time),3);
for i =1:length(time)
    sp(i,:) = Evaluate_Trajectory(time(i),h);
end
s_ldm = sp (:,1);   %vettore posizione di s
v_ldm = sp (:,2);   %vettore velocita di s
a_ldm = sp (:,3);   %vettore accelerazione di s e
%% Interpolazione lineare , sono ancora geometriche 
x=zeros(length(time),1); 
y=zeros(length(time),1);
x_primo=zeros(length(time),1); 
y_primo=zeros(length(time),1);
x_secondo=zeros(length(time),1); 
y_secondo=zeros(length(time),1);
for i=1:length(time) 
    %interpolazione spostamento
    x(i)=interp1(S,X,s_ldm(i),'Linear'); 
    y(i)=interp1(S,Y,s_ldm(i),'Linear');
    %interpolazione velocità
    x_primo(i)=interp1(S,X_primo,s_ldm(i),'Linear');
    y_primo(i)=interp1(S,Y_primo,s_ldm(i),'Linear');
    %interpolazione accelerazione
    x_secondo(i)=interp1(S,X_secondo,s_ldm(i),'Linear');
    y_secondo(i)=interp1(S,Y_secondo,s_ldm(i),'Linear');
end
%% Velocità e Accelerazioni lungo gli assi x,y
%utilizzo velocità e accelerazioni geometriche 
%i quali hanno già subito interpolazione
x_p = zeros(length(time),1);
x_pp = zeros(length(time),1);
y_p = zeros(length(time),1);
y_pp = zeros(length(time),1);
for i=1:length(time)
    x_p(i) = x_primo(i)*v_ldm(i);
    x_pp(i) = x_secondo(i)*v_ldm(i)^2+x_primo(i)+a_ldm(i);
    y_p(i) = y_primo(i)*v_ldm(i);
    y_pp(i) = y_secondo(i)*v_ldm(i)^2+y_primo(i)+a_ldm(i); 
end

%% Plot andamento
%figure 3
figure('Name','Legge di moto polinomiale')
% figure('Name','Legge di ad accelerazione costante simmetrica')
plot(time,sp(:,1),'*')
hold on
plot(time,sp(:,2),'g')
hold on
plot(time,sp(:,3),'r')
grid on
legend('posizione[rad]',' Velocità [rad/s]', ' Accelerazione [rad/s^2]')
legend('Location' , 'NorthWest')
%figure 4
figure('Name','Verifica interpolazione')
plot(x,y) % verifica dei valori interpolati
%figure 5
figure('Name','Posizione asse x')
plot(time,x,'r')
hold on
%figure 6
figure('Name','Velocità asse x')
plot(time,x_p,'b')
hold on
%figure 7
figure('Name','Accelerazione asse x')
plot(time,x_pp,'g')
hold on
%figure 8
figure('Name','Posizione asse y')
plot(time,y,'r')
hold on
%figure 9
figure('Name','Velocità asse y')
plot(time,y_p,'b')
hold on
%figure 10
figure('Name','Accelerazione asse y')
plot(time,y_pp,'g')
hold on
% %% Limiti di velocità e di accelerazione
% %velocità nominale motore su asse x: 6000 min^-1 (giri al minuto ???)
% %velocità nominale motore su asse y: 11,000 rpm 
% %esprimo come primo approccio le velocità in rpm...
% v_max_x = 6000;
% w_max_x = v_max_x*pi/30;
% v_max_y = 11000;
% w_max_y = v_max_y*pi/30;
% %Kvx,Kvy :  coefficienti di scala, interpretati come fattori di limitazione
% %           della velocità massima dei motori
% Kvx = 0.6;
% Kvy = 0.6;
% m_tx = parx.m + ((2*parx.Jp3 + parx.Jp2)/parx.r3^2) + ((parx.Jp1+parx.Jm)/parx.tau^2);
% m_ty = pary.Mx + ((4*pary.Jp3 + pary.Jp2)/pary.r3^2) + ((pary.Jp1 + pary.Jm)/pary.tau);
% s = zeros(passo,1);
% s(1) = 0;
% s_p = zeros(passo,1);
% s_p(1) = 0;
% s_pp = zeros(passo,1);
% s_pp(1) = 0;

% % Riassunto dati: le cose che valgono per X valgono anche per Y
% % X, X_primo, X_secondo -> Posizione, Velocità, Accelerazione GEOMETRICA
% % x, x_primo, x_secondo -> vettori pos,vel,acc geometriche dopo interpolaz.
% % s_dlm,v_ldm,a_ldm posizione,velocità,accelerazione di s (legge di moto)
% % x,x_p, x_pp posizione,velocità accelerazione lungo gli assi rispetto a t
% 
% %   limite di velocità asse x
% s_p_limite_x1 = parx.tau*Kvx*w_max_x/abs(x_primo);
% s_p_limite_x2 = sqrt(parx.Cm/(m_tx*parx.tau*abs(x_secondo)));
% %   limite di velocità asse y
% s_p_limite_y1 = parx.tau*Kvy*w_max_y/abs(y_primo);
% s_p_limite_y2 = sqrt(pary.Cm/(m_tx*pary.tau*abs(y_secondo)));
% %   Il valore limite  della velocità di percorrenza sarà il minimo
% %   dei quattro limiti... lo devo fare istante per istante
% 
% %   limiti su accelerazione 
% %   ---- per valori >=0 di accelerazione ----
% %   ed s'>=0 :
% s_pp_min = - (x_secondo*s_p^2)/abs(x_primo);
% s_pp_max = ((parx.Cm/(m_tx*parx.tau))- x_secondo*s_pp^2)/abs(x_primo);
% %   ed s'<=0 :
% s_pp_min = -((parx.Cm/(m_tx*parx.tau))- x_secondo*s_pp^2)/abs(x_primo);
% s_pp_max = (x_secondo*s_p^2)/abs(x_primo);  
% %   ---- per valori <=0 di accelerazione ----
% %   ed s'>=0 :
% s_pp_min = -((parx.Cm/(m_tx*parx.tau))+ x_secondo*s_pp^2)/abs(x_primo);
% s_pp_max = -(x_secondo*s_p^2)/abs(x_primo);  
% %   ed s'<=0 :
% s_pp_min = (x_secondo*s_p^2)/abs(x_primo);  
% s_pp_max = ((parx.Cm/(m_tx*parx.tau))+ x_secondo*s_pp^2)/abs(x_primo);
% %anche questi devo farli istante per istante..
% 
% %   ----altri limiti accelerazione----
% %   s_p<= 0.7*s_p_limite ---> max acc.
% %   0.7*s_p_limite <= s_p <= 0.8*s_p_lmite
% %   s_p >= 0.8*s_p_limite











