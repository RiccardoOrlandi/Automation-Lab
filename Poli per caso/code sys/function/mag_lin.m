function G = mag_lin(u, theta)

% x2 è la corrente
% x1 è la posizione
% x3 è la velocità

    k_aero = theta(1, 1);
    k_mag = theta(2, 1);
    m = theta(3, 1);
    y0 = theta(4, 1);
    Rtot = theta(5, 1);
    Lc = theta(6, 1);
    g = 9.81;


    x2_eq = u/Rtot;
    x3_eq = 0;
    x1_eq = y0 - x2_eq * sqrt(k_mag/(m*g));
    assignin('base', 'x1_eq', x1_eq);

    % Calcolo delle derivate parziali per la linearizzazione attorno al punto di equilibrio
    % Calcolo delle derivate rispetto a x1, x2, x3 e u (ingresso)

    % Derivate parziali della funzione di stato rispetto agli stati
    % (derivate di xdot rispetto a x1, x2, x3)
    dx1_dx1 = 0;  % Derivata di xdot1 rispetto a x1
    dx1_dx2 = 0;  % Derivata di xdot1 rispetto a x2
    dx1_dx3 = 1;  % Derivata di xdot1 rispetto a x3
    dx1_du = 0;   % Derivata di xdot1 rispetto a u

    dx2_dx1 = 0;  % Derivata di xdot2 rispetto a x1
    dx2_dx2 = -Rtot/Lc;  % Derivata di xdot2 rispetto a x2
    dx2_dx3 = 0;  % Derivata di xdot2 rispetto a x3
    dx2_du = 1/Lc;  % Derivata di xdot2 rispetto a u

    dx3_dx1 = (k_mag/m) * (2 * (x2_eq)^2) / (y0 - x1_eq)^3;  % Derivata di xdot3 rispetto a x1
    dx3_dx2 = (k_mag/m) * (2 * x2_eq) / (y0 - x1_eq)^2;   % Derivata di xdot3 rispetto a x2
    dx3_dx3 = k_aero/m;  % Derivata di xdot3 rispetto a x3
    dx3_du = 0;  % Derivata di xdot3 rispetto a u

    % Matrice A (derivata parziale di xdot rispetto a x)
    A = [dx1_dx1, dx1_dx2, dx1_dx3; 
         dx2_dx1, dx2_dx2, dx2_dx3; 
         dx3_dx1, dx3_dx2, dx3_dx3];

    % Matrice B (derivata parziale di xdot rispetto a u)
    B = [dx1_du; dx2_du; dx3_du];

    % Matrice C (uscite)
    C = [1, 0, 0; 0, 1, 0];  % Misuriamo la posizione e la corrente come uscite
    D = [0; 0];  % Non ci sono effetti diretti dell'ingresso sulle uscite

    % Funzione di trasferimento
    sys = ss(A, B, C, D);
    G = tf(sys);
end