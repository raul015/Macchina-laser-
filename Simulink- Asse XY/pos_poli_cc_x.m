function [pp] = pos_poli_cc_x(m, ac ,scelta)
%in ingresso
% m, motore
% ac, parametri anello in corrente
% in uscita informazioni sul contrllore pp

%modulo dei poli complessi coniugati
% w0 = 2*pi*ac.fc/10; %628.3185 % w0 = 2*pi*100

% % 
% % %%%pos poli motore
% % w0 = 2500
% % csi =0.8 %indice di smorzamento

%%%pos poli carrello
 
 %per carrello scelta=1
 
 switch(scelta)
     case 1 %per motore 
        w0=600;
        csi=0.95;
        
        
           
     case 2 %per carrello 
        w0=150;
        csi=0.95;
        
   
% prova 0.7 a 0.6 >>>> ripple aumentati, in numero e ampiezza iniziale
% 0.95,  ripple buono, ampiezza bassa, proviamo aumentare w0
%w0 a 1000 va in risonanza, a 1500 risonanza 300 pendenza troppo bassa,
%curva lontana dal riferimento, ma in scala
% 700 e 0,8 ripple numerosi, pendenza quasi ok

 end


%noto w0 e csi -->> calcolo dei poli
if( csi > 0 && csi < 1 )
    poli(1) = w0*(-csi + 1i*sqrt(1-csi^2));
    poli(2) = w0*(-csi - 1i*sqrt(1-csi^2));
else %csi > 1
    poli(1) = w0*(-csi + sqrt(-1+csi^2));
    poli(2) = w0*(-csi - sqrt(-1+csi^2));
end

%solamente per il calcolo del regolatore considero J diversa da quella del sistema
Jmctrl = 1.3*m.Jma; 

%calcolo delle costanti
g1 = w0^2 * Jmctrl/m.K;
g2 = 2*csi*w0*Jmctrl/m.K;
%matrice dei guadagni
G = [g1, g2];

pp.g1 = g1;
pp.g2 = g2;
pp.w0 = w0;
pp.csi = csi;
pp.poli = poli;

% valuto qui comportamento del sistema and anello chiuso
% utilizzo un approccia basato sulsistema lineare descrivibile in S
% costruisco matrici eq. in forma di stato
% anello aperto
A = [ 0, 1;
     0, 0];
B = [0 ;
     m.K/Jmctrl];
 
% costruisco la matrice Astar
Astar = -B*G;
%matrice del sistema ad anello chiuso
Ac = A + Astar;

pp.G = G;
pp.A = A;
pp.B = B;
pp.Ac = Ac;
pp.Astar = Astar;

%costrisco modello dinamico del sistema ad anello chiuso
sys_close = ss(Ac, ... %matrice A del sistema ad anello chiuso
    zeros(2,1), ... %matrice B 
    eye(2), ... %matrice C
    zeros(2,1) ); %matrice D


% % diagrammo posizione dei poli
% figure
% pzmap( sys_close ); %posizione dei poli nel piano complesso
% grid on
% axis equal


% % risposta alla perturbazione dello stato
% % impongo condizioni iniziali diverse da 0
% Y0 = [1; 0]; % 1 radiante sulla coordinata theta, 0 su dot theta
% figure
% initial(sys_close, Y0);
% grid on

% stesso conto con place
G_place = place( A, ... %matrice A del sistema ad anello aperto
                B, ... % matrice B del sistema ad anello aperto
                poli); % vettore dei poli desisderati
            
pp.G_place = G_place;
pp.Ac_place = A - B*G_place;
pp.Astar_place = -B*G_place;


end

