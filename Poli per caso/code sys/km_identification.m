clear
close all
clc

%%
addpath('function');
add_data('data/Step Test/Step Test with ball')
add_data('data/Step Test/Step Test without ball')

run('Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%% identification parameter
x0 = [0, 0, 0]';
u = 21; % volt 
k_mag0 = 6.5308e-5;
Ts_FFD = 2e-3;
Tend_FFD = 2;

%% identification

k_mag_est_21 = identification_km(k_mag0,x0, u, Tend_FFD, theta, Test_21V(:, 501:1001), Ts_FFD, 'Test 21V');
u = 21.3;
k_mag_est_21_3 = identification_km(k_mag0,x0, u, Tend_FFD, theta, Test_21_3V(:, 501:1001), Ts_FFD, 'Test_21.3V');
u = 21.6;
k_mag_est_21_6 = identification_km(k_mag0,x0, u, Tend_FFD, theta, Test_21_6V(:, 501:1001), Ts_FFD, 'Test 21.6V');
u = 21.9;
k_mag_est_21_9 = identification_km(k_mag0,x0, u, Tend_FFD, theta, Test_21_9V(:, 501:1001), Ts_FFD, 'Test 21.9V');
u=23;
k_mag_est_23 = identification_km(k_mag0,x0, u, Tend_FFD, theta, Test_23V(:, 501:1001), Ts_FFD, 'Test 23V');
k_mag_est_21
k_mag_est_21_3
k_mag_est_21_6
k_mag_est_21_9
k_mag_est_23
k_mag_est = mean([k_mag_est_21, k_mag_est_21_3, k_mag_est_21_6, k_mag_est_21_9, k_mag_est_23])