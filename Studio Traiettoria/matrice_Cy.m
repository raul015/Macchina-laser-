function [Cy] = matrice_Cy(pary)

K_mod=zeros(pary.n,pary.n);
M_mod=zeros(pary.n,pary.n);
C_mod=zeros(pary.n,pary.n);

    for ti=1:4
    M_mod(ti,ti) = pary.Vy(:,ti)'*pary.My*pary.Vy(:,ti);
    K_mod(ti,ti) = pary.Vy(:,ti)'*pary.Ky*pary.Vy(:,ti);
    
    C_mod(ti,ti)=2*pary.z*sqrt(M_mod(ti,ti)*K_mod(ti,ti));
    end

Cy = ((pary.Vy')^-1)*C_mod*((pary.Vy)^-1);

end

