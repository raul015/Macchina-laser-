function [ac] = anello_corrente( m )
% global m
% sintetizza regolatore di corrente
% parametri ingresso: m il motore dc
% uscita:
% ac: dato strutturato con i dati del regolatore di corrente

% definisco funzione di trasferimento semplificata in corrente
% considero solamente la parte elettrica
tf_Hi_simple = tf(1/m.Ra,[m.te, 1]);

% fisso frequenza critica
fc = 1000;
wc = 2*pi*fc; %pulsazione critica

%sintesi anello di corrente
ti_i = m.te; %prima equazione >> costante di tempo integrale 
kg_i = wc*m.te*m.Ra; %secondo parametro>> guadagno di corrente del sistema

% scriviamo il regolatore (PI)
PI_I = kg_i*tf([ti_i, 1],[ti_i, 0]); % abbiamo uno zero in corrispondenza di tau i

%funzione d'anello
L_simple = PI_I * tf_Hi_simple;
L_compl = PI_I * m.tf_V_I;

%funz. di trasferimento anello chiuso
H_I_simple = feedback(L_simple,1);
H_I = feedback(L_compl,1); % permette di ricostruire l'anello chiuso con retroazione positiva o negativa


% diagrammi utili
% figure
% bode(tf_Hi_simple,'r',m.tf_V_I,'g');
% grid on
% legend('simple','compl');
% title('fdt Va -> I del motore');


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

