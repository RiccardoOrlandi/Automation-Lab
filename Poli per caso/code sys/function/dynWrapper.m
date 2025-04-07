function dx = dynWrapper(~, x, u, theta, y0)
    [dx_model, ~] = model(0, x, u, theta);

    dx = zeros(3,1);

    % Gestione condizioni a tratti
    if x(1) <= 0 && x(3) > 0
        dx = dx_model;

    elseif x(1) <= 0 && x(3) <= 0
        dx(1) = 0;                % posizione bloccata
        dx(2) = dx_model(2);      % velocità angolare evolve
        dx(3) = dx_model(3);      % accelerazione evolve

    elseif x(1) >= y0 && x(3) > 0
        dx(1) = 0;                % posizione bloccata
        dx(2) = dx_model(2);
        dx(3) = 0;                % niente accelerazione

    else
        dx = dx_model;
    end
end