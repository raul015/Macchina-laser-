function [ ac ] = anello_corrente( m )
% sintetizza regolatore di corrente
% parametri ingresso: m il motore dc
% uscita:
% ac: dato strutturato con i dati del regolatore di corrente

% definisco funzione di trasferimento semplificata in corrente
% considero solamente la parte elettrica
tf_Hi_simple = tf(1/m.Ra,[m.te, 1]); %gli devo passare numeratore e denominatore

% fisso frequenza critica
fc = 1000;
wc = 2*pi*fc; %pulsazione critica

%sintesi anello di corrente
ti_i = m.te; %prima equazione, costante tempo integrale linea in corrente = costante elettrica del motore
%questo perchè voglio elimnare il polo con lo zero.
%anello in corrente = parte elettrica
kg_i = wc*m.te*m.Ra; %secondo parametro

% scriviamo il regolatore (PI)
PI_I = kg_i*tf([ti_i, 1],[ti_i, 0]);

%funzione d'anello
L_simple = PI_I * tf_Hi_simple;
L_compl = PI_I * m.tf_V_I;

%funz. di trasferimento anello chiuso
H_I_simple = feedback(L_simple,1); %ricostruisce il sistema ad anello chiuso moto la funzione di anello 
H_I = feedback(L_compl,1);


% diagrammi utili
figure
bode(tf_Hi_simple,'r',m.tf_V_I,'g');
grid on
legend('simple','compl');
title('fdt Va -> I del motore');

%fdt anello chiuso
figure
bode(H_I_simple,'r',H_I,'g');
grid on
legend('simple','compl');
title('fdt H_I anello chiuso in corrente');

%salvo informazioni in ac
ac.tf_Hi_simple = tf_Hi_simple;
ac.fc = fc;
ac.PI_I = PI_I;
ac.L_simple = L_simple;
ac.L_compl = L_compl;
ac.H_I_simple = H_I_simple;
ac.H_I = H_I;
ac.ti_i = ti_i;
ac.kg_i = kg_i;







end

