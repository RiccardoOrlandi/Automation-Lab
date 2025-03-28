clear
close all
clc

%%
addpath('function');
run('Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%% Chiamata al modello per trovare l'equilibrio
u = 15;
% theta(2, 1) = 2e-5;
G = mag_lin(u, theta);
% restituisce un sistema G 2x1 (1 input: tensione, 2 output: posizione e corrente)
%       a noi interessa primo input e primo output per il controllore
%       della posizione
% sys = G(1, 1);
G2 = mag_lin_corrente(u, theta);
[Gnum, Gden] = tfdata(G2);
Gnum = Gnum{1};
Gden = Gden{1};
% bode(sys)
% grid on
% % wc deve essere <15 rad/s
s = tf('s');
% controllore = 1/s*(s+10)*(s+10)/(s+5);
% figure()
% rlocus(sys*controllore)
% figure()
% bode(sys*controllore)
% grid on

% 
% figure()
% bode(G2)
% grid on

% controllore2 = 1/s*(s+200)/(s+3000)*(s+200)*2e7;
controllore2 = 1/s*(s+10)/(s+30)*(s+10)*1e5;

% *3e5
figure()
rlocus(G2*controllore2)
figure()
bode(G2*controllore2)
grid on

pole(G2)
x1_eq
% rltool


%%
close all
prova = G2*1/s*(s+5)/(s+15)*(s+5)*9e4;
rlocus(prova)
figure()
bode(prova)
grid on
figure()
step(feedback(prova, 1))
grid on

%%
controllore3 = 3.334e5*(s+34.7)*(s+39)/s/(s+180);
[Cnum, Cden] = tfdata(controllore3);
Cnum = Cnum{1};
Cden = Cden{1};
prova = G2*controllore3;
rlocus(prova)
figure()
bode(prova)
grid on
figure()
step(feedback(prova, 1))
grid on


kp = 46.0161;
ki = 2117.9265;
kd = 0;
controller = kp + ki/s+ kd*s;
[Celnum, Celden] = tfdata(controller);
Celnum = Celnum{1};
Celden = Celden{1};