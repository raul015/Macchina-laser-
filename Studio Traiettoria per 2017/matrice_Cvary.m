function [CCy] = matrice_Cvary(pary,KKy)

K_mody=zeros(pary.n,pary.n);
M_mody=zeros(pary.n,pary.n);
C_mody=zeros(pary.n,pary.n);

    for ti=1:4
    M_mody(ti,ti) = pary.Vy(:,ti)'*pary.My*pary.Vy(:,ti);
    K_mody(ti,ti) = pary.Vy(:,ti)'*KKy*pary.Vy(:,ti);
    
    C_mody(ti,ti)=2*pary.z*sqrt(M_mody(ti,ti)*K_mody(ti,ti));
    end

CCy = ((pary.Vy')^-1)*C_mody*((pary.Vy)^-1);

