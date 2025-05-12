function sys = lin_MPC(x1, theta)

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

    x1_eq = x1;
    x2_eq = sqrt(m*g*(y0 - x1_eq)^2/k_mag);
    u_eq = Rtot * x2_eq; 
    x3_eq = 0;
    % assignin('base', 'x1_eq0', x1_eq);
    % assignin('base', 'x2_eq0', x2_eq);
    % assignin('base', 'x3_eq0', x3_eq);
    % assignin('base', 'u', u_eq);

    A = [0 0 1;
        0 -Rtot/Lc 0;
        2*k_mag*x2_eq^2/(m*(y0-x1_eq)^3) 2*k_mag*x2_eq/(m*(y0-x1_eq)^2) 0]; %Quando si vuole provare con 
    %la forza magnetica riferita alla cima della pallina sostituire y0 con
    %0.0247
    B = [0; 1/Lc; 0];
    C = [1, 0, 0;
        0, 1, 0];
    D = [0;0];

    % Funzione di trasferimento
    sys = ss(A, B, C, D);
    % G = tf(sys);
    x = quadprog(H,f,A,b,Aeq,beq,lb,ub,x0,options);
    
end