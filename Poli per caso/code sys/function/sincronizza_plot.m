function sincronizza_plot(T, u, nome_test, soglia, Ts, Tend, x0, theta)
    t = 0:Ts:(Tend/Ts-1)*Ts;
    indice_scalino = find(T(2,:) > soglia, 1, 'first');
    [t, x, y] = FFD(Ts, Tend, x0, u, theta);
    indice_scalino2 = find(y(2,:) > soglia, 1, 'first');
    
    t_exp = t(indice_scalino:indice_scalino+50) - t(indice_scalino);
    t_mod = t(indice_scalino2:indice_scalino2+50) - t(indice_scalino2);
    
    if isempty(indice_scalino2)
    warning('Nessuno scalino trovato nel modello per %g V', u);
    return;
    figure();
    hold on;
    plot(t_exp, T(2, indice_scalino:indice_scalino+50), 'b-', 'LineWidth', 1);
    plot(t_mod, y(2, indice_scalino2:indice_scalino2+50), 'r-', 'LineWidth', 1);
    grid on;
    title(['Position (' num2str(u) 'V) - ' nome_test]);
    legend(['Test ' num2str(u) 'V'], 'Modello');
    xlabel('Tempo rispetto al punto di scalino [s]');
    ylabel('Posizione');
    hold off;
end