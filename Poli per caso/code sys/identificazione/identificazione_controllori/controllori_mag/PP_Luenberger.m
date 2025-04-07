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

u = 15;
[G, A, B, C, D] = lin(u, theta);

rank_c = rank(ctrb(A,B));
rank_o = rank(obsv(A,C));

if rank_c == 3 && rank_o == 3
    disp('Il sistema è completamente controllabile e raggiungibile');
end