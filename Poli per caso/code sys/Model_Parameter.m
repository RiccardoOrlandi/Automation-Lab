%% Model Parameters

% other param:
k_aero = 0;
k_mag =  2.4405e-05; %9.3993e-05;%2.4405e-05; %1.0461e-05; % Nm^2/A^2
m = 0.0657; % kg
y0 = 0.0120; % m
Rs = 1; % Ohm
Rtot = 9.7585;
Lc = 0.3708; % H
g = 9.81;
theta = [k_aero, k_mag, m, y0, Rtot, Lc]';

% sensori
offset_corrente_volt = -0.0166; %[V]
offset_posizione_volt = -0.0231; %[V]
Kb = 0.0033; %[m/V] 
