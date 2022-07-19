function [amp, vf]=calcFFT(data , Fs, lmin)
% function [amp vf]=calcFFT(data , Fs)
% prof. Paolo Righettini ----

if( nargin < 3 )
    lmin =1;
end

    L=length(data);
    if( L < lmin )
        if( size(data,2) == 1 )
            data=[data; zeros(lmin-L,1)];
        else
            data=[data zeros(1,lmin-L)];
        end
        L=length(data);
    end
    %NFFT = 2^(nextpow2(L)-1);
    NFFT = 2^nextpow2(L);
    %NFFT = L;
    df = (Fs)/(NFFT);
    vf=Fs/2*linspace(0,1,NFFT/2);
    FFTf=fft(data,NFFT)/(L/2);
    amp=abs(FFTf);
    amp=amp(1:NFFT/2);

end