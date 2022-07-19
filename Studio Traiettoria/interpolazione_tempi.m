function input_s = interpolazione_tempi(x_i,xp_i,xpp_i,y_i,yp_i,ypp_i,u,t_m)
%interpolazione tempi asse x
x= interp1(t_m,x_i,u,'Linear');
xp= interp1(t_m,xp_i,u,'Linear');
xpp= interp1(t_m,xpp_i,u,'Linear');
%interpolazione tempi asse y
y= interp1(t_m,y_i,u,'Linear');
yp= interp1(t_m,yp_i,u,'Linear');
ypp= interp1(t_m,ypp_i,u,'Linear');
% input_s = [x,xp,xpp,y,yp,ypp];
% x= interp1(t_m,x_i,u,'Linear');
% xp= interp1(t_m,xp_i,u,'Linear');
% xpp= interp1(t_m,xpp_i,u,'Linear');
% %interpolazione tempi asse y
% y= interp1(t_m,y_i,u,'Linear');
% yp= interp1(t_m,yp_i,u,'Linear');
% ypp= interp1(t_m,ypp_i,u,'Linear');
input_s = [x,xp,xpp,y,yp,ypp];

