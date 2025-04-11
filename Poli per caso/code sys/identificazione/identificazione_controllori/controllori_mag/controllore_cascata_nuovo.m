clear
close all
clc

%%
%per Windows
addpath('..\..\..\function');
run('..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello
run('..\controllori_el\fast_controller.m') %richiamare i controllori elettrici

%per Mac
%addpath('../../../function');
%run('../../../Model_Parameter.m')

%% Linearizzazione all'equilibrio
Veq = 12;

G = mag_lin_corrente(Veq, theta);
[Gnum, Gden] = tfdata(G);
num_mag_M = Gnum{1};
den_mag_M = Gden{1};

upper = 12e-3;
lower = 0;

%% Controllore Elettrico 1 fast
G_el_close = feedback(Gel*controller_el1, 1);
G2_1 = G_el_close*G;

%% Controllore elettrico 2 fast
G_el_close2 = feedback(Gel*controller_el2, 1);
G2_2 = G_el_close2*G;

%% Controllore interno VECCHIO
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


%% Controllore interno NUOVO
%% Controllore mag 
controller2 = 1873.4*(s+39.78)*(s+4.402)/(s*(s+252.8));
[Gnum, Gden] = tfdata(controller2);
num_mag_C2 = Gnum{1};
den_mag_C2 = Gden{1};

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
