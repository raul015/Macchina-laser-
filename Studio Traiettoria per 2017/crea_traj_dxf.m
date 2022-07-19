 function trajectory=crea_traj_dxf(entita,ds,sifig)
% *******************************************************************************
% function [traj]=crea_traj_dxf(entita,ds)
%
% INPUT
% entita2  -> vettore entità contiene le entità del file dxf ordinate [mm]
%
% entita2  -> vettore entità contiene le entità del file dxf
%             1: tipo di  entità (1-linea(5 campi) 2-arco(10 campi))
%		      2: x iniziale
%			  3: y iniziale
%		      4: x finale
%			  5: y finale
%			  [per gli archi]
%               (utile per circonferenza)
%               altrimenti utilizzato come riferimento
%			  6: x centro  
%			  7: y centro
%             8: raggio
%			  9: angolo iniziale
%			 10: angolo finale   
%
% ds       -> passo di divisione
% sifig    -> disegna la figura se 1
%
% OUTPUT
% trajectory -> .x ascissa [m]
%               .y ordinate [m]
%               .s coordinata curvilinea
%               .nPti numero di punti
%               .l lunghezza 
%
% *******************************************************************************

[row,col]=size(entita);

k_old=1;
conta=0;

k=1; % posizione nel vettore traj 

for w=1:row
    k_old=k;
    % ----- linea -----
    if entita(w,1)==1
        % lunghezza segmento
        lunghezza=sqrt(((entita(w,4)-entita(w,2))^2)+((entita(w,5)-entita(w,3))^2));
        % delta avanzamento scomposto sulle due direzioni
        dx=(entita(w,4)-entita(w,2))*ds/lunghezza;
        dy=(entita(w,5)-entita(w,3))*ds/lunghezza;
        traj(k,:)=[entita(w,2) entita(w,3)]; % primo elemento della linea
        %floor approssima all'intero più vicino, minore o uguale a 
        %quell'elemento
        n=floor(lunghezza/ds); % numero di punti sulla linea
        % riempie vettore
        for s=2:n 
                    %punto prima+ il passo --> Xk-1 + dx = Xk
                    % e la stessa cosa vale per y
               traj(k+s-1,:)=[traj(k+s-2,1)+dx traj(k+s-2,2)+dy]; % elementi successivi della linea 
        end
        k=k+n;
        conta=conta+1;
    end 
    % ----- fine linea -----
    
    % ----- arco orario e antiorario -----
    if entita(w,1)==2 | entita(w,1)==-2
        % arco orario(-) o antiorario(+)
        segno=entita(w,1)/2;
        if segno>0 & entita(w,10)<entita(w,9)
            entita(w,9)=entita(w,9)-360;
        end
        if segno<0 & entita(w,10)>entita(w,9)
            entita(w,10)=entita(w,10)-360;
        end
        % lunghezza arco
        lunghezza=entita(w,8)*grad2rad(entita(w,10)-entita(w,9));
        % delta angolo
        da=(ds/entita(w,8));
        alfa= grad2rad(entita(w,9)); % angolo iniziale
        traj(k,:)=[entita(w,2) entita(w,3)]; % primo elemento della linea
        n=abs(floor(lunghezza/ds));
        % riempie vettore
        for s=2:n 
               % elementi successivi della linea 
               alfa=alfa+da*(segno);
               % x
               traj(k+s-1,1)=entita(w,6)+entita(w,8)*cos(alfa);
               % y
               traj(k+s-1,2)=entita(w,7)+entita(w,8)*sin(alfa);
        end
        k=k+n;
        conta=conta+1;
    end
    
    % --- disegno ---
    conta;
    k_old;
    k;
    if sifig
        hold on;
        if rem(conta,2)
          plot(traj(k_old:k-1,1),traj(k_old:k-1,2),'*');axis equal;
        else
          plot(traj(k_old:k-1,1),traj(k_old:k-1,2),'.');axis equal;
        end
    end
    % --- disegno ---
end

% salva nella struttura
trajectory.x=traj(:,1)/1000;
trajectory.y=traj(:,2)/1000; 
trajectory.nPti=length(traj);
trajectory.x(trajectory.nPti+1)=trajectory.x(1);
trajectory.y(trajectory.nPti+1)=trajectory.y(1);
trajectory.nPti=trajectory.nPti+1;


% ascissa curvilinea
trajectory.s(1)=0;
for j=2:trajectory.nPti
    trajectory.s(j)=trajectory.s(j-1)+sqrt((trajectory.x(j)-trajectory.x(j-1))^2+(trajectory.y(j)-trajectory.y(j-1))^2);
end

trajectory.s=trajectory.s';
trajectory.l=trajectory.s(j);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function  out  = rad2grad( inp )
% *******************************************************************************
%
% function  out  = rad2grad( inp ):
%        conversione da radianti a  gradi
%
% *******************************************************************************
out = inp*180.0/pi;

function  out  = grad2rad( inp )
% *******************************************************************************
%
% function  out  = grad2rad( inp ):
%        conversione da gradi a  radianti
%
% *******************************************************************************
out = inp*pi/180.0;
