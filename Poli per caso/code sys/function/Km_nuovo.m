function [Km,acc]= Km_nuovo(Test)
% Calcolo della costante elettromagnetica Km
% Test_21V: Struct contenente i dati del test
% m: Massa della sfera (costante)
% g: Accelerazione gravitazionale (costante)

g = 9.81;
m = 0.0657;
offset = 0.0236;
k_b = 2.686e-3;

% Estrazione dei dati dalla struct
tempo = Test(1, :);          % Prima riga: tempo
posizione =(Test(2,:)+offset)*k_b; % Seconda riga: posizione       
corrente = Test(3, :);        % Terza riga: corrente


% Parametri per il filtro passa-basso
fc = 10;  % Frequenza di taglio del filtro (Hz)
fs = 1 / mean(diff(tempo))  % Frequenza di campionamento
[b_lp, a_lp] = butter(4, fc / (fs / 2));

% Filtraggio della posizione per ridurre il rumore
posizione_filtrata = filtfilt(b_lp, a_lp, posizione);

% Calcolo della velocità e accelerazione tramite differenziazione numerica
velocita = gradient(posizione_filtrata, tempo);  % Velocità
acc = gradient(velocita, tempo);                % Accelerazione

% Parametri per il filtro passa-banda
f_low = 0.5;    % Frequenza minima del passa-banda (Hz)
f_high = 5;    % Frequenza massima del passa-banda (Hz)
[b_bp, a_bp] = butter(4, [f_low, f_high] / (fs / 2));

% Filtraggio dell'accelerazione per isolare la parte dinamica
acc_filt = filtfilt(b_bp, a_bp, acc);

% Inizializzazione del vettore Km
Km = zeros(1, length(tempo));

y0 = 9e-3;  % Distanza tra la pallina e il traferro (m)

% Calcolo di Km per ogni istante di tempo
for i = 1:length(tempo)
    Km(i) = -m * (acc_filt(i) - g) * (y0 - posizione_filtrata(i))^2 / corrente(i)^2;
end

% Selezione dei dati tra 1 e 2 secondiAAA
indice_selezionati = tempo >= 1.16 & tempo <= 1.21;
tempo_selezionato = tempo(indice_selezionati);
Km_selezionato = Km(indice_selezionati);

% Visualizzazione dei risultati
figure;
plot(tempo_selezionato, Km_selezionato);
title('Stima di Km nel tempo');
xlabel('Tempo [s]');
ylabel('Km [unità]');
grid on;

% Valore medio della stima di Km
Km_medio = mean(Km);

disp(['Valore medio stimato di Km: ', num2str(Km_medio)]);

% Salvataggio dei risultati su file
results.Km = Km;
results.Km_medio = Km_medio;
save('risultati_stima_Km.mat', 'results');
end
