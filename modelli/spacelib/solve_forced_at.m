function amp=solve_forced_at(M,K,F,Omega)
% prof. Paolo Righettini
% vibrazioni meccaniche
% function amp=solve_forced_at(M,K,F,Omega)

%matrice dei coeff
A=-Omega^2*M+K;
tn=F; 
amp=A\tn; %soluzione del sistema lineare

return

