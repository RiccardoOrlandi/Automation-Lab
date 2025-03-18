%% Model Parameters

%offset:
offset_corrente_volt = -0.0166; %[V]
offset_posizione_volt = 1.2074; %[V]
Kb = 0.0027; %[m/V] 
%other param:
k_aero = 0;
k_mag = 6.5308e-5; % Nm^2/A^2   assumiamo costante ma potremmo validarlo considerando  l'area calcolabile tra dai dati del datasheet
m = 0.0657; % kg
y0 = 0.0086; % m
Rs = 1; % Ohm
Rtot = 9.089;
Lc = 0.3545; % H

theta = [k_aero, k_mag, m, y0, Rtot, Lc]';