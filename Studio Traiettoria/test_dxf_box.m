function vs=test_dxf_box

% --- crazione traiettoria ---
file='.\zig.dxf';
[trajectory,errore]=dxf_box_3(file,1,1);
trajectory.l
%axis([.15 0.45 -.02 0.12]);
axis equal;
figure;
plot(trajectory.x,trajectory.y,'r.');
disp('premi un tasto per continuare');