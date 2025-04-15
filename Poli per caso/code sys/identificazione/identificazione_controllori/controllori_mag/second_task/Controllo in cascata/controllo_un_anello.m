clear
close all
clc

%%
%per Windows
addpath('..\..\..\..\..\function');
run('..\..\..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello
run('..\..\..\controllori_el\fast_controller.m') %richiamare i controllori elettrici
load("input_signal.mat")

%per Mac
%addpath('../../../../../function');
%run('../../../../../Model_Parameter.m')
%run('../../../controllori_el\fast_controller.m') %richiamare i controllori elettrici
%% Linearizzazione all'equilibrio
Veq = 12;
[A, V0, U0] = mag_lin_corrente2(0, theta)
G = mag_lin_corrente(Veq, theta);
[Gnum, Gden] = tfdata(G);
num_mag_M = Gnum{1};
den_mag_M = Gden{1};

upper = 12e-3;
lower = 0;
Upper_bound_V = 23;
Lower_bound_V = -23;

%% Controllore Elettrico 1 (Quello già testato)
% controllore con più elongazione (margine di fase 82°, wc = 129rad/s)
%                                 (poli = -75.2085 +- 7.4473i)
G_el_close = feedback(Gel*controller_el1, 1); 
G2_1 = G_el_close*G;

%% Controllore elettrico 2
% controllore più cauto           (margine di fase 83°, wc = 84.4rad/s)
%                                 (poli = -53.5093 +- 13.6548i)
G_el_close2 = feedback(Gel*controller_el2, 1);
G2_2 = G_el_close2*G;

%% Controllore elettrico 3
% controllore con un polo veloce ma quello dominante più lento  
%                                 (margine di fase 91.7°, wc = 180rad/s)
%                                 (poli = -187, -20)
G_el_close3 = feedback(Gel*controller_el3, 1);
G2_3 = G_el_close3*G;

%% Controllore interno 1
%% Controllore 3o ordine (assestamento 0.3, sovraelongazione 25%, damping 0.64
% pare funzionare ma rallenta molto simulink
% inoltre l'input è particolarmente "nervoso" anche al riferimento
controller = 1.5764e05*(s+24.2)*(s+15.92)*(s+123.3)/(s*(s+1020)*(s+1205));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% con kmag elevata 1e-4
controller = 1943.8*(s+24.11)*(s+7.716)/(s*(s+436));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controllore molto moderato
% ampia oscillazione
controller = 1336.6*(s+7.716)*(s+41.43)/(s*(s+312.6));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controllore in linea con gli altri (Sembra valido, un po più veloce del controllore 2)
controller = 3215.7*(s+26.34)*(s+7.716)/(s*(s+452.5));
[Gnum, Gden] = tfdata(controller);
num_mag_C = Gnum{1};
den_mag_C = Gden{1};

%% Controllore interno 2
%% Sembra valido, un po più tranquillo 
controller2 = 3438.2*(s+20.07)*(s+5.024)/(s*(s+385.6));
[Gnum, Gden] = tfdata(controller2);
num_mag_C2 = Gnum{1};
den_mag_C2 = Gden{1};


%% Controllore interno 3
%% Da alcuni problemi, non sempre stabilizza per colpa della saturazione
controller3 = 1873.4*(s+39.78)*(s+4.402)/(s*(s+252.8));
[Gnum, Gden] = tfdata(controller3);
num_mag_C3 = Gnum{1};
den_mag_C3 = Gden{1};





%% Plot linearizzazione
x=-0.012:0.0001:0.012;
dot = 2*k_mag*ueq^2/m*((y0-x1_eq)^(-3))*(x-x1_eq) + 2*k_mag/m*ueq/((y0 - x1_eq)^2)*(ueq-ueq);

figure()
plot(x,dot, 'LineWidth', 1.5)
grid on
hold on
dot_nl = k_mag/m*(ueq./(y0-x)).^2-g;
plot(x, dot_nl, 'LineWidth', 1.5)
plot(x, zeros(1, length(x)), 'LineStyle','--', 'color', 'green', 'LineWidth', 1.2)
ylim([-10, 10])
xlim([x1_eq-0.002, x1_eq+0.002])
xlabel('posizione')
ylabel('accellerazione')
title('Linearizzazione in 4.4mm intorno di 2mm')
legend('linearizzato', 'non linearizzato')
