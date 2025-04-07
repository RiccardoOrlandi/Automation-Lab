function [tvec, x_out, y_out] = ModelOde(Ts, Tend, x0, u, theta)
    % Simulazione con ODE45 al posto del metodo a differenze finite
    y0 = theta(4,1);

    % Definizione del tempo
    tvec = 0:Ts:Tend;

    % Risoluzione ODE
    opts = odeset('RelTol',1e-6, 'AbsTol',1e-8);
    [T, X] = ode45(@(t,x) dynWrapper(t, x, u, theta, y0), tvec, x0, opts);

    % Valori finali
    x_out = X';

    % Inizializza y_out in base alla dimensione reale dell'output di model
    [~, y0_sample] = model(0, x0(:), u, theta);
    y_out = zeros(length(y0_sample), length(T));

    for i = 1:length(T)
        [~, y] = model(T(i), X(i,:)', u, theta);  % X(i,:)' è colonna
        y_out(:,i) = y;
    end

    tvec = T';
end
