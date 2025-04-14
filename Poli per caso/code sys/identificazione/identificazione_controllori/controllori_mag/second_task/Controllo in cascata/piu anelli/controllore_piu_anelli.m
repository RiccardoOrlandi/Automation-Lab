clear
close all
clc

%% CONTROLLORI TROPPO OSCILLANTI O TROPPO INSTABILI/LENTI
%%
%per Windows
addpath('..\..\..\..\..\..\function');
run('..\..\..\..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello
run('..\..\..\..\controllori_el\fast_controller.m') %richiamare i controllori elettrici

%per Mac
%addpath('../../../../../function');
%run('../../../../../Model_Parameter.m')

%% Linearizzazione all'equilibrio

u = 15;

G = mag_lin_corrente(u, theta);
[Gnum, Gden] = tfdata(G);
Gnum = Gnum{1};
Gden = Gden{1};

upper = 12e-3;
lower = 0;
Upper_bound_V = 23;
Lower_bound_V = -23;

%% posizione iniziale simulink
ueq = 15/Rtot;
x2_eq = 0;
% x1_eq = y0 - u0 * sqrt(k_mag/(m*g));

% u0 = 14/Rtot;
% g = 9.81;
% x10 = y0 - u0 * sqrt(k_mag/(m*g));

x10 = 3.51e-3; % inserire posizione iniziale della pallina
x1_error = x10 - x1_eq;
u0 = -(x10-y0)/sqrt(k_mag/(m*g));

%% Controllore Elettrico 1 (Quello già testato)
% controllore con più elongazione (margine di fase 82°, wc = 129rad/s)
%                                 (poli = -75.2085 +- 7.4473i)
G_el_close = feedback(Gel*controller_el1, 1); 
G2_1 = G_el_close*G;

%% Stabilizzatore
num = [1.3350e+03 1.1747e+05];
den = [1 437.9395];
controller_stab = tf(num, den);

% reference tracking

G_close = feedback(G*controller_stab,1);
[Gnclose, Gdclose] = tfdata(G_close);
Gnclose = Gnclose{1};
Gdclose = Gdclose{1};
num_ext = [0.0204 1.4785];
den_ext = [1 0];
controllor_track = tf(num_ext, den_ext);

%% prova piu lenta
num = [916.9165 8.0682e+04];
den = [1 437.9395];
controller_stab = tf(num, den);

% reference tracking

G_close = feedback(G*controller_stab,1);
[Gnclose, Gdclose] = tfdata(G_close);
Gnclose = Gnclose{1};
Gdclose = Gdclose{1};
num_ext = [0.0081249 23.37*0.0081249];
den_ext = [1 0];
controllor_track = tf(num_ext, den_ext);

