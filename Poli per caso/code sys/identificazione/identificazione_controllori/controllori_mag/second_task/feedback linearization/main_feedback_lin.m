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


%% Observer
x1 = 0.003;
n = 3;
q = 1; 
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

desired_poles_obs = [-200, -250, -280];
L = place(A', C', desired_poles_obs)';

A_ob = A - L*C;
B_ob = [ B - L*D, L];
C_ob = eye(n);
D_ob = zeros(n, q+p);

%% parametri modello
Rtot_mod = 7.0585; % R = 9.7585
Lc_mod = 0.4708; % Lc = 0.3708
k_mag_mod = 3.2405e-05; % k_mag = 2.4405e-05

%% PLOT RESULT

out = sim('feedback_lin_Test');
ref = out.ref;
FL = out.FL;
FL_RLS = out.FL_RLS;
FL_RLS_PI = out.FL_RLS_PI;
t = out.tout;

%%
figure()
plot_Latex(t, ref, 'Time [s]', 'Position [m]', 'Feedback Linearization Comparison', [-0.001, 0.004]);

hold on
plot_Latex(t, FL_RLS, 'Time [s]', 'Position [m]', 'Feedback Linearization Comparison', [-0.001, 0.004]);
h = plot_Latex(t, FL_RLS_PI, 'Time [s]', 'Position [m]', 'Feedback Linearization Comparison', [0, 0.004]);
h.Color = 'b';
plot_Latex(t, FL, 'Time [s]', 'Position [m]', 'Feedback Linearization Comparison', [0, 0.004]);


hold off
grid on
legend('ref', 'FL RLS', 'FL RLS I','FL')

