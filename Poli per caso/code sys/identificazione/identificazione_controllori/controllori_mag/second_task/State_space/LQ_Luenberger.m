clear 
clc 
close all

%%
%per Windows 
% addpath('..\..\..\..\..\function')
% run('..\..\..\..\..\Model_Parameter.m')
%per Mac
addpath('../../../../../function')
run('../../../../../Model_Parameter.m')
Upper_bound_V = 23;
Lower_bound_V = 0;
x1 = 0.003;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(x1, theta);
%%
Q  = diag([50, 10 ,1e-6, 10]);
R = 10e-11;

x_max = [0.012; 1; 3; 0.1];  % m, rad/s, A, errore
u_max = 23;  % Volt

Q_n = diag(1 ./ (x_max.^2));  % penalizza in base al quadrato della grandezza
R_n = 1 / (u_max^2);

A_tilde = [ A,      zeros(n, 1);
            -C(1,:),     zeros(1, 1)];
B_tilde = [ B;
            0 ];

I = eye(4);
A_final = A_tilde + 1*I;
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

K = lqr(A_final, B_tilde, Q_n, R_n);
Ken_x = K(:, 1:3);
Ken_eta = K(:, 4);

%%
cl_poles = eig(A_tilde +7*eye(4)-B_tilde*Ken);

L_poles = 5*cl_poles(1:3)';
L = place(A', C', L_poles)';

A_ob = A - L*C;
B_ob = [ B - L*D, L];
C_ob = eye(n);
D_ob = zeros(n, m+p);
