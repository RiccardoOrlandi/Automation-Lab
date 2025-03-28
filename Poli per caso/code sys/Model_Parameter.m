%% Model Parameters

% other param:
k_aero = 0;
k_mag = 1.0461e-05; % Nm^2/A^2
m = 0.0657; % kg
y0 = 0.0086; % m
Rs = 1; % Ohm
Rtot = 9.7585;
Lc = 0.3708; % H

theta = [k_aero, k_mag, m, y0, Rtot, Lc]';