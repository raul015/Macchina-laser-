function [trajectory,errore]=dxf_box_3(filedxf,ds,sifig)

%entita è un vettore con informazioni di interesse
%l_tot è la lunghezza totale della traiettoria
%errore è riferito al file es non letto correttamente ecc...
[entita2,l_tot,errore]=dxf2ent(filedxf,sifig);
%all'interno del file sono presenti molteplici entità di linee e archi di
%circonferenza, quindi entita2 avrà il numero di righe = al numero delle 
%entità presenti per il tracciamento della traiettoria.


%ds è il passo di campionamento.
trajectory=crea_traj_dxf(entita2,ds,1);