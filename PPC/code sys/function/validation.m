function [amplitude, phase] = validation(test, volt, omega)

t = test(1,:);

for i=0:0.002:length(t)
    input(1, i) = volt*sin(omega*i);
end

ind0 = floor(2/0.002) + 1;
% Estrarre il segmento del segnale dopo l'istante
test_cut=test(3,ind0:end);
% Calcolare il massimo del segmento
max_val1 = max(test_cut);
X1 = fft(input);
plot(t, abs(X1/length(t)))
X2 = fft(test_cut');

% Calcolo della fase di ciascun segnale
fase1 = angle(X1);
fase2 = angle(X2);

% La differenza di fase tra i segnali � la differenza tra le fasi
diff_fase = fase1 - fase2;

% La differenza di fase pu� essere normalizzata per evitare discontinuit�
diff_fase = unwrap(diff_fase);  % Correzione per eventuali discontinuit� di fase

% Visualizza la differenza di fase
figure;
plot(diff_fase);
title('Differenza di fase tra i due segnali');
xlabel('Indice di frequenza');
ylabel('Differenza di fase (radians)');
    
