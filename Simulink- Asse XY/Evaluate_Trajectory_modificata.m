function Y = Evaluate_Trajectory_modificata (t , h)
% parametri:
% t: tempo assoluto
% h: spostamento richiesto
% Y: vettore contenente posizione Y(1), vel Y(2), acc Y(3)


%%annotazione mie:
%questa funzione mi permette di determinale il profilo di
%moto in funzione del tempo


%%
h0=0;
% DT=[.2 ,.2 ,.2 , 0]; %definisce durata dei movimenti elementari
DT=[1 , 0 , 1 , 0]; %definisce durata dei movimenti elementari
% name = 'Constant_Acceleration_ADIM_par';
par = [1/3, 2/3];
%definisco 4 zone di movimento/intervalli
DT1 = DT(1); % durata 1s
DT2 = DT(2); % durata 0s
DT3 = DT(3); % durata 0s
DT4 = DT(4); % durata 1s
%in funzione del tempo t calcolo i 2 intervalli in questo caso

%definisco gli istanti in cui iniziano i vari intervalli
T0 = 0;
T1 = T0 + DT1; 
T2 = T1 + DT2;
T3 = T2 + DT3;
T  = T3 + DT4;                  % Total time

if t >= T0 && t <= T1            % Interval N°1 
   td = DT1; %tempo di azionamento
   x = (t - T0)/td; %tempo adimensionale dove sviluppo il mio moto
%    [G,F,f] = Constant_Acceleration_ADIM_par(x,par);
%    [G,F,f] = Cubic (x);
     [G,F,f,J] = Polinomiale_7g(x);
   
   y = h0 + G*h;
   yp = F * h/td;
   ypp = f * h/td^2;
end

if t > T1 && t <= T2             % Interval N°2 
   y = h0 + h;
   yp = 0;
   ypp = 0;
end

if t > T2 && t <= T3             % Interval N°3 mi fa tornare indietro
   td = DT3;
   x = (t - T2)/td;
%    [G,F,f] = Constant_Acceleration_ADIM_par(x,par);
%    [G,F,f] = Cubic (x);
   [G,F,f,J] = Polinomiale_7g(x);
   y = (h0 + h) - G*h;
   yp =  - (F * h/td);
   ypp = - (f * h/td^2);
end

if t > T3               % Interval N°4    
   y = h0;
   yp = 0;
   ypp = 0;  
end

Y = [y,yp,ypp]; %pos, vel, acc

