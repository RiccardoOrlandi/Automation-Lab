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

u = 14.65;
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
scale = [0.012; 3; 10];
T = diag(1./scale);
A_n = T*A/T;
B_n = T*B;

Q = eye(3);
R_n = 1;
rank_o = rank(obsv(A,sqrt(Q)));
Q_n = inv(T)'*Q*inv(T);

K_n = lqr(A_n, B_n, Q_n, R_n);

K = K_n *T;


