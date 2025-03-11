clear
clc
% Ottieni la cartella di lavoro corrente
folder = pwd;
folder = fullfile(folder, '\data\Sine Test');
S_Test_wb_10V_345radS=0;
load('S_Test_wb_10V_345radS.mat')
%%

% Ottieni la cartella di lavoro corrente
folder = pwd;
folder = fullfile(folder, '\data\Sine Test');

% Ottieni una lista di tutti i file .mat nella cartella
files = dir(fullfile(folder, '*.mat'));

% Carica ogni file .mat nel workspace
for k = 1:length(files)
    % Costruisci il percorso completo del file
    filePath = fullfile(folder, files(k).name);
    
    % Carica il file .mat nel workspace
    load(filePath);
    
    % (Facoltativo) Visualizza il nome del file caricato
    disp(['Caricato: ', files(k).name]);
end

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
%% Electric Model
sys_el = tf(1, [Lc, Rtot]);
polo = Rtot/Lc;
freq_max = 1000;
f = 1:0.1:freq_max; % Vettore di frequenze lineare
[mag,phase, omega] = bode(sys_el, f); % Calcolo del modulo e della fase

mag = squeeze(mag);
phase = squeeze(phase);
omega = squeeze(omega);

figure(1)
subplot(2,1,1)
semilogx(omega,20*log10(mag));
grid on
% hold on;
% plot(30, 20*log10(0.07), 'rx', 'MarkerSize', 7, 'LineWidth', 1);  % Aggiungi la "X"
% hold off;
figure(1)
subplot(2,1,2)
semilogx(omega, phase);
% hold on
% plot(30, -49.15, 'rx', 'MarkerSize', 7, 'LineWidth', 1);
% hold off
grid on 

%% S_Test_wb_10V_30radS
test = 32;
volt = 10;
rad = 30;

[amp, deg] = validation(test, volt, omega);