clc
clear
close all

%%
%per Windows
% run('..\..\..\Model_Parameter.m')

%per Mac
run('../../../Model_Parameter.m')

% Funzione di trasferimento
s = tf('s');
polo = Rtot / Lc;
tau = 1 / polo;
sys = tf(1, [Lc Rtot]);

disp('Funzione di trasferimento:')
disp(sys)

%% Analisi dinamica
fprintf('--- Analisi dinamica ---\n');
fprintf('Polo del sistema: %.4f\n', -polo);
fprintf('Costante di tempo (tau): %.4f s\n', tau);

% Stabilità
if real(pole(sys)) < 0
    fprintf('Sistema stabile.\n');
else
    fprintf('Sistema instabile.\n');
end

% Risposta al gradino per ottenere tempo di salita e assestamento
info = stepinfo(sys);
fprintf('Overshoot: %.2f %%\n', info.Overshoot);
fprintf('Tempo di salita (Rise Time): %.4f s\n', info.RiseTime);
fprintf('Tempo di assestamento (Settling Time): %.4f s\n', info.SettlingTime);

% Margine di guadagno e fase
[GM, PM, Wcg, Wcp] = margin(sys);
fprintf('\n--- Margini di stabilità ---\n');
fprintf('Margine di guadagno: %.2f dB\n', 20*log10(GM));
fprintf('Margine di fase: %.2f gradi\n', PM);
fprintf('Frequenza di crossover in guadagno: %.2f rad/s\n', Wcg);
fprintf('Frequenza di crossover in fase: %.2f rad/s\n', Wcp);

% Spazio di stato per controllabilità e raggiungibilità
[A, B, C, D] = tf2ss(1, [Lc Rtot]);
sys_ss = ss(A, B, C, D);

Co = ctrb(A, B);
Obs = obsv(A, C);

fprintf('\n--- Controllabilità e Osservabilità ---\n');
if rank(Co) == size(A,1)
    fprintf('Sistema completamente controllabile.\n');
else
    fprintf('Sistema NON controllabile.\n');
end

if rank(Obs) == size(A,1)
    fprintf('Sistema completamente osservabile.\n');
else
    fprintf('Sistema NON osservabile.\n');
end

% Plots opzionali
figure;
step(sys); grid on;
title('Risposta al gradino');

figure;
margin(sys); grid on;
title('Diagramma di Bode con margini di stabilità');
