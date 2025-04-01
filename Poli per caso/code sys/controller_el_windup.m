clc;
clear;
close all;

%% Parametri del modello
run('Model_Parameter.m');

%% Controllore del circuito elettrico
s = tf('s');
polo = Rtot/Lc;
tau = 1/polo;
sys = tf(1, [Lc Rtot]);

%% Parametri del controllore PID
kp = 46.0161;
ki = 2117.9265;
kd = 0;
controller = kp + ki/s + kd*s;

%% Sistema con feedback
sys_cl = feedback(controller*sys, 1);

%% Aggiunta della saturazione e Anti-Windup
sat_limit = 10; % Limite di saturazione per il controllo
K_aw = 100; % Guadagno Anti-Windup

% Definizione della funzione di saturazione
sat = @(u) min(max(u, -sat_limit), sat_limit); 

% Funzione del controllore con Anti-Windup
% Variabili di stato: integratore del controllore
dt = 0.01; % Passo temporale per la simulazione

% Simulazione del sistema con Anti-Windup
time = 0:dt:10; % Tempo di simulazione
u = zeros(size(time)); % Segnale di controllo
e = zeros(size(time)); % Errore
u_sat = zeros(size(time)); % Segnale di controllo saturato
u_ideal = zeros(size(time)); % Segnale di controllo ideale
integral_term = zeros(size(time)); % Termini dell'integratore

% Supponiamo un riferimento unitario
r = ones(size(time));

% Ingresso del sistema (riferimento)
input_signal = r;

% Simulazione del sistema con l'uscita
[y, t_out] = lsim(sys_cl, input_signal, time);  % Ottieni l'uscita del sistema

% Ciclo per simulare il comportamento del controllore con anti-windup
for i = 2:length(time)
    % Calcola errore (riferimento - uscita del sistema)
    e(i) = r(i) - y(i);  % Calcola l'errore

    % Calcolo del segnale di controllo ideale
    u_ideal(i) = kp * e(i) + ki * integral_term(i-1) + kd * (e(i) - e(i-1))/dt;

    % Saturazione del segnale di controllo
    u_sat(i) = sat(u_ideal(i));

    % Anti-Windup: calcola la retroazione correttiva
    delta_u_aw = K_aw * (u_ideal(i) - u_sat(i));

    % Aggiorna lo stato integrale con il termine di retroazione anti-windup
    integral_term(i) = integral_term(i-1) + e(i) * dt + delta_u_aw * dt;

    % Memorizza il segnale di controllo saturato
    u(i) = u_sat(i);
end

% Risultati della simulazione
figure;
subplot(3,1,1);
plot(time, u, 'LineWidth', 1.5);
title('Segnale di Controllo (U)');
xlabel('Tempo (s)');
ylabel('U');
grid on;

subplot(3,1,2);
plot(time, e, 'LineWidth', 1.5);
title('Errore di Controllo (E)');
xlabel('Tempo (s)');
ylabel('Errore');
grid on;

subplot(3,1,3);
plot(time, u_sat, 'LineWidth', 1.5);
title('Segnale di Controllo Saturato (U_{sat})');
xlabel('Tempo (s)');
ylabel('U_{sat}');
grid on;

%% Analisi della risposta in frequenza
figure;
bode(sys);
hold on;
grid on;
bode(controller*sys);
legend('Sistema', 'Controllore con Anti-Windup');
