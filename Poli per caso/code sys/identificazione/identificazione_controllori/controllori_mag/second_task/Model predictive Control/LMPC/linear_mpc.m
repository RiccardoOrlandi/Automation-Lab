function u0 = linear_mpc(Q, R, N, x0, T_s)

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
         % sistema continuo
                      % tempo di campionamento
    sys_d = c2d(sys, T_s);         % discretizzazione ZOH
    
    A = sys_d.A;
    B = sys_d.B;

    umin = 0;
    umax = 23;
    [nx, nu] = size(B);
    
    % Costruisci matrici predittive
    H = blkdiag(kron(eye(N), R));
    for i = 1:N
        H = blkdiag(H, Q);
    end

    % Matrice F per evoluzione dinamica
    F = zeros(N*nx, nx);
    Phi = zeros(N*nx, N*nu);
    
    for i = 1:N
        F((i-1)*nx+1:i*nx, :) = A^i;
        for j = 1:i
            Phi((i-1)*nx+1:i*nx, (j-1)*nu+1:j*nu) = A^(i-j) * B;
        end
    end

    % Costruisci H_QP e f_QP
    Qbar = kron(eye(N), Q);
    Rbar = kron(eye(N), R);
    
    H_QP = Phi' * Qbar * Phi + Rbar;
    f_QP = (F * x0)' * Qbar * Phi;

    % Vincoli: umin <= u <= umax
    G = [eye(N*nu); -eye(N*nu)];
    h = [repmat(umax, N, 1); -repmat(umin, N, 1)];
    
    % Risolvi QP
    options = optimoptions('quadprog','Display','off');
    [U_opt, ~] = quadprog(H_QP, f_QP', G, h, [], [], [], [], [], options);

    % Applica il primo controllo
    u0 = U_opt(1:nu);
end
