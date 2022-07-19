function [Cy] = matrice_Cy(pary)


massa_modaley=zeros(4,4);
rigidezza_modaley=zeros(4,4);
W_i= zeros(4,1);
smorzamento_modaley=zeros(4,4);
    for ti=1:4
    
    W_i(ti,1)=sqrt(pary.Dy(ti,ti));
    
    massa_modaley(ti,ti) = pary.Vy(:,ti)'*pary.My*pary.Vy(:,ti);
    rigidezza_modaley(ti,ti) = pary.Vy(:,ti)'*pary.Ky*pary.Vy(:,ti);
    smorzamento_modale(ti,ti)=2*par.z*sqrt(massa_modale(ti,ti)*rigidezza_modale(ti,ti));
%    smorzamento_modaley(ti,ti)=2*pary.z*massa_modaley(ti,ti)*W_i(ti,1);
    end

C_diagonaliy = diag(((pary.Vy')^-1)*smorzamento_modaley*((pary.Vy)^-1));

Cy = zeros(4,4);

    for ti = 1:4
        Cy(ti,ti) = C_diagonaliy(ti);
    end

end

