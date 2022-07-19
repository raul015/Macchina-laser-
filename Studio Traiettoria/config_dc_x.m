function [mx] = config_dc_x(parx)

% parametri
% idx: identificativo motore di cui ottenere i dati
% Jr: mom. inerzia del carico ridotto all'asse del motore
% uscita
% m: dato strutturato con i dati di riferimento del motore

%con l'aggiunta di inerzia avrei il sistema più ritardato
%dovuto anche al cambiamento della tau elettrica...
  
        mx.Ra = 1.6; %hom
        mx.La = 1.72e-3;% H
        mx.K = 0.445; % V/1000 min^-1
%         m.K = (30.5/1000)*60/(2*pi);  %Vs/rad
        mx.Jm = parx.Jm; %del motore
        mx.name='Parker NX110E'; %nome ---
        mx.Imax = 0.99; %massimo livello di corrente 
        %calcolo fattore di conversione tensione corrente
        mx.P = 0.21*10^-3;
        corrente_max =  5; % [A] dell'azionamento
        tensione_max = 10; %[V]dell'azionamento
        mx.Kr = corrente_max/tensione_max;
     
        
    mx.Jr=(parx.Jp1)+(parx.Jp2+4*parx.Jp3+parx.m*parx.r3^2)*(parx.r1/parx.r2)^2 ; %momento ridotto del carico all'asse del motore
    mx.Jma = mx.Jm + mx.Jr; % mom.inerzia totale all'asse del motore 

    %costante elettrica 
    mx.te = mx.La/mx.Ra;
    %costante elettromeccanica
    mx.tem = mx.Jma*mx.Ra/mx.K^2;
    
    % fdt omega/Va
    % coefficienti del polinomio in S al num e al den della fdt Laplace
    num = [1/mx.K];
    den = [mx.te*mx.tem, mx.tem, 1];
    
    tf_V_W = tf(num,den); %creo la funz. trasferimento
    %imposto nella ftd informazioni di utilita'
    set(tf_V_W,'Name',['motore ' mx.name],'InputName','Va','OutputName','Omega');
    
    %funzione di trasferimento fra tensione Va e I
    num=[mx.tem, 0];
    den=mx.Ra*[mx.te*mx.tem, mx.tem, 1];
    tf_V_I = tf(num,den); %creo la funz. trasferimento V= ingresso , I =uscita
    %imposto nella ftd informazioni di utilita'
    set(tf_V_I,'Name',['motore H_I' mx.name],'InputName','Va','OutputName','I');
    
    
    %salvo nel dato motore
    mx.tf_V_W = tf_V_W;
    mx.tf_V_I = tf_V_I;
    
    
    
end

