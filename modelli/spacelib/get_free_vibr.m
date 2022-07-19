function x=get_free_vibr(V,D,coeff,t)
% prof. Paolo Righettini
% vibrazioni meccaniche
% function x=get_free_vibr(V,D,coeff,t)
% V e D di eig
% coeff vettore della combinazione lineare dei modi
% t tempo a cui calcolare la risposta libera

[n]=size(D,1);

x=zeros(n,1);

for k=1:n
    w = sqrt(D(k,k));
    % sommo i contributi di tutti i modi al tempo t
    x = x + coeff(2*k-1)*V(:,k)*sin(w*t) + coeff(2*k)*V(:,k)*cos(w*t);
    
end