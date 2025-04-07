clear all
close all
%%
%per Windows
% run('..\..\Model_Parameter.m')
% 
% addpath('..\..\function')
% add_data('..\..\data\Step Test\Step Test with ball');
% add_data('..\..\data\Step Test\18_03_2025_v2\with ball');
% add_data('..\..\data\Step Test\18_03_2024\with_ball');
% add_data('..\..\data\Step Test\04_04_2025')

%per Mac
run('../../Model_Parameter.m')
addpath('../../function')
add_data('../../data/Step Test/Step Test with ball');
add_data('../../data/Step Tes/18_03_2025_v2/with ball');
add_data('../../data/Step Test/18_03_2024/with_ball');
add_data('../../data/Step Test/04_04_2025');

%% validation of Km on time:
soglia = 0.5e-3;
Ts = 0.002;
x0 = [0 0 0]';
Tend = 7;

sincronizza_plot(T21_3V, 21.3, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);
sincronizza_plot(T21_6V, 21.6, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);
sincronizza_plot(T22_5V, 22.5, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);
sincronizza_plot(T22V_v2, 22, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);
sincronizza_plot(T21V_v2, 21, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);
sincronizza_plot(T21V_v3, 21, 'Segnali Sincronizzati', soglia, Ts, Tend, x0, theta);