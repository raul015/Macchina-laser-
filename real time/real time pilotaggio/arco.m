function handle=arco(xc,yc,r,aini,afin,senso)

aini=rad(aini);
afin=rad(afin);
passo=abs(afin-aini)/100;
% angolo a cavallo del passaggio 0-360
if senso<0
   if aini<afin
      passo=(aini+(2*pi-afin))/100;
   end
end
if senso>0
   if aini>afin
      passo=((2*pi-aini)+afin)/100;
   end
end



k=1;
teta(1)=aini;
angolo=0;
while k<101
   k=k+1;
   angolo=teta(k-1)+senso*passo;
   if angolo<0
      angolo=2*pi+angolo;
   end
   teta(k)=angolo;
end

coord=[0 0];
for k=1:length(teta)   
   coord(k,1)=xc+r*cos(teta(k));
   coord(k,2)=yc+r*sin(teta(k));
end

handle=line(coord(:,1),coord(:,2),'Color','r');
