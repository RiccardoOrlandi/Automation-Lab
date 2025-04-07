clear
close all
clc

%%
%per Windows 
% addpath('..\..\function')
% add_data('..\..\data\Sine Test\precedenti');
% add_data('..\..\data\Sine Test\18_03_2025');
% add_data('..\..\data\Sine Test\25_03_2025');
% run('..\..\Model_Parameter.m')

%per Mac
addpath('../../function')
add_data('../../data/Sine Test/precedenti');
add_data('../../data/Sine Test/18_03_2025');
add_data('../../data/Sine Test/25_03_2025');
run('../../Model_Parameter.m')

%% Model Parameters


dt = 0:0.002:Test_55radS(1,end);
V = 0.15*sin(55*dt);
figure();
hold on;
plot(dt,V);
plot(dt,Test_55radS(3,:));
grid on
hold off

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
[mag1, phase1] = prova(0.71, 0.031, omega,1);

[mag2, phase2] = bode(sys_el, omega);

mag1
mag2
phase1
phase2

Fs = 1/0.002;            % Sampling frequency                    
T = 1/Fs;             % Sampling period       
L = length(S_Test_wb_10V_30radS(1, :));             % Length of signal
t = (0:L-1)*T;        % Time vector
Y = fft(S_Test_wb_10V_30radS(3, :));

P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs/L*(0:(L/2));
figure()

plot(f,P1,"LineWidth",3) 
grid on
title("Single-Sided Amplitude Spectrum of X(t)")
xlabel("f (Hz)")
ylabel("|P1(f)|")

% fase
y = fft(S_Test_wb_10V_30radS(3, :));
z = fftshift(y);

ly = length(y);
f = (-ly/2:ly/2-1)/ly*Fs;
figure()
stem(f,abs(z))
title("Double-Sided Amplitude Spectrum of x(t)")
xlabel("Frequency (Hz)")
ylabel("|y|")
grid

tol = 400;
z(abs(z) < tol) = 0;

theta = angle(z);

figure()
stem(f,theta/pi)
title("Phase Spectrum of x(t)")
xlabel("Frequency (Hz)")
ylabel("Phase/\pi")
grid


results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];


%% S_Test_wb_10V_20radS

%validation(S_Test_wb_10V_20radS, 10, 20);
%prova(0.84, 0.033, 20)

omega = 20;
[mag1, phase1] = prova(0.84, 0.033, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_34_56radS

%validation(S_Test_wb_10V_34_56radS, 10, 34.56);
% prova(0.64, 0.0265, 34.56)

omega = 34.56;
[mag1, phase1] = prova(0.64, 0.0265, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_3_45radS

%validation(S_Test_wb_10V_3_45radS, 10, 3.45);
% prova(1.067, 0.048, 3.45)

omega = 3.45;
[mag1, phase1] = prova(1.067, 0.048, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_40radS

%validation(S_Test_wb_10V_40radS, 10, 40);
% prova(0.584, 0.026, 40)

omega = 40;
[mag1, phase1] = prova(0.584, 0.026, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_test_wb_10V_50radS

%validation(S_test_wb_10V_50radS, 10, 50);
% prova(0.491, 0.024, 50)

omega = 50;
[mag1, phase1] = prova(0.491, 0.024, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_5_4radS

%validation(S_Test_wb_10V_5_4radS, 10, 5.4);
% prova(1.045, 0.04, 5.4)

omega = 5.4;
[mag1, phase1] = prova(1.045, 0.04, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];
%% S_Test_wb_10V_80radS

%validation(S_Test_wb_10V_80radS, 10, 80);
% prova(0.327, 0.016, 80)

omega = 80;
[mag1, phase1] = prova(0.327, 0.016, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% S_Test_wb_10V_345radS

%validation(S_Test_wb_10V_345radS, 10, 345);
% prova(0.076, 0.0054, 345)

omega = 345;
[mag1, phase1] = prova(0.076, 0.0054, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_180radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 180;
[mag1, phase1] = prova(0.161, 0.01, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_300radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 300;
[mag1, phase1] = prova(0.12, 0.0072, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_400radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 400;
[mag1, phase1] = prova(0.078, 0.006, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_55radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 55;
[mag1, phase1] = prova(0.446, 0.022, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_70radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 70;
[mag1, phase1] = prova(0.365, 0.019, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_90radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 90;
[mag1, phase1] = prova(0.28, 0.015, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%%


%% nuovi valori vicino ad wc

disp('Tabella che mostra gli errori percentuali tra valori reali e del modello:')
disp(results)

%% Test_100radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 100;
[mag1, phase1] = prova(0.261, 0.013, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_120radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 120;
[mag1, phase1] = prova(0.218, 0.012, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_130radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 130;
[mag1, phase1] = prova(0.203, 0.011, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_140radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 140;
[mag1, phase1] = prova(0.187, 0.01, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];

%% Test_70radS


%validation(S_Test_wb_10V_30radS, 10, 30);
omega = 70;
[mag1, phase1] = prova(0.365, 0.019, omega,1);

[mag2, phase2] = bode(sys_el, omega);

results = [results num2str(omega) '        ' num2str((mag1-mag2)/mag2*100) '         ' ...
    num2str((phase2-phase1)/phase2*100) newline];