clear 
clc 
close all

%%
%per Windows 
addpath('..\..\..\..\..\function')
run('..\..\..\..\..\Model_Parameter.m')
%per Mac
%addpath('../../../../../function')
%run('../../../../../Model_Parameter.m')

x1 = 0.006;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(x1, theta);
%%
Q  = diag([100,10,1, 100]);
R = 0.01;

A_tilde = [ A,      zeros(n, 1);
            -C(1,:),     zeros(1, 1)];
B_tilde = [ B;
            0 ];

I = eye(4);
A_final = A_tilde + 5*I;
if rank(ctrb(A_final, B_tilde)) == 4
    disp('Il sistema allargato è completamente controllabile');
else 
    disp('Sistema non controllabile');
end

if rank(ctrb(A_final, sqrt(Q))) == 4
    disp('Il sistema allargato è completamente osservabile');
else 
    disp('Sistema non osservabile');
end

K = lqr(A_final, B_tilde, Q, R);
K_x = K(:, 1:3);
K_eta = K(:, 4);
cl_poles = eig(A_final-B_tilde*K);

L_poles = 5*cl_poles(1:3)';
L = place(A', C', L_poles)';

A_ob = A - L*C;
B_ob = [ B - L*D, L];
C_ob = eye(n);
D_ob = zeros(n, m+p);
