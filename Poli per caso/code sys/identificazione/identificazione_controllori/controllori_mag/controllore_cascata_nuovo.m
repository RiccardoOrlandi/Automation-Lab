clear
close all
clc

%%
%per Windows
% addpath('..\..\..\function');
% run('..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%per Mac
addpath('../../../function');
run('../../../Model_Parameter.m')

%% Linearizzazione all'equilibrio

switch 0 % se metto 1 inserisco dei disturbi nel modello (esempio km diversa e punto equilibrio diverso, che significano
         % linearizzazione diversa del modello)

    case 0
        Veq = 10;
    case 1
        V_dist = 13;
        theta(2, 1) = 1e-5;
end

G = mag_lin_corrente(Veq, theta);
[Gnum, Gden] = tfdata(G);
Gnum = Gnum{1};
Gden = Gden{1};


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
figure()
margin(Gel*controller)
grid on
figure()
step(feedback(Gel*controller, 1));
grid on

G_el_close = feedback(Gel*controller, 1);
G2 = G_el_close*G;

dist = 0.001;

%% Controllore esterno 4o ordine,ta=0.04;Overshoot=12%
  
  C(s)=1.8333e07 (s^2 + 411.7*s + 4.281e04)*(s^2 + 132.6*s + 5301)/(s*(s+3055)*(s+2908)*(s+2761))
              