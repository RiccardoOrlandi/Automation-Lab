clear
close all
clc


addpath('function');
load('C:\Users\Student\Desktop\Automation-Lab-main\Automation-Lab-main\PPC\data\Step Test\Step Test with ball\Test_21V.mat');
%load('C:\Users\Student\Desktop\Poli Per Caso\data\Step Test\Step Test
%without ball\Test_3V.mat');
%load('C:\Users\Student\Desktop\Poli Per Caso\data\Sine Test\S_Test_10V_10HZ.mat')
%% Model Parameters

k_aero = 0;
k_mag = 6.5308e-5; % Nm^2/A^2   assumiamo costante ma potremmo validarlo considerando  l'area calcolabile tra dai dati del datasheet
m = 0.0657; % kg
y0 = 0.0086; % m
Rs = 1; % Ohm
Rc = 9.14; %Ohm
Rtot = Rs + Rc; %Ohm
Lc = 0.2934; % H

theta = [k_aero, k_mag, m, y0, Rtot, Lc]';

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

%% Electric Model

sys_el = tf(1, [Lc, Rtot]);
bode(sys_el)
grid on
polo = Rtot/Lc;
freq_max = 100;
f = 1:freq_max; % Vettore di frequenze lineare
[H, w] = bode(sys_el, f); % Calcolo del modulo e della fase
H=reshape(H, [1,freq_max]);
figure()
%plot(f, 20*log10(abs(H))); % Grafico del modulo su scala logaritmica
plot(f, 10*abs(H)); % Grafico del modulo su scala lineare
grid on
figure()
plot(f, angle(H)*180/pi); % Grafico della fase su scala lineare
grid on;
xlabel('Frequenza [rad/s]');
ylabel('Ampiezza [lineare] e Fase [°]');
legend('Ampiezza', 'Fase');


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

validation(S_Test_wb_10V_30radS,10, 30)

