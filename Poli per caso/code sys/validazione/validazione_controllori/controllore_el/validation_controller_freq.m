clear
close all
clc

%%
%per Windows 
addpath('..\..\..\function')
add_data_volt('..\..\..\data\test_controllore\controllore_el\controllore_veloce\sine_test\25_03_2025');
run('..\..\..\Model_Parameter.m')

%per Mac
%addpath('../../../function')
%add_data_volt('../../../data/test_controllore/controllore_el/controllore_veloce/sine_test/25_03_2025');
%run('../../../Model_Parameter.m')
%% Model Parameters

kp = 46;
ki = 2118;
kd = 0;
dt = 0:0.002:C_el_300radS(1,end);
input_voltage = 10*sin(300*dt);
V = [dt', input_voltage'];

T_end = dt(end);

out = sim('validation_frequency_controller');
disp(size(out.ideal_current'));



figure();
hold on;
plot(dt, out.ideal_current);
plot(dt,input_voltage);

% plot(dt,C_el_140radS(3,:));
grid on
hold off

%% Electric Model

s = tf('s');
sys_el = tf(1, [Lc, Rtot]);
polo = Rtot/Lc;

controller = kp + ki/s+ kd*s;

% sys_cl = feedback(controller*sys_el, 1);
sys_cl = linsys1;
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
%% C_el_10radS
omega = 10;
[mag1, phase1] = prova(1.031, 0.0048, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_20radS



omega = 20;
[mag1, phase1] = prova(1.045, 0.005, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_30radS


omega = 30;
[mag1, phase1] = prova(1.05875, 0.006, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% C_el_40radS


omega = 40;
[mag1, phase1] = prova(1.0625, 0.0067, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_50radS

omega = 50;
[mag1, phase1] = prova(1.055, 0.007, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_90radS


omega = 90;
[mag1, phase1] = prova(0.77, 0.0075, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% C_el_100radS



omega = 100;
[mag1, phase1] = prova(0.72, 0.01, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% C_el_120radS


omega = 120;
[mag1, phase1] = prova(0.675, 0.007, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_129radS

%validation(S_Test_wb_10V_345radS, 10, 345);
% prova(0.076, 0.0054, 345)

omega = 129;
[mag1, phase1] = prova(0.65, 0.0071, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_140radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 140;
[mag1, phase1] = prova(0.58, 0.0072, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_150radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 150;
[mag1, phase1] = prova(0.56, 0.007, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_400radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 400;
[mag1, phase1] = prova(0.22, 0.005, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_300radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 300;
[mag1, phase1] = prova(0.28, 0.007, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_345radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 345;
[mag1, phase1] = prova(0.25, 0.006, omega, Rtot);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];



disp('Tabella che mostra gli errori percentuali tra valori reali e del modello:')
disp(results)


%% C_el_140radS (blu)
omega = 140;
[mag1, phase1] = prova_blu(0.55, 0.0065, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% C_el_150radS (blu)
omega = 150;
[mag1, phase1] = prova_blu(0.52, 0.0069, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];%% C_el_129radS (blu)
%% C_el_120radS (blu)
omega = 120;
[mag1, phase1] = prova_blu(0.62, 0.0063, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];%% C_el_129radS (blu)
%% C_el_300radS (blu)
omega = 300;
[mag1, phase1] = prova_blu(0.24, 0.0034, omega, Rtot);

[mag2, phase2] = bode(sys_cl, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];%% C_el_129radS (blu)




