function [x_bar, u_bar] = compute_equilibrium(x1)

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

    x1_bar = x1;
    x2_bar = sqrt(m*g*(y0 - x1_bar)^2/k_mag);
    u_bar = Rtot * x2_bar; 
    x3_bar = 0;

    x_bar = [x1_bar; x2_bar; x3_bar];

end

