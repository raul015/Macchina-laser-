function [my] = config_dc_y(pary)
% Jr: mom. inerzia del carico ridotto all'asse del motore
% uscita
% m: dato strutturato con i dati di riferimento del motore
Jm = pary.Jm;
Jp1 = pary.Jp1;
Jp2 = pary.Jp2;
Jp3 = pary.Jp3;
% J5 = pary.J5;
Mx = pary.Mx;
r1 = pary.r1;
r2 = pary.r2; 
r3 = pary.r3;
% Jr=(Jm+Jp1)+(2*J5+Jp2+4*Jp3+Mx*r3^2)*(r1/r2)^2       ; % da calcolare
Jr=(Jm+Jp1)+(Jp2+4*Jp3+Mx*r3^2)*(r1/r2)^2       ; % da calcolare

my.Ra = 6.4 ; %hom
my.La = 6.4*10^(-3);
my.K = 0.4;
% m.Jm = 1.7e-4; %del motore
my.Jm = Jm;
my.name='Mavilor BLS-073 A.00.0105.00'; %nome ---
my.Imax = 3.91; %massimo livello di corrente
        
my.I=11;
my.V=10;
my.Kr=my.I/my.V;

my.Jr = Jr; %momento ridotto del carico all'asse del motore
my.Jma = my.Jm + my.Jr; % mom.inerzia totale all'asse del motore 

    
%costante elettrica 
my.te = my.La/my.Ra;
%costante elettromeccanica
my.tem = my.Jma*my.Ra/my.K^2;
    
% fdt omega/Va
   % coefficienti del polinomio in S al num e al den della fdt Laplace
    num=[1/my.K];
    den=[my.te*my.tem, my.tem, 1];
    
    tf_V_W = tf(num,den); %creo la funz. trasferimento
    %imposto nella ftd informazioni di utilita'
    set(tf_V_W,'Name',['motore ' my.name],'InputName','Va','OutputName','Omega');
    
    %funzione di trasferimento fra tensione Va e I
    num=[my.tem, 0];
    den=my.Ra*[my.te*my.tem, my.tem, 1];
    tf_V_I = tf(num,den); %creo la funz. trasferimento tensione corrente
    %imposto nella ftd informazioni di utilita'
    set(tf_V_I,'Name',['motore H_I' my.name],'InputName','Va','OutputName','I');
    
    
    %salvo nel dato motore
    my.tf_V_W = tf_V_W;
    my.tf_V_I = tf_V_I;
    
    
    
end

