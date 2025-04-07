function plotModel(tvec, y)
    % Funzione per plottare l'output y in funzione del tempo tvec
    %
    % Input:
    %   - tvec: vettore dei tempi
    %   - y: matrice delle uscite (forze) o variabili di stato restituite da FFD

    % Verifica se y ha almeno 2 righe
    if size(y, 1) < 3
        error('La matrice y deve avere almeno 3 righe come restituito da FFD.');
    end

    % Estrai i segnali da plottare
    y1 = y(1, :);  % tempo
    y2 = y(2, :);  % posizione
    y3 = y(3, :);  % corrente

    % Crea il grafico
    figure;
    subplot(2,1,1)
    plot(tvec, y2, 'b', 'LineWidth', 1.5);
    xlabel('Tempo [s]');
    ylabel('Posizione');
    title('Posizione vs Tempo');
    grid on;

    subplot(2,1,2)
    plot(tvec, y3, 'r', 'LineWidth', 1.5);
    xlabel('Tempo [s]');
    ylabel('Corrente');
    title('Corrente vs Tempo');
    grid on;
end