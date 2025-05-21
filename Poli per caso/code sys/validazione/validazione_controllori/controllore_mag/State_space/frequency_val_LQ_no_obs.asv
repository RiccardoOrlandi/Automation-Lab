clear 
clc 
close all

%%
%per Windows 
% addpath('..\..\..\..\function')
% run('..\..\..\..\Model_Parameter.m')

%per Mac
addpath('../../../../function')
run('../../../../Model_Parameter.m')

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
A_final = A_tilde + 7*I;
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
cl_poles = eig(A_final-B_tilde*K);

syms s

F = ((s*eye(3)-A)\B);
H = C*F;

num_pre = -H(1,:)*Ken_eta;
den_pre = s*(1+Ken_x*F)-Ken_eta*H(1,:);

G_cl = den_pre \ num_pre;
[num_sym, den_sym] = numden(G_cl);
num = sym2poly(num_sym);
den = sym2poly(den_sym);
G_tf = tf(num, den);
bode(G_tf)