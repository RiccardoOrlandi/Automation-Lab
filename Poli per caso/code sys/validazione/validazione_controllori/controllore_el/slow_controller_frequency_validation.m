clear
close all
clc 

%%
%per Windows 
% addpath('..\..\..\function')
% add_data_volt('..\..\..\data\test_controllore\controllore_el\controllore_lento\Sine_test\04_04_2025');
% run('..\..\..\Model_Parameter.m')

%per Mac
addpath('../../../function')
add_data_volt('../../../data/test_controllore/controllore_el/controllore_lento/Sine_test/04_04_2025');
run('../../../Model_Parameter.m')
%% Model Parameters

kp = 0.15;
ki = 104;
kd = 0;
% dt = 0:0.002:T10V_120radS(1,end);
% input_voltage = 0.03*sin(120*dt);
% 
% figure();
% hold on;
% plot(dt,input_voltage);
% plot(dt,T10V_120radS(3,:));
% grid on
% hold off

%% Electric Model

s = tf('s');
sys_el = tf(1, [Lc, Rtot]);
polo = Rtot/Lc;

controller = kp + ki/s+ kd*s;

sys_cl = feedback(controller*sys_el, 1);
freq_max = 1000;
f = 1:0.1:freq_max; % Vettore di frequenze lineare
[mag,phase, omega] = bode(sys_cl, f); % Calcolo del modulo e della fase

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

%% T10V_8radS
omega = 8;
[mag1, phase1] = prova(0.95, 0.1, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_10radS
omega = 10;
[mag1, phase1] = prova(0.895, 0.1, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_12radS
omega = 12;
[mag1, phase1] = prova(0.83, 0.1, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_20radS
omega = 20;
[mag1, phase1] = prova(0.525, 0.09, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_30radS
omega = 30;
[mag1, phase1] = prova(0.285, 0.075, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_50radS
omega = 50;
[mag1, phase1] = prova(0.117, 0.05, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_90radS
omega = 90;
[mag1, phase1] = prova(0.039, 0.03, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% T10V_120radS
omega = 120;
[mag1, phase1] = prova(0.024, 0.024, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];