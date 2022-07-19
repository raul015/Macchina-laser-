function amp=solveForcedDumped(M,C,K,F,Omega)
%function amp=solveForcedDumped(M,C,K,F,Omega)
% prof. Paolo Righettini
% MECHANICAL VIBRATIONS
% calculation of the steady state response for the given frequencies
% M: mass matrix
% K: stiffness matrix
% C: damping matrix

n=length(Omega);
amp=zeros(length(F),n);

for k=1:n
    % mechanical impedence matrix
    Z=-Omega(k)^2*M+C*1i*Omega(k)+K;
    amp(:,k)=Z\F;
end

return

