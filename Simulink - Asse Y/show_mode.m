function [vs,ds]=show_mode(M,K)
%function [vs,ds]=showMode(M,K) - shows the mode of vibraitons
% returns the solution of the eigenvalues and eigenvectors problem
% prof. Paolo Righettini
% MECHANICAL VIBRATIONS


mm=M\K;

%disp('Characteristic polynomial: ')
%disp(poly(mm))
[v,d]=eig(mm);

%calculation of the dof number
[n]=size(d,1);

% sorts the natural frequencies 
ms=zeros(n,2);
for k=1:n
    ms(k,1)= sqrt(d(k,k));
    ms(k,2) = k;
end
ws=mysort(ms);

% sorts frequencies and modes 
vs=zeros(n,n);
ds=zeros(n,n);
for k=1:n
    idx = ws(k,2);
    vs(:,k)=v(:,idx);
    ds(k,k)=d(idx,idx);
end

for k=1:n
    idx = k;
    
    w = sqrt(ds(idx,idx));
   fprintf(1,'mode %d - natural frequency w = %f [rad/s] - %f [Hz] \n',k,w,w/(2*pi));
    fscala = max(abs(vs(:,idx)));
    for j=1:n
        fprintf(1,'A%d = %f \n',j,vs(j,idx)/fscala);
        %disp( ['A' num2str(j) '  = ' num2str(vs(j,idx)/fscala) ])
    end
          %aggiunto io 
    vs(:,idx)=vs(:,idx)./fscala;
end

end

function ws=mysort(ms)
    nr = size(ms,1);
    k=1;
    while( k <= (nr-1))
        if( ms(k+1,1) < ms(k,1) ) 
            rr = ms(k,:);
            ms(k,:) = ms(k+1,:);
            ms(k+1,:) = rr;
            k=1;
        else
            k=k+1;
        end
    end
    ws=ms;
end
