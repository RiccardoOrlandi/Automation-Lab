% Funzione obiettivo per il fitting
function error = objective(k_mag, t, data)
    % Parametri del modello (valori noti)
    theta = [k_aero, k_mag, m, y0, Rtot, Lc];  % Definisci gli altri parametri
    
    % Condizioni iniziali (ad esempio posizione, corrente, velocità iniziale)
    x0 = [0; 0; 0];  % Modifica in base ai tuoi dati iniziali
    
    % Ingresso u (può essere una forza o un altro tipo di ingresso)
    u = data.input;  % Supponiamo che tu abbia anche l'ingresso nel tuo dataset

    % Simulazione del modello
    [~, y_model] = ode45(@(t, x) model(t, x, u, theta), t, x0);
    
    % Calcola l'errore tra i dati misurati e la simulazione
    error = sum((y_model(:, 1) - data.position).^2 + (y_model(:, 2) - data.current).^2);
end

% Inizializzazione dell'ottimizzazione
k_mag_initial = 1;  % Valore iniziale per k_mag
options = optimset('Display', 'iter');  % Opzioni per il solver, mostriamo il progresso

% Eseguiamo l'ottimizzazione
k_mag_opt = fminunc(@(k_mag) objective(k_mag, data.time, data), k_mag_initial, options);

disp(['Il valore stimato di k_{mag} è: ', num2str(k_mag_opt)]);