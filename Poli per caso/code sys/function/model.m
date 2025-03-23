function [xdot, y, G] = model(t, x, u, theta)

    % x: column vector of 3 components [3x1]
    %       x = [position, current, speed]'
    %
    % theta: column vector of 6 components [6x1]
    %       theta = [k_aero, k_mag, m, y0, Rtot, Lc]'          
    %
    % x1_eq, x2_eq, x3_eq: condizioni di equilibrio per le variabili di stato
    % u: ingresso (forza applicata)
    
    k_aero = theta(1, 1);
    k_mag = theta(2, 1);
    m = theta(3, 1);
    y0 = theta(4, 1);
    Rtot = theta(5, 1);
    Lc = theta(6, 1);
    g = 9.81;

    x2_eq = u/Rtot;
    x3_eq = 0;
    %x1_eq = y0 - x2_eq * sqrt(k_mag/(m*g));
    x1_eq = 0.004;
    

   

    x1 = x(1, 1);
    x2 = x(2, 1);
    x3 = x(3, 1);

    % Equazioni di stato non lineari
    xdot1 = x3;
    xdot2 = -(Rtot/Lc) * x2 + (1/Lc) * u;
    xdot3 = (k_aero/m) * x3 + (k_mag/m) * (x2 / (y0 - x1))^2 - g;

    xdot = zeros(3, 1);
    xdot(1, 1) = xdot1;
    xdot(2, 1) = xdot2;
    xdot(3, 1) = xdot3;

    % Uscite
    y = zeros(2, 1);
    y(1, 1) = x1;
    y(2, 1) = x2;

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