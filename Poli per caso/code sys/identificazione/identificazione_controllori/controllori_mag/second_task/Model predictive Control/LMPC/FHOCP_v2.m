 function u_opt = FHOCP_v2(xk, Q, R, N, x_bar, u_bar, tau_s)
       % FHOCP
    % Solve the Finite Horizon Control Optimization Problem
    
    % Parameters
    % - xk: The current state
    % - Q: The state weight
    % - R: The input weight
    % - N: The prediction horizon
    % - x_bar: The target state equilibrium
    % - u_bar: The target input equilibrium
    % - tau_s: the sampling time
    
    yalmip clear

    k_aero = 0;
    k_mag = 2.4405e-05 ;%2.4405e-05; %9.3993e-05;%2.4405e-05; %1.0461e-05; % Nm^2/A^2
    m = 0.0657; % kg
    y0 = 0.0120; % m
    Rs = 1; % Ohm
    Rtot = 9.7585;
    Lc = 0.3708; % H
    g = 9.81;
    theta = [k_aero, k_mag, m, y0, Rtot, Lc]';


    % Inizializza variabili decisionali
    %x = sdpvar(3, N+1);     % Stato predetto
    u = sdpvar(1, N);       % Controllo predetto
    x = sdpvar(3, N+1);

        % Vincolo sullo stato iniziale
    x(:,1) = xk;

    % sistema
    [G, Act, Bct, Cct, Dct] = lin(xk(1,1), theta);
    % Model discretization                      
    Model           =   c2d(ss(Act,Bct,Cct,Dct),tau_s);
    [A,B,C,D]       =   ssdata(Model);

    for k = 1:N
        % Dinamica del sistema
        x(:, k+1) = A*x(:,k) + B*u(:,k);    
    end

    %     % Calcolo esplicito x(k) = A^k * x0 + sum A^{k-1-i} * B * u(i)
    % for k = 1:N
    %     Ak = A^k;
    %     sum_term = zeros(2,1);
    %     for i = 0:k-1
    %         sum_term = sum_term + A^(k-1-i) * B * u(i+1);  % u(i+1) perché in MATLAB gli indici partono da 1
    %     end
    %     x(:,k+1) = Ak * x0 + sum_term;
    % end

    

    % Vincoli su input
    Constraints = [u >= 1e-6*ones(1, N)] + [u <= 23*ones(1, N)]+...
        [-10*ones(3, N+1) <= x] + [x <= 0.012*ones(3, N+1)];

    % % Funzione costo
    % Objective = (x-x_bar*ones(3, N+1))'*Q*(x-x_bar*ones(3, N+1)) ...
    %     + (u-u_bar*ones(1, N))'*R*(u-u_bar*ones(1, N));

    Objective = 0;
    for k = 1:N
        Objective = Objective + (x(:,k) - x_bar)' * Q * (x(:,k) - x_bar) ...
                              + (u(:,k) - u_bar)' * R * (u(:,k) - u_bar);
    end

    % Terminal constraint (facoltativo)
    % Constraints = [Constraints, x(:,end) == x_bar];

    % Imposta opzioni del solver
    options = sdpsettings('solver', 'quadprog', 'verbose', 0);

    % Risolvi il problema di ottimizzazione
    diagnostics = optimize(Constraints, Objective, options);

    if diagnostics.problem == 0
        % Soluzione trovata
        u_opt = value(u(:,1));
    else
        % Fallimento
        warning('Problema nella risoluzione FHOCP: %s', diagnostics.info);
        u_opt = NaN;
    end
end
