%% Model Parameters

% other param:
k_aero = 0;
k_mag = 9e-05;%2.4405e-05; % Nm^2/A^2
m = 0.0657; % kg
y0 = 0.012; % m
Rs = 1; % Ohm
Rtot = 9.7585;
Lc = 0.3708; % H
g = 9.81;
theta = [k_aero, k_mag, m, y0, Rtot, Lc]';