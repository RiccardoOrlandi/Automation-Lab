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

x1 = 0.003;
%u = 9.515; %quando forza magnetica riferita al top scambiare 9.515 con 14.65
n = 3;
m = 1; 
p = 2;
Upper_bound_V = 23;
Lower_bound_V = -23;

[G, A, B, C, D] = lin(x1, theta);
sys = ss(A, B, C, D);
tf_g = tf(sys)
C1 = C(1,:);

rank_c = rank(ctrb(A,B));
rank_o = rank(obsv(A,C));

if rank_c == 3 && rank_o == 3
    disp('Il sistema è completamente controllabile e raggiungibile');
end
% figure(1)
% disp(pole(G));
% disp(tzero(G));
%sigma(G)
%%
%Trovo Kpp per il pole placement e L per l'osservatore di Luenberger
i = sqrt(-1);
desired_poles_pp = [-40, -50, -70];
Kpp = place(A, B, desired_poles_pp);

% sys_cl_pp = ss(A - B * Kpp, B, C, D);
% figure(3);
% legend('after cl')
% sigma(sys_cl_pp);

desired_poles_obs = [-400, -500, -700];
L = place(A', C', desired_poles_obs)';

A_ob = A - L*C;
B_ob = [ B, L];
C_ob = eye(n);
D_ob = zeros(n, m+p);

%%

A_tilde = [ A,      zeros(n, 1);
            -C(1,:),     zeros(1, 1)];
B_tilde = [ B;
            0 ];
M_tilde = [ zeros(n, 1);
            eye(1) ];

disp(rank(ctrb(A_tilde, B_tilde)))

en_desired_poles = [desired_poles_pp, -5];
Ken = place(A_tilde, B_tilde, en_desired_poles);

Ken_x = Ken(:, 1:n);
Ken_eta = Ken(:, n+1:end);

syms s
K = Ken_x*C_ob*((s*eye(3)-A_ob)\B_ob);
K_x1 = K(1,1);
K_x2 = K(1,2);
K_x3 = K(1,3);

H = C*((s*eye(3)-A)\B);

num_pre = -Ken_eta*H(1,:);
den_pre = s*(1 + K_x1+K_x3*H(2,:))-H(1,:)*(Ken_eta-s*K_x2);
G_cl = den_pre \ num_pre;
[num_sym, den_sym] = numden(G_cl);
num = sym2poly(num_sym);
den = sym2poly(den_sym);
G_tf = tf(num, den);
bode(G_tf)