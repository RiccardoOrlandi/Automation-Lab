clear 
clc 
close all

%%
%per Windows 
% addpath('..\..\..\..\..\function')
% run('..\..\..\..\..\Model_Parameter.m')
%per Mac
addpath('../function')
run('../Model_Parameter.m')
Upper_bound_V = 23;
Lower_bound_V = 0;
x1 = 0.003;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(x1, theta);
%% LQ control
Q_lq  = diag([100, 10 ,100, 10]);
R_lq = 10;

x_max = [0.012; 3; 0.1; 1];  % m, rad/s, A, errore
u_max = 23;  % Volt

Q_n = diag(1 ./ (x_max.^2))*Q_lq;  % penalizza in base al quadrato della grandezza
R_n = 1 / (u_max^2)*R_lq;

A_tilde = [ A,      zeros(n, 1);
            -C(1,:),     zeros(1, 1)];
B_tilde = [ B;
            0 ];

I = eye(4);
A_final = A_tilde + 3*I;
if rank(ctrb(A_final, B_tilde)) == 4
    disp('Il sistema allargato è completamente controllabile');
else 
    disp('Sistema non controllabile');
end

if rank(ctrb(A_final, sqrt(Q_lq))) == 4
    disp('Il sistema allargato è completamente osservabile');
else 
    disp('Sistema non osservabile');
end

K = lqr(A_final, B_tilde, Q_n, R_n);
Ken_x = K(:, 1:3);
Ken_eta = K(:, 4);
cl_poles = eig(A_tilde-B_tilde*K);
%%

L_poles = 5*cl_poles(1:3)';
L_kf = place(A', C', L_poles)';
eig(A-L_kf*C);

A_ob = A - L_kf*C;
B_ob = [ B - L_kf*D, L_kf];
C_ob = eye(n);
D_ob = zeros(n, m+p);
