function [CC] = matrice_Cvar(par,KK)

K_mod=zeros(par.n,par.n);
M_mod=zeros(par.n,par.n);
C_mod=zeros(par.n,par.n);

    for ti=1:4
    M_mod(ti,ti) = par.V(:,ti)'*par.M*par.V(:,ti);
    K_mod(ti,ti) = par.V(:,ti)'*KK*par.V(:,ti);
    
    C_mod(ti,ti)=2*par.z*sqrt(M_mod(ti,ti)*K_mod(ti,ti));
    end

CC = ((par.V')^-1)*C_mod*((par.V)^-1);

