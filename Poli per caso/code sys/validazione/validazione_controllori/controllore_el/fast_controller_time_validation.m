clear
clc
close all

%%
%per Windows
%run('..\..\..\Model_Parameter.m')

%per Mac
run('../../../Model_Parameter.m')
addpath('../../../function/')
add_data_volt('../../../data/test_controllore/controllore_el/controllore_veloce/step_test/25_03_2025');

%% controllore del circuito elettrico

s = tf('s');
polo = Rtot/Lc;
tau = 1/polo;
sys = tf(1, [Lc Rtot]);

%% primo test: wc=130rad;pm=80,
kp = 46.0161;
ki = 2117.9265;
kd = 0;


controller = kp + ki/s+ kd*s;

sys_cl = feedback(controller*sys, 1);
[y, t] = step(sys_cl);
plot_Latex(t, y, 'Time [s]', 'Current [A]', 'Step Response', [0 1.2]);
% %% secondo test
% kp2 = 29.924;
% ki2 = 37.79*29.924;
% % controller_el2 = kp2 + ki2/s;
%% Plot per 6V
% Parametri temporali
dt = 0.002;  % intervallo di tempo (2 ms)
T = size(C_el_6V(1,:),2);  % numero di campioni nei dati sperimentali
t = (T-1)*0.002;  % vettore temporale basato sui campioni e il passo temporale

tfin = 1.2;
Nfin = round(tfin/0.002,0);
tin = 0.95;
Nin = round(tin/0.002,0);

u = 6/Rtot;
out = sim('validation_time_controller.slx');
% Plot
figure()
hold on
plot_Latex(C_el_6V(1,Nin:Nfin)-tin, C_el_6V(3, Nin:Nfin), 'Time [s]', 'Current [A]', 'Test 6V', [0 2.3]);
plot_Latex(out.tout(1:end-Nin,1)', out.Modello(Nin+1:Nfin+1, 1)', 'Time [s]', 'Current [A]', 'Test 6V', [0 2.3]);
% plot(out.tout(1:end-Nin,1)', out.Modello2(Nin+1:Nfin+1, 1)', 'g--', 'DisplayName', 'Modello teorico 2')
grid on
legend('Test', 'Model')
grid on
hold off
xlim([0, (tfin-tin)]);

u = 10/Rtot;
out = sim('validation_time_controller.slx');
% Plot
figure()
hold on
plot_Latex(C_el_10V(1,Nin:Nfin)-tin, C_el_10V(3, Nin:Nfin), 'Time [s]', 'Current [A]', 'Test 10V', [0 2.3])
plot_Latex(out.tout(1:end-Nin,1)', out.Modello(Nin+1:Nfin+1, 1)', 'Time [s]', 'Current [A]', 'Test 10V', [0 2.3])
% plot(out.tout(1:end-Nin,1)', out.Modello2(Nin+1:Nfin+1, 1)', 'g--', 'DisplayName', 'Modello teorico 2')
grid on
legend('Test', 'Model')
grid on
hold off
xlim([0, (tfin-tin)]);

u = 15/Rtot;
out = sim('validation_time_controller.slx');
% Plot
figure()
hold on
plot_Latex(C_el_15V(1,Nin:Nfin)-tin, C_el_15V(3, Nin:Nfin), 'Time [s]', 'Current [A]', 'Test 15V', [0 2.3])
plot_Latex(out.tout(1:end-Nin,1)', out.Modello(Nin+1:Nfin+1, 1)', 'Time [s]', 'Current [A]', 'Test 15V', [0 2.3])
% plot(out.tout(1:end-Nin,1)', out.Modello2(Nin+1:Nfin+1, 1)', 'g--', 'DisplayName', 'Modello teorico 2')
grid on
legend('Test', 'Model')
grid on
hold off
xlim([0, (tfin-tin)]);


u = 20/Rtot;
out = sim('validation_time_controller.slx');
% Plot
figure()
hold on
plot_Latex(C_el_20V(1,Nin:Nfin)-tin, C_el_20V(3, Nin:Nfin), 'Time [s]', 'Current [A]', 'Test 20V', [0 2.3])
plot_Latex(out.tout(1:end-Nin,1)', out.Modello(Nin+1:Nfin+1, 1)', 'Time [s]', 'Current [A]', 'Test 20V', [0 2.3])
% plot(out.tout(1:end-Nin,1)', out.Modello2(Nin+1:Nfin+1, 1)', 'g--', 'DisplayName', 'Modello teorico 2')
grid on
legend('Test', 'Model')
grid on
hold off
xlim([0, (tfin-tin)]);


