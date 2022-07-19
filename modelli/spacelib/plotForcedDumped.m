function plotForcedDumped(M,C,K,F,vOmega)
%function plotForced(M,K,F,vOmega)
% prof. Paolo Righettini
% MECHANICAL VIBRATIONS
% plots the diagram of the steady state response
% vOmega: frequencies vector (column vector)
% F: vector with the amplitude of the forcing forces (all the forcing forces have the same frequency) (column vector)

A = solveForcedDumped(M,C,K,F,vOmega);
n=size(M,1);

ShowOnSameFigure(n,A,vOmega);
%ShowOnDifferentFigure(n,A,vOmega);


end

function ShowOnSameFigure(n,A,vOmega)
	figure; 
    
    %converto vOmega in Hz
    vOmega = vOmega/(2*pi);
    xlab = '[Hz]';
    
    %set(gcf,'name',['coordinata ' num2str(j)]);
	subplot(2,1,1); 
vClr = ['r','g','b','c','k','m','y'];
str='legend(';
for j=1:n
    semilogy(vOmega,abs(A(j,:)),vClr(j));
    %plot(vOmega,abs(A(j,:)),vClr(j));
    hold on
    str=strcat(str,sprintf('''x_%d(t)''',j));
    if( j < n ) 
        str=strcat(str,','); 
    else
        str=strcat(str,');'); 
    end
end
grid on;title('amplitude');
xlabel( xlab );
eval(str);

subplot(2,1,2);
for j=1:n
    plot(vOmega,angle(A(j,:))*180/pi,vClr(j));
    hold on
end
grid on;title('phase');
ylabel('[°]');    
xlabel(xlab);
eval(str)
end

function ShowOnDifferentFigure(n,A,vOmega)
    for j=1:n
        figure; set(gcf,'name',['coordinate ' num2str(j)]);
        subplot(2,1,1); 
        semilogy(vOmega,abs(A(j,:)));grid;title('amplitude');
        xlabel('[rad/s]');
        subplot(2,1,2); 
        plot(vOmega,angle(A(j,:))*180/pi);grid;title('phase');
        ylabel('[°]');    
        xlabel('[rad/s]');
    end

end