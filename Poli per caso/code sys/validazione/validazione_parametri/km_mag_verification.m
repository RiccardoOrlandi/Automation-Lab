clear all
close all
clc

%per Windows
run('..\..\Model_Parameter.m')

addpath('..\..\function')
add_data('..\..\data\Step Test\Step Test with ball');
add_data('..\..\data\Step Test\18_03_2025_v2\with ball');
add_data('..\..\data\Step Test\18_03_2024\with_ball');
add_data('..\..\data\Step Test\04_04_2025')

%per Mac
% run('../../Model_Parameter.m')
% 
% addpath('../../function')
% add_data('../../data/Step Test/Step Test with ball');
% add_data('../../data/Step Tes/18_03_2025_v2/with ball');
% add_data('../../data/Step Test/18_03_2024/with_ball');
%add_data('../../data/Step Test/04_04_2025')

%% mostrare diversi plot
Ts = 0.002;
x0 = [0 0 0]';
Tend = 2;
N = Tend/0.002;

delay = 1/0.002;
N2 = N-delay;

%% Plot per 21_3 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21.3;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21_3V(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21_3V(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (21.3V) - Segnali Sincronizzati');
legend('Test 21.3V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;
%% Plot per 21.6V con sincronizzazione
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21.6;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21_6V(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21_6V(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (21.6V) - Segnali Sincronizzati');
legend('Test 21.6V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;


%% Plot per 22.5 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 22.5;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T22_5V(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T22_5V(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (22.5V) - Segnali Sincronizzati');
legend('Test 22.5V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;

%% Plot per 22 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 22;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T22V_v2(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T22V_v2(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (22V) - Segnali Sincronizzati');
legend('Test 22V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;
%% Plot per T21V_v2 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21V_v2(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21V_v2(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (22V) - Segnali Sincronizzati');
legend('Test 22V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;
%% Plot per T21V_v3 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21V_v3(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21V_v3(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (21V) - Segnali Sincronizzati');
legend('Test 21V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;
%% Plot per T21V_v2 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21V_v2(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21V_v2(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (22V) - Segnali Sincronizzati');
legend('Test 22V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;
%% Plot per T21V_v4 V
t = 0:0.002:(N-1)*0.002; % Vettore dei tempi
u = 21;
soglia = 0.5e-3; % Soglia per trovare il punto di scalino

% Trova l'indice del primo valore che supera la soglia nei dati sperimentali
indice_scalino = find(T21V_v4(2,:) > soglia, 1, 'first');

% Simulazione del modello
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);
s
% Trova l'indice dello scalino nei dati del modello
indice_scalino2 = find(y(2,:) > soglia, 1, 'first');

% Traslazione del tempo per allineare gli scalini a t=0
t_exp = t(indice_scalino:indice_scalino+300) - t(indice_scalino);
t_mod = t(indice_scalino2:indice_scalino2+300) - t(indice_scalino2);

% Plot dei risultati sincronizzati
figure();
hold on;
plot(t_exp, T21V_v4(2, indice_scalino:indice_scalino+300), 'b-', 'LineWidth', 1);
plot(t_mod, y(2, indice_scalino2:indice_scalino2+300), 'r--', 'LineWidth', 1);
grid on;
title('Position (21V) - Segnali Sincronizzati');
legend('Test 21V', 'Modello');
xlabel('Tempo rispetto al punto di scalino [s]');
ylabel('Posizione');
hold off;