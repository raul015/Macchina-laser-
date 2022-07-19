function plot_free_vib(V,D,coeff,endTime,lw)
% function plot_free_vib(V,D,coeff,endTime,lw)
% prof. Paolo Righettini
% MECHANICAL VIBRATIONS
% coeff: vectors with the coefficient of the linear combination of the modes of vibration 
% V, D: eigenvalues and aigenvectors matrices 
% lw: linewidth

k=1;
[n]=size(D,1); 

if( nargin < 5 )
    lw=1;
end


wmax=max(sqrt(D(k,k)));
fmax = wmax/(2*pi);
fmin =min(sqrt(D(k,k)))/(2*pi);

if( nargin < 4 )
    endTime = 50/fmin;
end
npt=endTime*fmax*100;

dt=endTime/npt;
for t=0:dt:endTime
    xn = get_free_vibr(V,D,coeff,t);
    for j=1:n
        x(k,j) = xn(j);
    end
    tt(k)=t;
    k=k+1;
end

idx_end = npt/10;

figure; set(gcf,'name','free response - position');
for k=1:n
	subplot(n,1,k);plot(tt(1:idx_end),x(1:idx_end,k),'linewidth',lw);grid;title(['coordinate x' num2str(k) '(t)']);
    xlabel('time [s]'); ylabel('amplitude')
end

figure; set(gcf,'name','risposta libera - frequenze');
Fs = 1/dt;
for k=1:n
	subplot(n,1,k);

    [amp vf]=calcFFT(x(:,k) , Fs);
    %Y=fft(x(:,1),npt);

    %Pyy = Y.*conj(Y)/npt;
    %fs=1/dt;
    %f = fs/npt*(0:npt/2);
    nptplot = round((length(vf))*5*fmax/(Fs/2));
    %plot(f(1:npt/2),Pyy(1:npt/2))
    %plot(f(1:nptplot),Pyy(1:nptplot))
    plot(vf(1:nptplot),amp(1:nptplot),'linewidth',lw)
    
    %plot(tt,x(:,k));
    grid on;

    title(['amplitude - coordinata x' num2str(k) '(t)']);
    xlabel('Frequency (Hz)')
    ylabel('amplitude')
end

return

