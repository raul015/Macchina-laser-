function Y = Evaluate_Trajectory (t , h)
% parametri:
% t: tempo assoluto
% h: spostamento richiesto
% Y: vettore contenente posizione Y(1), vel Y(2), acc Y(3)

h0=0;
% DT=[.2 ,.2 ,.2 , 0]; %definisce durata dei movimenti elementari
DT=[0.5 ,0.5 ,0.5 , 0]; %definisce durata dei movimenti elementari
name = 'Constant_Acceleration_ADIM_par';
cambiopar = [1/3, 2/3];


DT1 = DT(1);
DT2 = DT(2);
DT3 = DT(3);
DT4 = DT(4);

T0 = 0;
T1 = T0 + DT1;
T2 = T1 + DT2;
T3 = T2 + DT3;
T  = T3 + DT4;                  % Total time

if t >= T0 && t <= T1            % Interval N°1 
   td = DT1; %tempo di azionamento
   x = (t - T0)/td; %tempo adimensionale
   [G,F,f] = feval(name,x,cambiopar);
   
   y = h0 + G*h;
   yp = F * h/td;
   ypp = f * h/td^2;
end

if t > T1 && t <= T2             % Interval N°2 
   y = h0 + h;
   yp = 0;
   ypp = 0;
end

if t > T2 && t <= T3             % Interval N°3
   td = DT3;
   x = (t - T2)/td;
   [G,F,f] = feval(name,x,cambiopar);
   %[G,F,f] = Constant_Acceleration_ADIM_par(x,par);

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

