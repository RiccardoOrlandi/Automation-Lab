function [G, A, B, C, D] = lin(u, theta)

% x1 è la posizione
% x2 è la corrente
% x3 è la velocità

    k_aero = theta(1, 1);
    k_mag = theta(2, 1);
    m = theta(3, 1);
    y0 = theta(4, 1);
    Rtot = theta(5, 1);
    Lc = theta(6, 1);
    g = 9.81;

    x2_eq = u/Rtot;
    x1_eq = y0 - x2_eq * sqrt(k_mag/(m*g));
    x3_eq = 0;

    A = [0 0 1;
        0 -Rtot/Lc 0;
        2*k_mag*x2_eq^2/(m*(y0-x1_eq)^3) 2*k_mag*x2_eq/(m*(y0-x1_eq)^2) 0];
    B = [0; 1/Lc; 0];
    C = [1 0 0;
        0 1 0];
    D = [0;0];

    % Funzione di trasferimento
    sys = ss(A, B, C, D);
    G = tf(sys);
end