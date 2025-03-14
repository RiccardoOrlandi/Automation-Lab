%% Model Parameters

k_aero = 0;
k_mag = 6.5308e-5; % Nm^2/A^2   assumiamo costante ma potremmo validarlo considerando  l'area calcolabile tra dai dati del datasheet
m = 0.0657; % kg
y0 = 0.0086; % m
Rs = 1; % Ohm
%Rc = 8.14;%Ohm
Rc = 8.89;

%Rc2 = 9.14
%Rc3 = 8.35
Rtot = Rs + Rc; %Ohm
Lc = 0.3537; % H
%Lc PDB = 0.2934
%Lc2 = 0.2328
%Lc3 = 0.3626

theta = [k_aero, k_mag, m, y0, Rtot, Lc]';