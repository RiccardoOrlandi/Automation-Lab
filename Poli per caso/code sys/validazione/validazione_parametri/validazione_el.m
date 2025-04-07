clear
close all
clc

%%
%per Windows
% addpath('..\..\function');
% add_data('..\..\data\Step Test\Step Test with ball')
% add_data('..\..\data\Step Test\Step Test without ball')
% add_data('..\..\data\Step Test\18_03_2024\with_ball')
% add_data('..\..\data\Step Test\18_03_2024\without_ball')
% add_data('..\..\data\Step Test\18_03_2025_v2\with_ball')
% add_data('..\..\data\Step Test\18_03_2025_v2\without_ball')
% add_data('..\..\data\Step Test\04_04_2025')
% run('..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%per Mac
addpath('../../function');
add_data('../../data/Step Test/Step Test with ball')
add_data('../../data/Step Test/Step Test without ball')
add_data('../../data/Step Test/18_03_2024/with_ball')
add_data('../../data/Step Test/18_03_2024/without_ball')
add_data('../../data/Step Test/18_03_2025_v2/with_ball')
add_data('../../data/Step Test/18_03_2025_v2/without_ball')
add_data('../../data/Step Test/04_04_2025')
run('../../Model_Parameter.m')

%% Numerical Integration
t0 = 0;
tfin = 0.3;
x0 = [0, 0, 0]';
u = 21; % volt 

% Simulation with ode45
%[t, x] = ode45(@(t, x) model(t, x, u, theta), [t0 tfin], x0);

% Simulation using Forward Finite Differences
Ts_FFD      =       2e-3;
Tend_FFD    =       10;
[t_FFD, x_FFD, sim_FFD ] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
%~

%%
figure()
plot(t_FFD+1, x_FFD(1,:))
hold on
%plot_data(Test_21V, 'position', 0, Tend_FFD)
plot(Test_21V(1, :), Test_21V(2, :))
grid on
title('Position')
legend('ideal','real');
hold off


figure()
plot(t_FFD+1, x_FFD(2,:))
hold on
%plot_data(Test_21V, 'current', 0, Tend_FFD)
plot(Test_21V(1, 501:end), Test_21V(3, 501:end))
grid on
title('Current')

modello= zeros(1, length(Test_21V));
for i = 1:length(Test_21V)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*Test_21V(1, i)));
end
plot(Test_21V(1, :)+1, modello(1, :))
plot(Test_wb_21V(1, :), Test_wb_21V(3, :))

legend('ideal FFD','real with ball', 'ideal exact', 'real without ball');
