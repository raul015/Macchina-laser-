function [m] = config_dc(par)

% parametri
% idx: identificativo motore di cui ottenere i dati
% Jr: mom. inerzia del carico ridotto all'asse del motore
% uscita
% m: dato strutturato con i dati di riferimento del motore

%con l'aggiunta di inerzia avrei il sistema più ritardato
%dovuto anche al cambiamento della tau elettrica...
  
        m.Ra = 1.6; %hom
        m.La = 1.72e-3;% H
        m.K = 0.445; % V/1000 min^-1
%         m.K = (30.5/1000)*60/(2*pi);  %Vs/rad
        m.Jm = par.Jm; %del motore
        m.name='Parker NX110E'; %nome ---
        m.Imax = 0.99; %massimo livello di corrente 
        %calcolo fattore di conversione tensione corrente
        m.P = 0.21*10^-3;
        corrente_max =  5; % [A] dell'azionamento
        tensione_max = 10; %[V]dell'azionamento
        m.kr = corrente_max/tensione_max;
     
        
    m.Jr=(par.Jp1)+(par.Jp2+4*par.Jp3+par.m*par.r3^2)*(par.r1/par.r2)^2 ; %momento ridotto del carico all'asse del motore
    m.Jma = m.Jm + m.Jr; % mom.inerzia totale all'asse del motore 

    %costante elettrica 
    m.te = m.La/m.Ra;
    %costante elettromeccanica
    m.tem = m.Jma*m.Ra/m.K^2;
    
    % fdt omega/Va
    % coefficienti del polinomio in S al num e al den della fdt Laplace
    num = [1/m.K];
    den = [m.te*m.tem, m.tem, 1];
    
    tf_V_W = tf(num,den); %creo la funz. trasferimento
    %imposto nella ftd informazioni di utilita'
    set(tf_V_W,'Name',['motore ' m.name],'InputName','Va','OutputName','Omega');
    
    %funzione di trasferimento fra tensione Va e I
    num=[m.tem, 0];
    den=m.Ra*[m.te*m.tem, m.tem, 1];
    tf_V_I = tf(num,den); %creo la funz. trasferimento V= ingresso , I =uscita
    %imposto nella ftd informazioni di utilita'
    set(tf_V_I,'Name',['motore H_I' m.name],'InputName','Va','OutputName','I');
    
    
    %salvo nel dato motore
    m.tf_V_W = tf_V_W;
    m.tf_V_I = tf_V_I;
    
    
    
end

