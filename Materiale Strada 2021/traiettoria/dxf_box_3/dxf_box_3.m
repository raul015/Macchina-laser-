function [trajectory,errore]=dxf_box_3(filedxf,ds,sifig)

[entita2,l_tot,errore]=dxf2ent(filedxf,sifig)
trajectory=crea_traj_dxf(entita2,ds,1);