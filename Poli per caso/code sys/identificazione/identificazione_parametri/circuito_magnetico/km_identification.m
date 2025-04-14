clear
close all
clc

%%
%per Windows
addpath('..\..\..\function');
add_data('..\..\..\data\Step Test\Step Test with ball')
add_data('..\..\..\data\Step Test\Step Test without ball')
add_data('..\..\..\data\Step Test\04_04_2025')

run('..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%per Mac
% addpath('../../../function');
% add_data('../../../data/Step Test/Step Test with ball')
% add_data('../../../data/Step Test/Step Test without ball')
% add_data('../../../data/Step Test/04_04_2025')
% 
% run('../../../Model_Parameter.m')
%% identification parameter
x0 = [0, 0, 0]';
k_mag0 = 6.5308e-5;
Ts_FFD = 2e-3;
Tend_FFD = 2;

%% identification:
soglia=0.5e-3;
soglia2 = 11e-3;
u = 21;
indice_scalino = find(T21V(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T21V(2,:) > soglia2, 1, 'first');
t_meas = T21V(1,indice_scalino:indice_scalino2);
measure = T21V(2,indice_scalino:indice_scalino2);

% out = FFD(Ts_FFD,Tend_FFD,x0,u,theta);
% indice_scalino3 = find(out(2,:) > soglia2, 1, 'first');
% indice_scalino4 = find(out(2,:) > soglia4, 1, 'first');
% t_model = out(1,indice_scalino:indice_scalino2);
% model = out(2,indice_scalino:indice_scalino2);


k_mag_est_21 = identification_km(k_mag0,x0, u, Tend_FFD, theta, T21V(:, indice_scalino:indice_scalino2), Ts_FFD, 'Test 21V');

u = 21.5;
indice_scalino = find(T21_5V(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T21_5V(2,:) > soglia2, 1, 'first');
k_mag_est_21_5 = identification_km(k_mag0,x0, u, Tend_FFD, theta, T21_5V(:, indice_scalino:indice_scalino2), Ts_FFD, 'Test 21.6V');
u = 22;
indice_scalino = find(T22V(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T22V(2,:) > soglia2, 1, 'first');
k_mag_est_22 = identification_km(k_mag0,x0, u, Tend_FFD, theta, T22V(:, indice_scalino:indice_scalino2), Ts_FFD, 'Test 21.9V');
u = 22;
indice_scalino = find(T22V_v2(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T22V_v2(2,:) > soglia2, 1, 'first');
k_mag_est_22 = identification_km(k_mag0,x0, u, Tend_FFD, theta, T22V_v2(:, indice_scalino:indice_scalino2), Ts_FFD, 'Test 21.9V');
k_mag_est_21
k_mag_est_21_5
k_mag_est_22
% k_mag_est_23
k_mag_est = mean([k_mag_est_21, k_mag_est_21_5, k_mag_est_22])