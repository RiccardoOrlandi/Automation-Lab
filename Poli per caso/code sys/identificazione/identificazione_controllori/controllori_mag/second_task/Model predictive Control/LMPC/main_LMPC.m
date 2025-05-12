clear 
clc 
close all

%%
%per Windows 
addpath('..\..\..\..\..\..\function')
run('..\..\..\..\..\..\Model_Parameter.m')
%per Mac
%addpath('../../../../../function')
%run('../../../../../Model_Parameter.m')

%% faccio partire il blocco oggetto MPC
run('LMPC.m')



x1 = 0.006;
%u = 9.515; %quando forza magnetica riferita al top scambiare 9.515 con 14.65
n = 3;
m = 1; 
p = 2;
Upper_bound_V = 23;
Lower_bound_V = 0;

[G, A, B, C, D] = lin(x1, theta);
sys = ss(A, B, C, D);

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
desired_poles_pp = [-10, -40, -50];
Kpp = place(A, B, desired_poles_pp);

% sys_cl_pp = ss(A - B * Kpp, B, C, D);
% figure(3);
% legend('after cl')
% sigma(sys_cl_pp);

desired_poles_obs = [-15, -120, -150];
L = place(A', C', desired_poles_obs)';

A_ob = A - L*C;
B_ob = [ B - L*D, L];
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

en_desired_poles = [desired_poles_pp, -3];
Ken = place(A_tilde, B_tilde, en_desired_poles);

Ken_x = Ken(:, 1:n);
Ken_eta = Ken(:, n+1:end);








