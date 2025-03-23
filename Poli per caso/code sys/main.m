clear
close all
clc

addpath('function');
add_data('data/Step Test/Step Test with ball')
add_data('data/Step Test/Step Test without ball')

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
[t_FFD, x_FFD, sim_FFD ] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
%~
%% Chiamata al modello per trovare l'equilibrio
x=zeros(3,1);
zdot=zeros(3,1);
y = zeros(2,1);
G = tf([]);
[zdot, y, G] = model(0, x, 10, theta);
%%

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
    modello(1, i) = 21/Rtot*(1-exp(1)^(-(Rtot/Lc)*Test_21V(1, i)));
end
plot(Test_21V(1, :)+1, modello(1, :))


plot(Test_wb_21V(1, :), Test_wb_21V(3, :))

legend('ideal FFD','real with ball', 'ideal exact', 'real without ball');

%km = Km_nuovo(Test_21V)
k_mag0 = 6.5308e-5;
Tend_FFD =2;
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