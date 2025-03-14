clear
close all
clc

addpath('function');
add_data('data/Step Test/Step Test with ball')

% add_data('\data\Step Test\Step Test with ball') % funzione che serve per aggiungere i test di questa cartella
                                                % usando un percorso
                                                % relativo 

run('Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello


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
[t_FFD, x_FFD, ~ ] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);


% %% Plot figures
% figure
% plot(t, x(:,1))
% hold on
% plot_data(Test_21V, 'position')
% grid on
% %legend('Position')
% title('position')
% hold off

figure()
plot(t_FFD, x_FFD(1,:))
hold on
plot_data(Test_21V, 'position', 0, Tend_FFD)
grid on
title('Position')
legend('ideal','real');
hold off


figure()
plot(t_FFD, x_FFD(2,:))
hold on
plot_data(Test_21V, 'current', 0, Tend_FFD)
grid on
title('Current')
legend('ideal','real');
hold off





km = Km_nuovo(Test_21V)