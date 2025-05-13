function [ xkp1, yk ] = model_step(xk, uk, tau)
    % model_step
    % Function implementing the discrete-time evolution of the system state x(k+1) and output y(k).
    % Obtained discretizing the system dynamics via Forward Euler.
    %
    % x(k+1) = f(x(k), u(k))
    % y(k) = x(k)
    
    %% Model Parameters

    % other param:
    k_aero = 0;
    k_mag = 2.4405e-05 ;%2.4405e-05; %9.3993e-05;%2.4405e-05; %1.0461e-05; % Nm^2/A^2
    m = 0.0657; % kg
    y0 = 0.0120; % m
    Rs = 1; % Ohm
    Rtot = 9.7585;
    Lc = 0.3708; % H
    g = 9.81;
    theta = [k_aero, k_mag, m, y0, Rtot, Lc]';

    % x1 = xk(1, 1);
    % x2 = xk(2, 1);
    % x3 = xk(3, 1);

    % Equazioni di stato non lineari
    xdot1 = xk(3);
    xdot2 = -(Rtot/Lc) * xk(2) + (1/Lc) * uk;
    xdot3 = (k_aero/m) * xk(3) + (k_mag/m) * (xk(2) / (y0 - xk(1)))^2 - g;


    xkp1 = [xk(1) + tau*xdot1;
        xk(2) + tau*xdot2;
        xk(3) + tau*xdot3];

    % Uscite
    yk = [xk(1);
        xk(2)];

end