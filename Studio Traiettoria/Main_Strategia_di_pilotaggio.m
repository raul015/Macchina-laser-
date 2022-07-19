clc
clear 
close all
% i limiti che calcolo fanno riferimento all'istante dopo
% all'istante i faccio le valutazioni in base alla tabella,--> ricavo s'' 
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

%posizionamento poli con retroazione sul motore
ppx_m = pos_poli_cc_x(mx, acx, 1);
ppy_m = pos_poli_cc_y(my, acy, 1);

%posizionamento poli con retroazione sul carrello 
ppx_c = pos_poli_cc_x(mx, acx, 2);
ppy_c = pos_poli_cc_y(my, acy, 2);

%% Script per  lo studio della traiettoria
file='.\zig_mod-Copia.dxf';
% file='.\cerchio1v.dxf';
[trajectory, errore]=dxf_box_3(file,1,1);
%figure 2
axis equal; % mette in scala la figura
figure;
plot(trajectory.x,trajectory.y,'r.');

l=trajectory.l;         % lunghezza traiettoria l = S(npt) 
npt=trajectory.nPti;    % numero punti traiettoria
S=trajectory.s;         % ascissa curvilinea 504X1,percorrenza traiettoria parte da 0
X=trajectory.x;         % Coordinate X,Y che individuano il punto S 
Y=trajectory.y;         % c'è correlazione tra coordinate 
Matr_int = [X,Y,S];     % X(S),Y(S),P(S)
%% Calcolo accelerazione e velocità geometrica X_primo,X_secondo,Y_primo,Y_secondo                          
delta = zeros(npt,1);
%   Vettori geometrici
Vel_geom = zeros(npt,2);
Acc_geom = zeros(npt,2);


for i=1: (npt-1)
    
    delta(i) = S(i+1)-S(i); 
    Vel_geom(i+1,1) = (Matr_int(i+1,1)-Matr_int(i,1))/(delta(i)); 
    Vel_geom(i+1,2) = (Matr_int(i+1,2)-Matr_int(i,2))/(delta(i)); 
    Acc_geom(i+1,1) = (Vel_geom(i+1,1)-Vel_geom(i,1))/(delta(i)); 
    Acc_geom(i+1,2) = (Vel_geom(i+1,2)-Vel_geom(i,2))/(delta(i));
    
end

%% Strategia di pilotaggio
% Vettori Geometrici da interpolare
x = []; 
y = [];
% Velocità e Accelerazioni lungo gli assi x,y
Vel_asse_x = [];
Acc_asse_x = [];
Vel_asse_y = [];
Acc_asse_y = [];
% Definizione parametri (PDF)
v_max_x = 6000;
w_max_x = v_max_x*pi/30;
v_max_y = 11000;
w_max_y = v_max_y*pi/30;
Kvx = 0.8;
Kvy = 0.8;
m_tx = parx.m + ((2*parx.Jp3 + parx.Jp2)/parx.r3^2) + ((parx.Jp1+parx.Jm)/parx.tau^2);
m_ty = pary.Mx + ((4*pary.Jp3 + pary.Jp2)/pary.r3^2) + ((pary.Jp1 + pary.Jm)/pary.tau);
np = 1000; %numeri di punti presenti nella traiettoria
dT = 1/np;
time(1)=0;
% condizione iniziale posizione, velocità di percorrenza , accelerazione
% di percorrenza
s(1) = 0;
s_p(1) = 0;
s_pp(1) = 1; 
%   Indice iterazione --> dimensione dei vettori in output
i = 1;
%   Mi aspetto di avere una ccelerazione di Output repentina
d_mancante(1) = 0;
d_min_arresto(1) = 0;
appoggio = 0;
s_finale = 0;
delta_d(1)=0;

  x_appoggio = 0;
  y_appoggio = 0;
  Vel_geom_interp_appoggio1 = 0;
  Vel_geom_interp_appoggio2 = 0;
  Acc_geom_interp_appoggio1 = 0;
  Acc_geom_interp_appoggio2 = 0;
while( s(i) < l)
    
    i
%   interpolazione POSIZIONE  
    
    x(i)= interp1(Matr_int(:,3),Matr_int(:,1),s(i),'Linear',x_appoggio); 
    y(i)= interp1(Matr_int(:,3),Matr_int(:,2),s(i),'Linear',y_appoggio);
    x_appoggio = x(i);
    y_appoggio = y(i);
%     x= fillmissing(x,'previous');
%     y= fillmissing(y,'previous');
    
%   interpolazione VELOCITA' E ACCELERAZIONE GEOMETRICA
    Vel_geom_interp(i,1)=interp1(Matr_int(:,3),Vel_geom(:,1),s(i),'Linear', Vel_geom_interp_appoggio1);
%     Vel_geom_interp_appoggio1 =  Vel_geom_interp(i,1);
    Vel_geom_interp(i,2)=interp1(Matr_int(:,3),Vel_geom(:,2),s(i),'Linear',Vel_geom_interp_appoggio2);
%     Vel_geom_interp_appoggio2 =  Vel_geom_interp(i,2);
    Acc_geom_interp(i,1)=interp1(Matr_int(:,3),Acc_geom(:,1),s(i),'Linear', Acc_geom_interp_appoggio1);
%     Acc_geom_interp_appoggio1 = Acc_geom_interp(i,1);
    Acc_geom_interp(i,2)=interp1(Matr_int(:,3),Acc_geom(:,2),s(i),'Linear',Acc_geom_interp_appoggio2);
%     Acc_geom_interp_appoggio2 = Acc_geom_interp(i,2);
%     
%      Vel_geom_interp =   fillmissing(Vel_geom_interp,'previous');
%      Acc_geom_interp =   fillmissing(Acc_geom_interp,'previous');
    
%   VELOCITA'E ACCELERAZIONE lungo gli ASSI nel TEMPO 
    Vel_asse_x(i) = Vel_geom_interp(i,1)*s_p(i);
    Vel_asse_y(i) = Vel_geom_interp(i,2)*s_p(i);
    Acc_asse_x(i) = Acc_geom_interp(i,1)*(s_p(i)^2) + Vel_geom_interp(i,1)* s_pp(i);
    Acc_asse_y(i) = Acc_geom_interp(i,2)*(s_p(i)^2) + Vel_geom_interp(i,2)* s_pp(i);    

%% LIMITI DI VELOCITA:

if(Acc_geom_interp(i,1)==0 && Acc_geom_interp(i,2)~=0)  
    
    if(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)~=0)
        %non devo considerare i limiti dell'asse x
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = NaN;
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = sqrt(pary.Cm/(m_ty*pary.tau*norm(Acc_geom_interp(i,2))));
        s_p_limite_y(i)  = min(s_p_limite_y1(i) , s_p_limite_y2(i));
        s_p_limite(i)    = s_p_limite_y(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)==0)
        %considero soltanto la prima condizione di velocita
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = s_p_limite_x1(i);
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN;
        s_p_limite_y(i)  = NaN;
        s_p_limite(i)    = s_p_limite_x(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)~=0)
        %non devo considerare il secondo limite di velocita 
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = s_p_limite_x1(i);
        s_p_limite_y1(i) = pary.tau*Kvy*w_max_y/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = sqrt(pary.Cm/(m_ty*pary.tau*norm(Acc_geom_interp(i,2))));
        s_p_limite_y(i)  = min(s_p_limite_y1(i) , s_p_limite_y2(i));
        s_p_limite(i)    = min(s_p_limite_x(i) , s_p_limite_y(i));
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)==0)
        %non considero entrambi gli assi
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = 0;
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN;
        s_p_limite_y(i)  = 0;
        s_p_limite(i)    = 0;
        
    end
    
elseif(Acc_geom_interp(i,1)~=0 && Acc_geom_interp(i,2)==0)
    
    if(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)==0)
        %non devo considerare i limiti dell'asse y
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1)); 
        s_p_limite_x2(i) = sqrt(parx.Cm/(m_tx*parx.tau*norm(Acc_geom_interp(i,1))));
        s_p_limite_x(i)  = min(s_p_limite_x1(i) , s_p_limite_x2(i));
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN; % acc = 0;
        s_p_limite_y(i)  = NaN;
        s_p_limite(i)    = s_p_limite_x(i);
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)~=0)   
        %Considero solo l'asse y ma soltanto il primo limite
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN;
        s_p_limite_x(i)  = NaN;
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = NaN; %acc = 0;
        s_p_limite_y(i)  = s_p_limite_y1(i);
        s_p_limite(i)    = s_p_limite_y(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)~=0)   
        %non devo considerare il secondo limite di velocita 
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1)); 
        s_p_limite_x2(i) = sqrt(parx.Cm/(m_tx*parx.tau*norm(Acc_geom_interp(i,1))));
        s_p_limite_x(i)  = min(s_p_limite_x1(i) , s_p_limite_x2(i));
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = NaN; %acc = 0;
        s_p_limite_y(i)  = s_p_limite_y1(i);
        s_p_limite(i)    = min(s_p_limite_x(i) , s_p_limite_y(i));
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)==0)
        
        %non considero entrambi gli assi
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN;
        s_p_limite_x(i)  = 0;
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN; %acc = 0;
        s_p_limite_y(i)  = 0;
        s_p_limite(i)    = 0;
        

        
    end
    
elseif(Acc_geom_interp(i,1)==0 && Acc_geom_interp(i,2)==0)
    
    if(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)==0)
        
        %Considero l'asse x solo una condizione
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = s_p_limite_x1(i);
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN; %acc = 0
        s_p_limite_y(i)  = NaN;
        s_p_limite(i)    = s_p_limite_x(i);
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)~=0)
        
        %Considero l'asse y nella prima condizione
        s_p_limite_x1(i) = NaN;
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = NaN;
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = NaN; %acc = 0
        s_p_limite_y(i)  = s_p_limite_y1(i);
        s_p_limite(i)    = s_p_limite_y(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)~=0)
        
        %Considero l'asse x,y ma solo la prima condizione 
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = s_p_limite_x1(i);
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = NaN; %acc = 0
        s_p_limite_y(i)  = s_p_limite_y1(i);
        s_p_limite(i)    = min(s_p_limite_x(i) , s_p_limite_y(i));
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)==0)
        
        %Non considero nulla 
        s_p_limite_x1(i) = NaN;
        s_p_limite_x2(i) = NaN; %acc = 0
        s_p_limite_x(i)  = 0;
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN; %acc = 0
        s_p_limite_y(i)  = 0;
        s_p_limite(i)    = 0;
        

        
    end
    
elseif(Acc_geom_interp(i,1)~=0 && Acc_geom_interp(i,2)~=0)
    
    if(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)~=0)
        %non devo considerare i limiti dell'asse x
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN;
        s_p_limite_x(i)  = NaN;
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = sqrt(pary.Cm/(m_ty*pary.tau*norm(Acc_geom_interp(i,2))));
        s_p_limite_y(i)  = min(s_p_limite_y1(i) , s_p_limite_y2(i));
        s_p_limite(i)    = s_p_limite_y(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)==0)
        %considero soltanto la prima condizione di velocita
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = sqrt(parx.Cm/(m_tx*parx.tau*norm(Acc_geom_interp(i,1))));
        s_p_limite_x(i)  = min(s_p_limite_x1(i) , s_p_limite_x2(i));
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN;
        s_p_limite_y(i)  = NaN;
        s_p_limite(i)    = s_p_limite_x(i);
        
    elseif(Vel_geom_interp(i,1)~=0 && Vel_geom_interp(i,2)~=0)
        %non devo considerare il secondo limite di velocita 
        s_p_limite_x1(i) = (parx.tau*Kvx*w_max_x)/norm(Vel_geom_interp(i,1));
        s_p_limite_x2(i) = sqrt(parx.Cm/(m_tx*parx.tau*norm(Acc_geom_interp(i,1))));
        s_p_limite_x(i)  = min(s_p_limite_x1(i) , s_p_limite_x2(i));
        s_p_limite_y1(i) = (pary.tau*Kvy*w_max_y)/norm(Vel_geom_interp(i,2));
        s_p_limite_y2(i) = sqrt(pary.Cm/(m_ty*pary.tau*norm(Acc_geom_interp(i,2))));
        s_p_limite_y(i)  = min(s_p_limite_y1(i) , s_p_limite_y2(i));
        s_p_limite(i)    = min(s_p_limite_x(i) , s_p_limite_y(i));
        
    elseif(Vel_geom_interp(i,1)==0 && Vel_geom_interp(i,2)==0)
        %non considero entrambi gli assi
        s_p_limite_x1(i) = NaN; 
        s_p_limite_x2(i) = NaN;
        s_p_limite_x(i)  = 0;
        s_p_limite_y1(i) = NaN;
        s_p_limite_y2(i) = NaN;
        s_p_limite_y(i)  = 0;
        s_p_limite(i)    = 0;
        

    end
    
end

%% Limiti di accelerazione

caso_x(i)=0;

if(Vel_geom_interp(i,1)>=0 && Acc_asse_x(i) >= 0)
    caso_x(i)=1;
elseif(Vel_geom_interp(i,1)>=0 && Acc_asse_x(i)<0)
    caso_x(i)=2;
elseif(Vel_geom_interp(i,1)<0 && Acc_asse_x(i)>=0)
    caso_x(i)=3;
elseif(Vel_geom_interp(i,1)<0 && Acc_asse_x(i)<0)
    caso_x(i)=4;
end


switch caso_x(i)
    
    case 1  %Vel_geom_interp(i,1)>=0 && Acc_asse_x(i) >= 
        
            if(Vel_geom_interp(i,1)~=0)
                
                lim_acc_inf_x(i+1) = - (Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));
                lim_acc_sup_x(i+1) = ((parx.Cm/(m_tx*parx.tau))- Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));
                
            else
                lim_acc_inf_x(i+1) = 0.1;
                lim_acc_sup_x(i+1) = 0.1;
            end
                
    case 2  %Vel_geom_interp(i,1)>=0 && Acc_asse_x(i)<0
        
            if(Vel_geom_interp(i,1)~=0)
                lim_acc_inf_x(i+1) = -((parx.Cm/(m_tx*parx.tau))+ Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));
                lim_acc_sup_x(i+1) = -(Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1)); 
            else
                lim_acc_inf_x(i+1) = 0.1 ;
                lim_acc_sup_x(i+1) = 0.1 ; 
            end
            
    case 3  %Vel_geom_interp(i,1)<0 && Acc_asse_x(i)>=0
        
            lim_acc_inf_x(i+1) = -((parx.Cm/(m_tx*parx.tau))- Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));
            lim_acc_sup_x(i+1) = (Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));
            
    case 4  %Vel_geom_interp(i,1)<0 && Acc_asse_x(i)<0
        
            lim_acc_inf_x(i+1) = (Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));  
            lim_acc_sup_x(i+1) = ((parx.Cm/(m_tx*parx.tau))+ Acc_geom_interp(i,1)*(s_p(i)^2))/norm(Vel_geom_interp(i,1));

    otherwise
            warning('non rientra in nessun caso (x)')
            lim_acc_inf_x(i+1) = 0;
            lim_acc_sup_x(i+1) = 0;
end

% Asse y, Limiti di acelerazione per i quattro casi -> acc e dec 

caso_y(i)=0;

if(Vel_geom_interp(i,2)>=0 && Acc_asse_y(i) >= 0)
    caso_y(i)=1;
elseif(Vel_geom_interp(i,2)>=0 && Acc_asse_y(i)<0)
    caso_y(i)=2;
elseif(Vel_geom_interp(i,2)<0 && Acc_asse_y(i)>=0)
    caso_y(i)=3;
elseif(Vel_geom_interp(i,2)<0 && Acc_asse_y(i)<0)
    caso_y(i)=4;
end

switch caso_y(i)
    case 1  %Vel_geom_interp(i,2)>=0 && Acc_asse_y(i) >= 0
            if(Vel_geom_interp(i,2)~=0)
                lim_acc_inf_y(i+1) = -(Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
                lim_acc_sup_y(i+1) = ((pary.Cm/(m_ty*pary.tau))- Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
            else      
                lim_acc_inf_y(i+1) = 0.1;
                lim_acc_sup_y(i+1) = 0.1;
            end
    case 2  %Vel_geom_interp(i,2)>0 && Acc_asse_y(i)<0  
            if(Vel_geom_interp(i,2)~=0)
                lim_acc_inf_y(i+1) = -((pary.Cm/(m_ty*pary.tau))+ Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
                lim_acc_sup_y(i+1) = -(Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
            else
                lim_acc_inf_y(i+1) = 0.1;
                lim_acc_sup_y(i+1) = 0.1;
            end
    case 3  %Vel_geom_interp(i,2)<0 && Acc_asse_y(i)>=0
            lim_acc_inf_y(i+1) = -((pary.Cm/(m_ty*pary.tau))- Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
            lim_acc_sup_y(i+1) = (Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
    case 4  %Vel_geom_interp(i,1)<0 && Acc_asse_x(i)<0
            lim_acc_inf_y(i+1) = (Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));  
            lim_acc_sup_y(i+1) = ((pary.Cm/(m_ty*pary.tau))+ Acc_geom_interp(i,2)*(s_p(i)^2))/norm(Vel_geom_interp(i,2));
    otherwise
            warning('non rientra in nessun caso (y)')
            lim_acc_inf_y(i+1) = 0;
            lim_acc_sup_y(i+1) = 0;
end

%% Calcolo della posizione, velocità di percorrenza (i+1)
s(i+1) = s(i) + s_p(i)*dT;          
s_p(i+1) = s_p(i) + s_pp(i)*dT; 
%% Calcolo delle distanze
d_mancante(i+1) = l-s(i+1);
s_pp_max(i+1)=  -s_p(i+1)/dT;
d_min_arresto(i+1)= 0.5*(s_p(i)^2)/(abs(s_pp_max(i+1)));
delta_d(i+1) = d_mancante(i+1) - d_min_arresto(i+1);

%% Calcolo della accelerazione di percorrenza (i+1) 

if(s(i)<0.5*l)
    
    if(s_p(i) <= s_p_limite(i)*0.7) % massima accelerazione possibile
            
        s_pp(i+1)= min(abs(lim_acc_sup_x(i+1)) , abs(lim_acc_sup_y(i+1)));
        warning('caso1')
    elseif(s_p(i) >= s_p_limite(i)*0.8)
        %     s_pp(i+1)= max(lim_acc_inf_x(i+1) , lim_acc_inf_y(i+1))
        s_pp(i+1)= -min(abs(lim_acc_inf_x(i+1)) , abs(lim_acc_inf_y(i+1)));    
        warning('caso2')
    else
        s_pp(i+1)= 0;      
        warning('caso3')
    end
elseif(s(i)>=0.5*l && delta_d(i+1)>0.05 && appoggio ==0) 
    if(s_p(i) <= s_p_limite(i)*0.7)
        s_pp(i+1)= min(abs(lim_acc_sup_x(i+1)) , abs(lim_acc_sup_y(i+1)));
        warning('caso1')
    elseif(s_p(i) >= s_p_limite(i)*0.8)
        %     s_pp(i+1)= max(lim_acc_inf_x(i+1) , lim_acc_inf_y(i+1))
        s_pp(i+1)= -min(abs(lim_acc_inf_x(i+1)) , abs(lim_acc_inf_y(i+1)));    
        warning('caso2')
    else
        s_pp(i+1)= 0;      
        warning('caso3')
    end  
else
    if(appoggio ==0)
    %s_pp(i+1) = s_pp_max(i+1);
    s_pp(i+1)= -min(abs(lim_acc_inf_x(i+1)) , abs(lim_acc_inf_y(i+1)));
    s_finale = s_pp(i+1);
    appoggio = 1;
    else
    s_pp(i+1) = s_finale;
    end
end
time(i+1)=time(i)+ dT;
i = i+1;

end

tsim=4;



%% plot

t = 1:i-1;
figure('Name','posizione asse x')
plot(t,x) 
figure('Name','velocità asse x')
plot(t,Vel_asse_x)
figure('Name','accelerazione asse x')
plot(t,Acc_asse_x) 
figure('Name','posizione asse y')
plot(t,y) 
figure('Name','velocità asse y')
plot(t,Vel_asse_y)
figure('Name','accelerazione asse y')
plot(t,Acc_asse_y) 
figure('Name','Asse XY')
plot(x,y) % 
t=1:i;
figure('Name','ascissa plot')
plot(t,s,'r')
hold on
plot(t,s_p,'g')
hold on
plot(t,s_pp,'k')
legend('posizione','velocità','accelerazione')

x(i) = x(i-1);
Vel_asse_x(i)= Vel_asse_x(i-1);
Acc_asse_x(i)= Acc_asse_x(i-1);
y(i) = y(i-1);
Vel_asse_y(i)= Vel_asse_y(i-1);
Acc_asse_y(i)= Acc_asse_y(i-1);
%% parametri per le varie traiettorie

%rapporti per far tornare i calcoli per la riconferenza
i_x1 = parx.d2/(parx.d1*parx.d3);
i_x2 = 1 / parx.d3; 
i_x3 = 1 / parx.d3;

i_y1 = pary.d2/(pary.d1*pary.d3);
i_y2 = 1 / pary.d3; 
i_y3 = 1 / pary.d3;

ci_x(1) = x(1)*i_x1;
ci_x(2) = x(1)*i_x2;
ci_x(3) = x(1)*i_x3;
ci_x(4) = x(1);

ci_y(1) = y(1)*i_y1;
ci_y(2) = y(1)*i_y2;
ci_y(3) = y(1)*i_y3;
ci_y(4) = y(1);

% per il cerchio

% ci_x(1) = 0;
% ci_x(2) = 0;
% ci_x(3) = 0;
% ci_x(4) = 0;

% parametri per lo zig
% ci_x(1) = 0;
% ci_x(2) = 0;
% ci_x(3) = 0;
% ci_x(4) = -0.0005;

%parametri per lo zig_mod
% ci_x(1) = 0;
% ci_x(2) = 0;
% ci_x(3) = 0;
% ci_x(4) = 0;

%parametri per tutti i file dxf
% ci_y(1) =0;
% ci_y(2) =0;
% ci_y(3) =0;
% ci_y(4) =0;
%% parametri di aggiustamento dei guadagni
%guadagni file Strategia_pilotaggio_XY_discretizzato zig/zig_mod
Gx_agg_rc = 0.19;
Gx_agg_rm = 0.5;
Gy_agg_rc = 0.09;
Gy_agg_rm = 1;
%guadagni file pospoli_XY_traiettoria_discretizzato zig/zig_mod
Gppx_agg_rc = 0.4;
Gppx_agg_rm = 1;
Gppy_agg_rc = 0.8;
Gppy_agg_rm = 1;



