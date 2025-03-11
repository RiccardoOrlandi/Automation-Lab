function [tvec, x, y]= FFD(Ts, Tend, x0, u, theta)

%% Simulation with forward finite differences
y0 = theta(4,1);
tvec    =       0:Ts:Tend;  % time vector (s)

% Initialize simulation output
N            =       length(tvec);   % number of samples
x            =       zeros(3,N);     % matrix with states
uout         =       zeros(1,N);     % matrix with inputs
y            =       zeros(2,N);     % matrix with forces
zdot         =       zeros(3,N-1);
x(:,1)       =       x0;
uout(:,1)    =       0;

% Run simulation

for ind=2:N
    [zdot(:, ind-1),y]    =   model(0,x(:,ind-1),uout(:,ind-1),theta);
    if x(1,ind-1) <= 0 && x(3,ind-1) > 0
        x(:,ind)     =   x(:,ind-1)+Ts*zdot(:, ind-1);
        y(:,ind)     =   y;
    elseif x(1,ind-1) <= 0 && x(3,ind-1) <= 0
        x(3,ind-1)   =   0;
        x(1,ind)     =   0;
        x(2,ind)     =   x(2,ind-1)+Ts*zdot(2,ind-1);
        x(3,ind)     =   x(3,ind-1)+Ts*zdot(3,ind-1);
        y(2,ind)     =   y(2,1);
        y(1,ind)     =   0;

    elseif x(1,ind-1) >= y0 && x(3,ind-1) > 0
        x(3,ind-1)   =   0;
        x(1,ind)     =   y0;
        x(2,ind)     =   x(2,ind-1)+Ts*zdot(2,ind-1);
        x(3,ind)     =   0;
        y(1,ind)     =   y0;
        
    else
        x(:,ind)     =   x(:,ind-1)+Ts*zdot(:, ind-1);
        y(:,ind)     =   y;
    end
    if ind >= 501
        uout(:,ind) = u;
    else
        uout(:,ind)      =   uout(:,1);
    end
end
