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
%run('../../../controllori_el\fast_controller.m') %richiamare i controllori elettrici
%% Linearizzazione all'equilibrio
x1_eq = 0.004;
G = mag_lin_corrente2(x1_eq, theta);


upper = 12e-3;
lower = 0;
Upper_bound_V = 23;
Lower_bound_V = 0;

s = tf('s');
G = G*(1/(Lc*s+Rtot));
controller_PI = 1000 + 3000/s;
margin(controller_PI*G)
grid on
figure()
step(feedback(controller_PI*G,1))
grid on
