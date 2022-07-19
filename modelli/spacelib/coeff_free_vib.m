function coeff=coeff_free_vib(V,D,x0,dotx0)
% function coeff=coeff_free_vib(V,D,x0,dotx0)
% prof. Paolo Righettini
% MECHANICAL VIBRATIONS
% parameters:
%   V: aignvectrs matrix
%   D: aignvalues matrix
%   x0, dotx0: inital conditions in position and speed (vectors)
% returns the coefficient of the free response (the coefficients of the linear combinaion of the modes)
% x0 e dotx0 condizioni iniziali

%numero gdl
[n]=size(D,1);

%coefficient matrix of the linear system 
A=zeros(2*n,2*n);

%the even columns define conditions on the positions
for k=1:n
 %copio il vettore modale 
  for j=1:n
      A(j,2*k) = V(j,k);
  end
end

%conditions on the speeds (odd column)
for k=1:n
 %copio il vettore modale 
  for j=1:n
      A(n+j,2*k-1) = V(j,k)*sqrt(D(k,k));
  end
end

%known terms
tn= [x0;dotx0];

% solution of the linear system
coeff=A\tn;

