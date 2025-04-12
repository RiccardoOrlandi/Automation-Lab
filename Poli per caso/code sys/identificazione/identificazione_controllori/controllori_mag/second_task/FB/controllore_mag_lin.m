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
        u = 15;
    case 1
        u = 13;
        theta(2, 1) = 1e-5;
end

G2 = mag_lin_corrente(u, theta);
[Gnum, Gden] = tfdata(G2);
Gnum = Gnum{1};
Gden = Gden{1};


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
figure()
margin(Gel*controller)
grid on
figure()
step(feedback(Gel*controller, 1));
grid on

G_el_close = feedback(G2*controller, 1);

dist = 0.001;

%% Stabilizzatore
num = [1.3350e+03 1.1747e+05];
den = [1 437.9395];
controller_stab = tf(num, den);
figure()
margin(G2*controller_stab)
grid on
figure()
step(feedback(G2*controller_stab,1))
grid on 
title('stabilizzatore')

% reference tracking

G_close = feedback(G2*controller_stab,1);
[Gnclose, Gdclose] = tfdata(G_close);
Gnclose = Gnclose{1};
Gdclose = Gdclose{1};
num_ext = [0.0204 1.4785];
den_ext = [1 0];
controllor_track = tf(num_ext, den_ext);
figure()
margin(G_close*controllor_track)
grid on
figure()
step(feedback(G_close*controllor_track, 1));
grid on
title('tracking');


%% Controllore con integratore
num_unico = [2.3311e+03 9.5102e+04 5.9792e+05];
den_unico = [1 238.5202 0];
controller_stab2 = tf(num_unico, den_unico);
figure()
margin(G2*controller_stab2)
figure()
rlocus(G2*controller_stab2)
figure()
step(feedback(G2*controller_stab2,1))

%% prova piu lenta
num = [916.9165 8.0682e+04];
den = [1 437.9395];
controller_stab = tf(num, den);
figure()
margin(G2*controller_stab)
grid on
figure()
step(feedback(G2*controller_stab,1))
grid on 
title('stabilizzatore')

% reference tracking

G_close = feedback(G2*controller_stab,1);
[Gnclose, Gdclose] = tfdata(G_close);
Gnclose = Gnclose{1};
Gdclose = Gdclose{1};
num_ext = [0.0081249+23.37*0.0081249];
den_ext = [1 0];
controllor_track = tf(num_ext, den_ext);
figure()
margin(G_close*controllor_track)
grid on
figure()
step(feedback(G_close*controllor_track, 1));
grid on
title('tracking');

%% anello del prof

C = 3212.6*(s+39.02)/(s+244.3);