function [G, veq, ueq] = mag_lin_corrente2(x1_eq, theta)

% u è la corrente
% x1 è la posizione
% x2 è la velocità

    k_aero = theta(1, 1);
    k_mag = theta(2, 1);
    m = theta(3, 1);
    y0 = theta(4, 1);
    Rtot = theta(5, 1);
    Lc = theta(6, 1);
    g = 9.81;

    ueq = (y0-x1_eq)/sqrt(k_mag/(m*g));
    veq = ueq*Rtot;
    x2_eq = 0;
    
    assignin('base', 'Veq', veq);
    assignin('base', 'ueq', ueq);


    A = [0 1;
        2*k_mag*ueq^2/m*((y0-x1_eq)^(-3)), 0];
    B = [0; 2*k_mag/m*ueq/((y0 - x1_eq)^2)];
    C = [1 0];
    D = [];

    % Funzione di trasferimento
    sys = ss(A, B, C, D);
    G = tf(sys);
end