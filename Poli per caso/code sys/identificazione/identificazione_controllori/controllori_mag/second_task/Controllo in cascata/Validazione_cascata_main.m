clear
clc
close all

addpath('..\..\..\..\..\function')

run('Controllore_testato.m');
close all
validazione = 'Validazione_cascata';
add_data_volt('Dati_acquisiti')

controller_mag = tf(num_mag_C2, den_mag_C2);
sys = feedback(controller_mag*G2_2, 1);
figure()
bode(sys)
grid on


model = 'Validazione_cascata';  % Assicurati che sia il nome giusto

% Carica il modello e abilita Fast Restart
load_system(model);
set_param(model, 'FastRestart', 'off');

% Crea oggetto di simulazione
simIn = Simulink.SimulationInput(model);

% % Imposta parametri della simulazione
% simIn = setModelParameter(simIn, ...
%     'StopTime', '10', ...
%     'SolverType', 'Fixed-step', ...
%     'Solver', 'ode4', ...
%     'FixedStep', '0.01');
set_param(model, 'FastRestart', 'on');


%% VALIDAZIONE FREQUENZA
simIn = setVariable(simIn, 'amp', 0.001);
simIn = setVariable(simIn, 'freq_rad', 0.1);
out = sim(simIn);
test = test_sin_0_1rad_phi2_2566_7_sec;
figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.001);
simIn = setVariable(simIn, 'freq_rad', 1);
out = sim(simIn);
test = test_sin_1rad_phi2_2566_7_sec;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.0004);
simIn = setVariable(simIn, 'freq_rad', 10);
out = sim(simIn);
test = test_sin_10rad_phi2_2566_7_sec;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off
%%
simIn = setVariable(simIn, 'amp', 0.001);
simIn = setVariable(simIn, 'freq_rad', 15);
out = sim(simIn);
test = test_sin_15rad_phi2_2566_7_sec;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.0005);
simIn = setVariable(simIn, 'freq_rad', 20);
out = sim(simIn);
test = test_sin_20rad_phi2_2566_7_sec_amp0_5mm;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.0001);
simIn = setVariable(simIn, 'freq_rad', 80);
out = sim(simIn);
test = test_sin_80rad_phi2_2566_7_sec_amp0_1mm;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.0001);
simIn = setVariable(simIn, 'freq_rad', 90);
out = sim(simIn);
test = test_sin_90rad_phi2_2566_7_sec_amp0_1mm;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%%
simIn = setVariable(simIn, 'amp', 0.0002);
simIn = setVariable(simIn, 'freq_rad', 110);
out = sim(simIn);
test = test_sin_110rad_phi2_2566_7_sec_amp0_1mm;

figure()
plot(out.tout, out.freq_sim(:,1))
hold on
plot(test(1, :), test(2, :))
grid on
hold off

%% VALIDAZIONE TEMPO
out = sim(simIn);
figure()
plot(out.tout, out.step_sim(:,1))
hold on
plot(test_step_v1(1, :), test_step_v1(2, :))
plot(test_step_v2(1, :), test_step_v2(2, :))
plot(test_step_v3(1, :), test_step_v3(2, :))
grid on
hold off



% (eventualmente) disattiva Fast Restart
set_param(model, 'FastRestart', 'off');

