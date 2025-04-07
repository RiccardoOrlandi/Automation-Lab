function y = variable_sine(t)
    f0 = 1; % Frequenza iniziale (Hz)
    f1 = 10; % Frequenza finale (Hz)
    Tfinal = 10; % Durata della simulazione

    % Frequenza che cresce linearmente da f0 a f1
    freq = f0 + (f1 - f0) * (t / Tfinal);
    
    % Segnale sinusoidale con frequenza variabile
    y = sin(2 * pi * freq * t);
end