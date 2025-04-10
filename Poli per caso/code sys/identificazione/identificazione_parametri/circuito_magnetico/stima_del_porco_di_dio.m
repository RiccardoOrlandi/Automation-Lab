clear
close all
clc

%% Caricamento dati
addpath('../../../function');
add_data('../../../data/Step Test/Step Test with ball')
add_data('../../../data/Step Test/Step Test without ball')
add_data('../../../data/Step Test/04_04_2025')

run('../../../Model_Parameter.m')

%% Parametri iniziali
x0 = [0, 0, 0]';
Ts_FFD = 2e-3;
Tend_FFD = 2;

%% Soglia per l'individuazione del scalino
soglia = 0.5e-3;
soglia2 = 11e-3;

%% Test con 21V
u = 21;
indice_scalino = find(T21V(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T21V(2,:) > soglia2, 1, 'first');
out_test = T21V(2, indice_scalino:indice_scalino2);  % Dati fino al primo indice di scalino
t_test = T21V(1, indice_scalino:indice_scalino2);

% Esegui il modello ideale con la funzione FFD
[~, ~, out] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
indice_scalino=find(out(2,:) > soglia, 1, 'first');
indice_scalino2=find(out(2,:) > soglia2, 1, 'first');
t = out(1,indice_scalino:indice_scalino2);
y = out(2,indice_scalino:indice_scalino2);

%% Test con 21.5V
u = 21.5;
indice_scalino = find(T21_5V(2,:) > soglia, 1, 'first');
y1 = T21_5V(2, 1:indice_scalino);  % Dati fino al primo indice di scalino

% Esegui il modello ideale con la funzione FFD
[~, ~, out] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
y2 = out(2, 1:indice_scalino);  % Risultati del modello fino al primo indice di scalino

% Salvataggio variabili per il test 21.5V
save('test_21_5V.mat', 'T21_5V', 'y1', 'y2');

%% Test con 22V
u = 22;
indice_scalino = find(T22V(2,:) > soglia, 1, 'first');
y1 = T22V(2, 1:indice_scalino);  % Dati fino al primo indice di scalino

% Esegui il modello ideale con la funzione FFD
[~, ~, out] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
y2 = out(2, 1:indice_scalino);  % Risultati del modello fino al primo indice di scalino

% Salvataggio variabili per il test 22V
save('test_22V.mat', 'T22V', 'y1', 'y2');

%% Test con 22V (versione 2)
u = 22;
indice_scalino = find(T22V_v2(2,:) > soglia, 1, 'first');
y1 = T22V_v2(2, 1:indice_scalino);  % Dati fino al primo indice di scalino

% Esegui il modello ideale con la funzione FFD
[~, ~, out] = FFD(Ts_FFD, Tend_FFD, x0, u, theta);
y2 = out(2, 1:indice_scalino);  % Risultati del modello fino al primo indice di scalino

% Salvataggio variabili per il test 22V (versione 2)
save('test_22V_v2.mat', 'T22V_v2', 'y1', 'y2');