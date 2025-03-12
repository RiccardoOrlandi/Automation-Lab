clear
close all
clc

%%
addpath('function')
add_data('\data\Sine Test');

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

figure(1)
subplot(2,1,2)
semilogx(omega, phase);

grid on 


results = ['rad/s     err%_mag        err%_phase' newline];
%% S_Test_wb_10V_30radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 30;
[mag1, phase1] = prova(0.71, 0.031, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];


%% S_Test_wb_10V_20radS

%validation(S_Test_wb_10V_20radS, 10, 20);
%prova(0.84, 0.033, 20)

omega = 20;
[mag1, phase1] = prova(0.84, 0.033, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_34_56radS

%validation(S_Test_wb_10V_34_56radS, 10, 34.56);
% prova(0.64, 0.0265, 34.56)

omega = 34.56;
[mag1, phase1] = prova(0.64, 0.0265, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_3_45radS

%validation(S_Test_wb_10V_3_45radS, 10, 3.45);
% prova(1.067, 0.048, 3.45)

omega = 3.45;
[mag1, phase1] = prova(1.067, 0.048, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_40radS

%validation(S_Test_wb_10V_40radS, 10, 40);
% prova(0.584, 0.026, 40)

omega = 40;
[mag1, phase1] = prova(0.584, 0.026, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_test_wb_10V_50radS

%validation(S_test_wb_10V_50radS, 10, 50);
% prova(0.491, 0.024, 50)

omega = 50;
[mag1, phase1] = prova(0.491, 0.024, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_5_4radS

%validation(S_Test_wb_10V_5_4radS, 10, 5.4);
% prova(1.045, 0.04, 5.4)

omega = 5.4;
[mag1, phase1] = prova(1.045, 0.04, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_80radS

%validation(S_Test_wb_10V_80radS, 10, 80);
% prova(0.327, 0.016, 80)

omega = 80;
[mag1, phase1] = prova(0.327, 0.016, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_345radS

%validation(S_Test_wb_10V_345radS, 10, 345);
% prova(0.076, 0.0054, 345)

omega = 345;
[mag1, phase1] = prova(0.076, 0.0054, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

disp('Tabella che mostra gli errori percentuali tra valori reali e del modello:')
disp(results)