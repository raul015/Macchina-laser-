function [entita2,l_tot,errore]=dxf2ent(filedxf,sifig)
% *******************************************************************************
% function [entita2,l_tot,errore]=dxf2ent(filedxf,sifig)
%
% INPUT
%
% filedxf  -> file .dxf da trasformare (comprensivo di path)
%				  es. 'x:\work\pippo.dxf	
%
% sifig    -> se 1 visualizza la figura
%
% OUTPUT
%
% entita2  -> vettore entità contiene le entità del file dxf
%             1: tipo di  entità (1-linea 2-arco)
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
% l_tot    -> lunghezza totale del percorso
%
% errore   -> 0   conversione ok!
%	          1   file dxf non conforme
%             2   circuito aperto 
%             3   file non trovato
% *******************************************************************************


% inizializza il numero di entità
nument=1;  % se 1 linea, se 2 arco, è solo una inizializzazione
           % il valore cambierà alla lettura della prima riga del 
           % file...
entita=[0 0 0 0 0 0 0 0 0 0];

% inizializza l'errore a nessun errore
errore=0; 

%-------------------------------------------------------
%
%    Apertura files in lettura
%
%-------------------------------------------------------
ifp = fopen(filedxf, 'r');
if (ifp==-1)
   disp('file not found\n');
   errore=3;
   return;
end
   
%ofp = fopen('c:\pippo.txt', 'w+');
%if (ifp==-1)
%   disp('file not found\n');
%   errore=3;
%   return;
%end
    
disp('inizio scanning\n');

%-------------------------------------------------------
%
%    Scanning del file di testo
%
%-------------------------------------------------------
i=0;

%la funzione ritorna 1 se ho settato fine file 
%altrimenti ritorna 0 se non è andato bene

while (~feof(ifp)) 
   nome=fgetl(ifp);
   % LINEA, confronta il nome con AcDLine
   if (strcmp(nome,'AcDbLine'))
      disp('linea\n');
      % 10
      prova=str2num(fgetl(ifp));
      if (prova ~= 10)
         errore=1;
         break;
      end
      xini=str2num(fgetl(ifp));
      % 20
      prova=str2num(fgetl(ifp));
      if (prova ~= 20)
         errore=1;
         break;
      end
      yini=str2num(fgetl(ifp));
      % 30
      prova=str2num(fgetl(ifp));
      if (prova ~= 30)
         errore=1;
         break;
      end
      trash=str2num(fgetl(ifp));
	   % 11
      prova=str2num(fgetl(ifp));
      if (prova ~= 11)
         errore=1;
         break;
      end
      xfin=str2num(fgetl(ifp));
      % 21
      prova=str2num(fgetl(ifp));
		if (prova ~= 21)
         errore=1;
         break;
      end
      yfin=str2num(fgetl(ifp));
      % 31
      prova=str2num(fgetl(ifp));
		if (prova ~= 31)
         errore=1;
         break;
      end
      trash=str2num(fgetl(ifp));                 
          
 %     fprintf(ofp,'%d %6.2f %6.2f %6.2f %6.2f\n',1,xini,yini,xfin,yfin);
      entita(nument,1:5)=[1,xini,yini,xfin,yfin];
      nument=nument+1;  %   ??? incrementa l'entità
 %In questo caso di entità ci interessano solo i primi 5 campi
 %non mi interessa il centro,raggio e angoli.
   end %end linea     
        
   % ARCO, confronta il nome con AcDbCircle
   if (strcmp(nome,'AcDbCircle'))              
      disp('Arco\n');
      % 10 - X Centro
      prova=str2num(fgetl(ifp));
      if (prova ~= 10)
         errore=1;
         break;
      end
      xcen=str2num(fgetl(ifp));
      % 20 - Y Centr
      prova=str2num(fgetl(ifp));
      if (prova ~= 20)
         errore=1;
         break
      end
      ycen=str2num(fgetl(ifp));
      % 30 - Z Centro
      prova=str2num(fgetl(ifp));
      if (prova ~= 30)
         errore=1;
         break;
      end
      trash=str2num(fgetl(ifp));
      % 40 - Raggio
      prova=str2num(fgetl(ifp));
      if (prova ~= 40)
         errore=1;
         break;
      end
      radius=str2num(fgetl(ifp));
      % Valori controllo
      trash=str2num(fgetl(ifp));
      % ----------------------------
      % circonferenza
      % viene gestita come due archi
      % ----------------------------
      if trash==0
      %   fprintf(ofp,'%d %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f\n',2,xcen+radius,ycen+radius,xcen+radius,xcen+radius,xcen,ycen,radius,0,360);
         entita(nument,:)=[2,xcen+radius,ycen,xcen-radius,ycen,xcen,ycen,radius,0,180];
         nument=nument+1;
         entita(nument,:)=[2,xcen-radius,ycen,xcen+radius,ycen,xcen,ycen,radius,180,360];
         nument=nument+1;
         break;
      end
      trash=str2num(fgetl(ifp));
      % 50 - Start angle */
      prova=str2num(fgetl(ifp));
      if (prova ~= 50)
         errore=1;
         break;
      end
      aini=str2num(fgetl(ifp));
      % 51 - Stop angle */
      prova=str2num(fgetl(ifp));
      if (prova ~= 51)
         errore=1;
         break
      end
      afin=str2num(fgetl(ifp));
      % arco
      xini = xcen+radius*cos(aini*pi/180);
      yini = ycen+radius*sin(aini*pi/180);
      xfin = xcen+radius*cos(afin*pi/180);
      yfin = ycen+radius*sin(afin*pi/180);
      %fprintf(ofp,'%d %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f\n',2,xini,yini,xfin,yfin,xcen,ycen,radius,aini,afin);
      entita(nument,:)=[2,xini,yini,xfin,yfin,xcen,ycen,radius,aini,afin];
      nument=nument+1;
   end %end arco
end % end while

fclose(ifp);
%fclose(ofp);
if errore==1
   disp('Il file dxf è corrotto o non conforme');
end
disp('Fine elaborazione');



%-------------------------------------------------------
%
% 				    Algoritmo di ordinamento
%
%-------------------------------------------------------

% tronca i valori alla terza decimale  (???)
entita=round(entita*1000)/1000;

% inizializzazioni
entita3=[];
% spostamento della prima entità da entita a entita2
[row,col]=size(entita); %inizializzata e cambiata durante lettura file.
entita2(1,:)=entita(1,:); % copio il contenuto di entita in entita2
entita=entita(2:row,:);
% calcolo dimensioni entita nuova
[row,col]=size(entita);
% cerco la seconda entita in ordine
j=2;
while row>0
   for i=1:row
      % la fine dell'entita2 è confrontata con gli inizi di entita nuova
      if ((entita2(j-1,4)==entita(i,2)) & (entita2(j-1,5)==entita(i,3)))
         % trova l'entita consecutiva e la salva in entita2
         entita2(j,:)=entita(i,:);
         % incrementa alla riga successiva entita2
         j=j+1;
         break; %uscita dal ciclo
      %  la fine dell'entita2 è confrontata con i punti fine di entita
      %  nuova (nel caso di entita ribaltate)
      elseif ((entita2(j-1,4)==entita(i,4)) & (entita2(j-1,5)==entita(i,5)))
         % se linea non cambia la notazione in entita2
         if entita(i,1)==1
            entita2(j,1)=1;
         % cerchi orari e antiorari cambia il segno in entita2
         elseif entita(i,1)==2
            entita2(j,1)=-2;
         end
         % inverto punti inizio e fine in entita2 rispetto a entita
         entita2(j,2:3)=entita(i,4:5);
         entita2(j,4:5)=entita(i,2:3);
         entita2(j,6:8)=entita(i,6:8);
         entita2(j,9)=entita(i,10);
         entita2(j,10)=entita(i,9);
         % passo alla prossima riga di entita2
         j=j+1; 
         break; %uscita dal ciclo
      end
   end
   
   % tolgo l'entita accodata da entita
   k=1;f=1;
   for w=1:row
      % coppio in entita3 tutte le entita tranne quella selezionata al
      % ciclo for precedente
      if (k~=i)
         % entro tutte le volte tranne che per il punto in esame
         entita3(f,:)=entita(k,:);
         % incremento in entita3 tranne che per il punto in esame
         f=f+1;
      end
      % incremento sempre in entita anche se è il punto incriminato
      k=k+1;
   end
   % svuoto entita
   entita=[];
   % lo riempio con entita3
   entita=entita3;
   entita3=[];
   % ricalcolo la lunghezza di entita accorciata di un elemento
   [row,col]=size(entita);
end



%-------------------------------------------------------
%
% Controllo sulla topologia del percorso
%
%-------------------------------------------------------
[row,col]=size(entita2);
if (entita2(1,2)==entita2(row,4) & entita2(1,3)==entita2(row,5))
   disp('OK CIRCUITO CHIUSO');
else
   disp('KO CIRCUITO CHIUSO');
   errore=2;
   %return;
end


%-------------------------------------------------------
%
% 				    Calcolo lunghezza totale
%
%-------------------------------------------------------

[row,col]=size(entita2);
l=zeros(1,row);
l_tot=0;
for i=1:row
   if entita2(i,1)==1
      l(i)=sqrt(((entita2(i,2)-entita2(i,4))^2)+((entita2(i,3)-entita2(i,5)))^2);
   elseif (entita2(i,1)==2) | (entita2(i,1)==-2)
      l(i)=entita2(i,8)*rad(abs(entita2(i,9)-entita2(i,10)));
   end
   l_tot=l_tot+l(i);
end

%-------------------------------------------------------
%
% 									Disegno
%
%-------------------------------------------------------
%se visualizza la figura
if sifig
   axis([0 300 0 300]);
   grid on;
   for i=1:row
   	    if entita2(i,1)==1
      	    line([entita2(i,2) entita2(i,4)],[entita2(i,3) entita2(i,5)],'color','r');
   	    elseif (entita2(i,1)==2) | (entita2(i,1)==-2)
      	    arco(entita2(i,6),entita2(i,7),entita2(i,8),entita2(i,9),entita2(i,10),entita2(i,1)/2);
		end
        %pause;
   end
end




