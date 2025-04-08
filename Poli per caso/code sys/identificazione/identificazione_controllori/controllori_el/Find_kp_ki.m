clc
clear
close all

%%
%per Windows
% run('..\..\..\Model_Parameter.m')

%per Mac
run('../../../Model_Parameter.m')

% System transfer function
s = tf('s');
G = 1 / (Lc*s + Rtot);

% Desired pole location for desired settling time and overshoot
zeta = 0.69;    % Damping ratio for <6% overshoot
omega_n = 5.8;   % Natural frequency for <1s settling time

% Desired closed-loop pole location (real part of the pole)
desired_pole = -zeta * omega_n + 1i * omega_n * sqrt(1 - zeta^2);

% PI controller: Kp + Ki/s
% Start by tuning the PI controller using manual or automated methods
Kp = 50;    % Initial guess for proportional gain
Ki = 10;    % Initial guess for integral gain

% Create the PI controller
PI = Kp + Ki / s;

% Closed-loop transfer function
T = feedback(G * PI, 1);

% Plot the step response to check transient performance
step(T);
title('Closed-loop Step Response');

% Check overshoot and settling time
info = stepinfo(T);

% Display performance metrics
disp(['Overshoot: ', num2str(info.Overshoot), '%']);
disp(['Settling Time: ', num2str(info.SettlingTime), ' seconds']);