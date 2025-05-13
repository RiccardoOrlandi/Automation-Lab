clear
close all
clc

%%
%per Windows
addpath('..\..\..\..\..\function');
run('..\..\..\controllori_el\fast_controller.m') %richiamare i controllori elettrici
run('..\..\..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello
add_data_volt('..\..\..\..\..\data\test_controllore\controllore_mag\15_04_2025')

%per Mac
%addpath('../../../../../function');
%run('../../../../../Model_Parameter.m')
%run('../../../controllori_el\fast_controller.m') %richiamare i controllori elettrici
%% Linearizzazione all'equilibrio
x1_eq = 0.0044;
G = mag_lin_corrente2(x1_eq, theta);
[Gnum, Gden] = tfdata(G);
num_mag_M = Gnum{1};
den_mag_M = Gden{1};

upper = 12e-3;
lower = 0;
Upper_bound_V = 23;
Lower_bound_V = 0;

%% Controllore elettrico 2
% controllore più cauto           (margine di fase 83°, wc = 84.4rad/s)
%                                 (poli = -53.5093 +- 13.6548i)
G_el_close2 = feedback(Gel*controller_el2, 1);
G2_2 = G_el_close2*G;


%% Controllore interno 2
%% Sembra valido, un po più tranquillo 
controller2 = 3438.2*(s+20.07)*(s+5.024)/(s*(s+385.6));
[Gnum, Gden] = tfdata(controller2);
num_mag_C2 = Gnum{1};
den_mag_C2 = Gden{1};

% %% Plot linearizzazione
% x=-0.012:0.0001:0.012;
% dot = 2*k_mag*ueq^2/m*((y0-x1_eq)^(-3))*(x-x1_eq) + 2*k_mag/m*ueq/((y0 - x1_eq)^2)*(ueq-ueq);
% 
% figure()
% plot(x,dot, 'LineWidth', 1.5)
% grid on
% hold on
% dot_nl = k_mag/m*(ueq./(y0-x)).^2-g;
% plot(x, dot_nl, 'LineWidth', 1.5)
% plot(x, zeros(1, length(x)), 'LineStyle','--', 'color', 'green', 'LineWidth', 1.2)
% ylim([-10, 10])
% xlim([x1_eq-0.002, x1_eq+0.002])
% xlabel('posizione')
% ylabel('accellerazione')
% title('Linearizzazione in 4.4mm intorno di 2mm')
% legend('linearizzato', 'non linearizzato')