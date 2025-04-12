clear
close all
clc

%%
%per Windows
addpath('..\..\..\..\..\function');
run('..\..\..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%per Mac
%addpath('../../../../../function');
%run('../../../../../Model_Parameter.m')

%% Linearizzazione all'equilibrio

switch 0 % se metto 1 inserisco dei disturbi nel modello (esempio km diversa e punto equilibrio diverso, che significano
         % linearizzazione diversa del modello)

    case 0
        Veq = 12;
    case 1
        V_dist = 13;
        theta(2, 1) = 1e-5;
end

[G, A, B, C, D] = mag_lin_corrente(Veq, theta);
[Gnum, Gden] = tfdata(G);
num_mag_M = Gnum{1};
den_mag_M = Gden{1};

% step = 0.001;
% upper =
% lower =

%% posizione iniziale simulink
ueq = Veq/Rtot;
x2_eq = 0;
% x1_eq = y0 - u0 * sqrt(k_mag/(m*g));

% u0 = 14/Rtot;
% g = 9.81;
% x10 = y0 - u0 * sqrt(k_mag/(m*g));

x10 = 3.51e-3; % inserire posizione iniziale della pallina
x1_error = x10 - x1_eq;
u0 = -(x10-y0)/sqrt(k_mag/(m*g));

%% Controllore Elettrico
s = tf('s');
kp = 46.0161;
ki = 2117.9265;
kd = 0;
Gel = 1/(s*Lc+Rtot);
controller = kp + ki/s+ kd*s;
[Celnum, Celden] = tfdata(controller);
Celnum = Celnum{1};
Celden = Celden{1};
% figure()
% margin(Gel*controller)
% grid on
% figure()
% step(feedback(Gel*controller, 1));
% grid on

G_el_close = feedback(Gel*controller, 1);
G2 = G_el_close*G;

dist = 0.001;

%% Controllore esterno
%% Controllore 3o ordine (assestamento 0.3, sovraelongazione 25%, damping 0.64
controller = 1.5764e05*(s+24.2)*(s+15.92)*(s+123.3)/(s*(s+1020)*(s+1205));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controllore 3o ordine (assestamento 0.3, sovraelongazione 20%, damping 1
controller =1.4665e07*(s+39.34)*(s+123.3)*(s+10.32)/(s*(s+5857)*(s+1.789e04));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};
%% Controller 4o
controller = 1.8333e07*(s^2+411.7*s+4.281e04)*(s^2+132.6*s+5301)/(s*(s+3055)*(s+2908)*(s+2761));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controller 2 ordine controllato
controller = 1336.6*(s+7.716)*(s+41.43)/(s*(s+312.6));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controllore

%% Plot linearizzazione
close all
x=-0.012:0.0001:0.012;
dot = 2*k_mag*ueq^2/m*((y0-x1_eq)^(-3))*(x-x1_eq) + 2*k_mag/m*ueq/((y0 - x1_eq)^2)*(ueq-ueq);

figure()
plot(x,dot)
grid on
hold on
dot_nl = k_mag/m*(ueq./(y0-x)).^2-g;
plot(x, dot_nl)
ylim([-10, 50])
xlim([0, 0.012])
xlabel('posizione')
ylabel('accellerazione')
title('Linearizzazione in 0.0044 [m]')
legend('linearizzato', 'non linearizzato')
