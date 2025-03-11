clear
close all
clc

addpath('function');
prova = load('C:\Users\Student\Desktop\Automation-Lab-main\Automation-Lab-main\PPC\data\Sine Test\S_Test_wb_10V_30radS.mat');
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
Rc = 8.14;%Ohm
%Rc2 = 9.14
%Rc3 = 8.35
Rtot = Rs + Rc; %Ohm
Lc = 0.3537; % H
%Lc PDB = 0.2934
%Lc2 = 0.2328
%Lc3 = 0.3626

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

