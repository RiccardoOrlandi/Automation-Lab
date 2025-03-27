clear
close all
clc

%%
addpath('function')
add_data_volt('\test_controllore\controllore_el\sine_test\25_03_2025');


%% Model Parameters
run('Model_Parameter.m')
kp = 46;
ki = 2118;
kd = 0;
dt = 0:0.002:C_el_10radS(1,end);
input_voltage = 10*sin(10*dt);
V = [dt', input_voltage'];

T_end = dt(end);
sim('validation_frequency_controller');
disp(size(out.ideal_current'));

figure();
hold on;
plot(dt,out.ideal_current');
plot(dt,C_el_10radS(3,:));
grid on
hold off
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
%% S_Test_wb_10V_30radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 10;
[mag1, phase1] = prova(1.031, 0, omega);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];


%% S_Test_wb_10V_20radS

%validation(S_Test_wb_10V_20radS, 10, 20);
%prova(0.84, 0.033, 20)

omega = 40;
[mag1, phase1] = prova(1.065, 0, omega);

[mag2, phase2] = bode(sys_cl, omega);

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

%% Test_180radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 180;
[mag1, phase1] = prova(0.161, 0.01, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_300radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 300;
[mag1, phase1] = prova(0.12, 0.0072, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_400radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 400;
[mag1, phase1] = prova(0.078, 0.006, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_55radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 55;
[mag1, phase1] = prova(0.446, 0.022, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_70radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 70;
[mag1, phase1] = prova(0.365, 0.019, omega);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];



disp('Tabella che mostra gli errori percentuali tra valori reali e del modello:')
disp(results)