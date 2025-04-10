clear 
clc 
close all

%%
%per Windows 
addpath('..\..\..\function')
run('..\..\..\Model_Parameter.m')
%per Mac
%addpath('../../../function')
%run('../../../Model_Parameter.m')

u = 12;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(u, theta);

rank_c = rank(ctrb(A,B));
rank_o = rank(obsv(A,C));

if rank_c == 3 && rank_o == 3
    disp('Il sistema è completamente controllabile e raggiungibile');
end

%%
%Trovo Kpp per il pole placement e L per l'osservatore di Luenberger

desired_poles_pp = [-20, -30, -40];
Kpp = place(A, B, desired_poles_pp);

desired_poles_obs = [-200, -300, -400];
L = place(A', C', desired_poles_obs)';

A_ob = A - L*C;
B_ob = [ B - L*D, L];
C_ob = eye(n);
D_ob = zeros(n, m+p);
