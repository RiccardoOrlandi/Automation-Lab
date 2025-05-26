clear 
clc 
close all

%%
%per Windows 
% addpath('..\..\..\..\..\function')
% run('..\..\..\..\..\Model_Parameter.m')
% add_data('..\..\..\..\..\data\LQ')
% add_data('..\..\..\..\..\data\Step Test\Step Test with ball')
% add_data('..\..\..\..\..\data\Step Test\Step Test with ball');
% add_data('..\..\..\..\..\data\Step Test\18_03_2025_v2\with ball');
% add_data('..\..\..\..\..\data\Step Test\18_03_2024\with_ball');
% add_data('..\..\..\..\..\data\Step Test\04_04_2025');
%per Mac
addpath('../../../../../function')
run('../../../../../Model_Parameter.m')
add_data('../../../../../data/Step Test/Step Test with ball')
add_data('../../../../../data/Step Test/Step Test with ball');
add_data('../../../../../data/Step Test/18_03_2025_v2/with ball');
add_data('../.././../../data/Step Test/18_03_2024/with_ball');
add_data('../../../../../data/Step Test/04_04_2025');
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

% %% Kalman Filter 
% % x1_mes = T21_6V(2, indice_scalino:indice_scalino+300);
% % x1_sim = y(2, indice_scalino2:indice_scalino2+300);
% t_end = Test_21V(1,end);
% out1 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(Test_21V(2,:),Test_21V(1,:));
% residui = Test_21V(2,501-0.05/0.002:611-0.05/0.002) - out1.x1_sim(501:611)';
% q11 = var(residui);
% residui_corr = Test_21V(3,501-0.05/0.002:611-0.05/0.002)- out1.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501-0.05/0.002:611-0.05/0.002) - out1.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q1 = diag([q11,q22,q33]);
% % === Output ===
% % disp('Matrice Q stimata dal confronto modello vs dati:')
% % disp(Q)
% 
% t_end = T22_5V(1,end);
% out2 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(T22_5V(2,:),T22_5V(1,:));
% residui = T22_5V(2,501:611) - out2.x1_sim(501:611)';
% q11 = var(residui);
% residui_corr = T22_5V(3,501:611)- out2.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501:611) - out2.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q2 = diag([q11,q22,q33]);
% % % === Output ===
% % disp('Matrice Q stimata dal confronto modello vs dati:')
% % disp(Q)
% 
% t_end = T21V_v2(1,end);
% out3 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(T21V_v2(2,:),T21V_v2(1,:));
% residui = T21V_v2(2,501:611) - out3.x3_sim(501:611)';
% q11 = var(residui);
% residui_corr = T21V_v2(3,501:611)- out3.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501:611) - out3.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q3 = diag([q11,q22,q33]);
% 
% 
% t_end = Test_21V(1,end);
% out4 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(Test_21V(2,:),Test_21V(1,:));
% residui = Test_21V(2,501-0.05/0.002:611-0.05/0.002) - out4.x1_sim(501:611)';
% q11 = var(residui);
% residui_corr = Test_21V(3,501-0.05/0.002:611-0.05/0.002)- out4.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501-0.05/0.002:611-0.05/0.002) - out4.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q4 = diag([q11,q22,q33]);
% 
% t_end = T22_5V(1,end);
% out5 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(T22_5V(2,:),T22_5V(1,:));
% residui = T22_5V(2,501-0.05/0.002:611-0.05/0.002) - out5.x1_sim(501:611)';
% q11 = var(residui);
% residui_corr = T22_5V(3,501-0.05/0.002:611-0.05/0.002)- out5.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501-0.05/0.002:611-0.05/0.002) - out5.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q5 = diag([q11,q22,q33]);
% 
% 
% t_end = T21V_v2(1,end);
% out6 = sim("model_non_lineare2023b.slx");
% x3_mes = gradient(T21V_v2(2,:),T21V_v2(1,:));
% residui = T21V_v2(2,501-0.05/0.002:611-0.05/0.002) - out6.x3_sim(501:611)';
% q11 = var(residui);
% residui_corr = T21V_v2(3,501-0.05/0.002:611-0.05/0.002)- out6.x2_sim(501:611)';
% q22 = var(residui_corr);
% residui_vel = x3_mes(501-0.05/0.002:611-0.05/0.002) - out6.x3_sim(501:611)';
% q33 = var(residui_vel);
% Q6 = diag([q11,q22,q33]);
% 
% data_R = Test_9V;
% % Estrazione delle misure
% y1 = data_R(2,:);  % Posizione
% y2 = data_R(3,:);  % Corrente
% 
% % Selezione dei campioni in regime (opzionale)
% % Includi solo i campioni dove il sistema è "fermo", es. ultimi secondi
% % qui selezioniamo gli ultimi 1000 campioni come esempio:
% regime_samples = 3000;
% y1_regime = y1(end-regime_samples+1:end);
% y2_regime = y2(end-regime_samples+1:end);
% 
% % Calcolo delle varianze (assumiamo indipendenza tra canali)
% y1_bar = mean(y1_regime);
% var_y1 = sum((y1_regime - y1_bar).^2)/(length(y1_regime)-1);
% %var_y1 = var(y1_regime);  % '1' = usa N nel denominatore, stimatore ML
% var_y2 = var(y2_regime);
% 
% % Matrice R stimata (diagonale)
% %R = diag([var_y1, var_y2]); %2x2
% R = var_y1;
% 
% data_R2 = Test_12V;
% % Estrazione delle misure
% y1_2 = data_R2(2,:);  % Posizione
% y2_2 = data_R2(3,:);  % Corrente
% 
% % Selezione dei campioni in regime (opzionale)
% % Includi solo i campioni dove il sistema è "fermo", es. ultimi secondi
% % qui selezioniamo gli ultimi 1000 campioni come esempio:
% regime_samples = 3000;
% y1_regime_2 = y1_2(end-regime_samples+1:end);
% y2_regime_2 = y2_2(end-regime_samples+1:end);
% 
% % Calcolo delle varianze (assumiamo indipendenza tra canali)
% y1_bar_2 = mean(y1_regime_2);
% var_y1_2 = sum((y1_regime_2 - y1_bar_2).^2)/(length(y1_regime_2)-1);
% %var_y1 = var(y1_regime);  % '1' = usa N nel denominatore, stimatore ML
% var_y2_2 = var(y2_regime_2);
% 
% % Matrice R stimata (diagonale)
% %R = diag([var_y1, var_y2]); %2x2
% R2 = var_y2;
% 
% data_R3 = Test_15V;
% % Estrazione delle misure
% y1_3 = data_R3(2,:);  % Posizione
% y2_3 = data_R3(3,:);  % Corrente
% 
% % Selezione dei campioni in regime (opzionale)
% % Includi solo i campioni dove il sistema è "fermo", es. ultimi secondi
% % qui selezioniamo gli ultimi 1000 campioni come esempio:
% regime_samples = 3000;
% y1_regime_3 = y1_3(end-regime_samples+1:end);
% y2_regime_3 = y2_3(end-regime_samples+1:end);
% 
% % Calcolo delle varianze (assumiamo indipendenza tra canali)
% y1_bar_3 = mean(y1_regime_3);
% var_y1_3 = sum((y1_regime_3 - y1_bar_3).^2)/(length(y1_regime_3)-1);
% %var_y1 = var(y1_regime);  % '1' = usa N nel denominatore, stimatore ML
% var_y2_3 = var(y2_regime_3);
% 
% % Matrice R stimata (diagonale)
% %R = diag([var_y1, var_y2]); %2x2
% R3 = var_y2_3;
% 
% data_R4 = Test_18V;
% % Estrazione delle misure
% y1_4 = data_R4(2,:);  % Posizione
% y2_4 = data_R4(3,:);  % Corrente
% 
% % Selezione dei campioni in regime (opzionale)
% % Includi solo i campioni dove il sistema è "fermo", es. ultimi secondi
% % qui selezioniamo gli ultimi 1000 campioni come esempio:
% regime_samples = 3000;
% y1_regime_4 = y1_4(end-regime_samples+1:end);
% y2_regime_4 = y2_4(end-regime_samples+1:end);
% 
% % Calcolo delle varianze (assumiamo indipendenza tra canali)
% y1_bar_4 = mean(y1_regime_4);
% var_y1_4 = sum((y1_regime_4 - y1_bar_4).^2)/(length(y1_regime_4)-1);
% %var_y1 = var(y1_regime);  % '1' = usa N nel denominatore, stimatore ML
% var_y2_4 = var(y2_regime_4);
% Q_prova = diag([0.00256, 0.054, 0]);
Q_prova = diag([0.00001, 0.4, 0]);

% Matrice R stimata (diagonale)
%R = diag([var_y1, var_y2]); %2x2
% R4 = var_y2_4;
% R_ds = 8e-7;
R_ds = 2e-5;
                          
L_kf = lqr(A.', C.', Q_prova, R_ds).';
poli_obs = eig(A-L_kf*C);

A_ob = A - L_kf*C;
B_ob = [ B - L_kf*D, L_kf];
C_ob = eye(n);
D_ob = zeros(n, m+p);