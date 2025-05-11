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
add_data('../../../../../data/Step Test/Step Test with ball')
add_data('../../../../../data/Step Test/Step Test with ball');
add_data('../../../../../data/Step Test/18_03_2025_v2/with ball');
add_data('../.././../../data/Step Test/18_03_2024/with_ball');
add_data('../../../../../data/Step Test/04_04_2025')
Upper_bound_V = 23;
Lower_bound_V = 0;
x1 = 0.003;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(x1, theta);
%%
%The system is unstable and it has no zeros but the number of input is
%lower than the number of output so it cannot be enlarged
%We are interested in the position so we "reduce" the number of outputs
C1 = [1 0 0];
D1 = 0;
%% System enlargment
A_tilde = [ A,      zeros(n, 1);
            -C1,     zeros(1, 1)];
B_tilde = [ B;
            0 ];

x_max = diag([0.012, 3, 1, 1]);
u_max = 23;
Q_n = diag([0.005, 1, 500, 1]);
R_n = 10;

Q_lq = diag( (1 ./ x_max).^2 ) .* Q_n;
R_lq = diag( (1 ./ u_max).^2 ) .* R_n;

if rank(ctrb(A_tilde, B_tilde)) == 4
    disp('Il sistema allargato è completamente controllabile');
else 
    disp('Sistema non controllabile');
end

if rank(obsv(A_tilde, sqrt(Q_lq))) == 4
    disp('Il sistema allargato è completamente osservabile');
else 
    disp('Sistema non osservabile');
end

Ken = lqr(A_tilde + 5*eye(4), B_tilde, Q_lq, R_lq);

Ken_x = Ken(:, 1:n);
Ken_eta = Ken(:, n+1:end);

sim("LQ_Luenberger_no_obs.slx");

%% Kalman Filter 
% x1_mes = T21_6V(2, indice_scalino:indice_scalino+300);
% x1_sim = y(2, indice_scalino2:indice_scalino2+300);
t_end = Test_21V(1,end);
out = sim("model_non_lineare2023b.slx");
x3_mes = gradient(Test_21V(2,:),Test_21V(1,:));
residui = Test_21V(2,501:611) - out.x1_sim(501:611)';
q11 = var(residui);
residui_corr = Test_21V(3,501:611)- out.x2_sim(501:611)';
q22 = var(residui_corr);
residui_vel = x3_mes(501:611) - out.x3_sim(501:611)';
q33 = var(residui_vel);
Q = diag([q11,q22,q33]);
% === Output ===
disp('Matrice Q stimata dal confronto modello vs dati:')
disp(Q)


data_R = Test_9V;
% Estrazione delle misure
y1 = data_R(2,:);  % Posizione
y2 = data_R(3,:);  % Corrente

% Selezione dei campioni in regime (opzionale)
% Includi solo i campioni dove il sistema è "fermo", es. ultimi secondi
% qui selezioniamo gli ultimi 1000 campioni come esempio:
regime_samples = 3000;
y1_regime = y1(end-regime_samples+1:end);
y2_regime = y2(end-regime_samples+1:end);

% Calcolo delle varianze (assumiamo indipendenza tra canali)
y1_bar = mean(y1_regime);
var_y1 = sum((y1_regime - y1_bar).^2)/(length(y1_regime)-1);
%var_y1 = var(y1_regime);  % '1' = usa N nel denominatore, stimatore ML
var_y2 = var(y2_regime);

% Matrice R stimata (diagonale)
%R = diag([var_y1, var_y2]); %2x2
R = var_y1;

disp('Matrice di covarianza del rumore di misura R:')
disp(R)

L_kf = lqr(A.', C.', Q, R).';
eig(A-L_kf*C);

A_ob = A - L_kf*C;
B_ob = [ B - L_kf*D, L_kf];
C_ob = eye(n);
D_ob = zeros(n, m+p);

if rank(ctrb(A, sqrt(Q))) == 3
    disp('Il sistema è completamente controllabile');
else 
    disp('Sistema non controllabile');
end

if rank(obsv(A, C)) == 3
    disp('Il sistema è completamente osservabile');
else 
    disp('Sistema non osservabile');
end

