clear
close all
clc

%%
%per Windows
% addpath('..\..\..\function');
% add_data('..\..\..\data\Step Test\Step Test with ball')
% add_data('..\..\..\data\Step Test\Step Test without ball')
% 
% run('..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%per Mac
addpath('../../../function');
add_data('../../../data/Step Test/Step Test with ball')
add_data('../../../data/Step Test/Step Test without ball')
add_data('../../../data/Step Test/04_04_2025')

run('../../../Model_Parameter.m')

% 1. Carica o definisci i dati sperimentali
% Supponiamo che i tuoi dati siano già in una struttura chiamata "data"
% con i campi: time, position, current, input
k_mag= 1e-05;
% Esempio di come potrebbero apparire i dati (puoi sostituirli con i tuoi dati reali)
soglia=0.5e-3;
soglia2 = 11e-3;
u = 21;
indice_scalino = find(T21V(2,:) > soglia, 1, 'first');
indice_scalino2 = find(T21V(2,:) > soglia2, 1, 'first');
data.time = T21V(1,indice_scalino:indice_scalino2);  % Tempo (ad esempio da 0 a 10 secondi)
data.position = T21V(2,indice_scalino:indice_scalino2);  % Posizione misurata (esempio)
data.current = T21V(3,indice_scalino:indice_scalino2);  % Corrente misurata (esempio)
data.input = u;  % Ingresso (se necessario)




% 4. Imposta le opzioni per l'ottimizzazione
options = optimset('Display', 'iter');  % Mostra il progresso durante l'ottimizzazione
% 5. Esegui l'ottimizzazione per trovare il miglior valore di k_mag
k_mag_opt = fminunc(@(k_mag) objective(k_mag, data.time, data), k_mag, options);

% 6. Visualizza il risultato
disp(['Il valore stimato di k_{mag} è: ', num2str(k_mag_opt)]);

% 7. (Opzionale) Puoi anche confrontare il modello con i dati misurati per vedere il fitting
theta_opt = [k_aero, k_mag_opt, m, y0, Rtot, Lc];  % Parametri ottimizzati

% Simulazione del modello con k_mag ottimizzato
x0 = [0; 0; 0];  % Condizioni iniziali
[~, y_model] = ode45(@(t, x) model(t, x, data.input, theta_opt), data.time, x0);

% Visualizza il confronto tra il modello e i dati
figure;
subplot(2,1,1);
plot(data.time, data.position, 'ro', data.time, y_model(:,1), 'b-');
title('Posizione: Dati vs Modello');
legend('Dati', 'Modello');

subplot(2,1,2);
plot(data.time, data.current, 'go', data.time, y_model(:,2), 'b-');
title('Corrente: Dati vs Modello');
legend('Dati', 'Modello');