clear
close all
clc

%%
addpath('function');
run('Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

%% Chiamata al modello per trovare l'equilibrio
u = 10;
% theta(2, 1) = 0.9e-6;
G = mag_lin(u, theta);
% restituisce un sistema G 2x1 (1 input: tensione, 2 output: posizione e corrente)
%       a noi interessa primo input e primo output per il controllore
%       della posizione
sys = G(1, 1);
G2 = mag_lin_corrente(u, theta);
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

figure()
bode(G2)
grid on
controllore2 = 1/s*(s+200)/(s+3000)*(s+200);

% *3e5
figure()
rlocus(G2*controllore2)
figure()
bode(G2*controllore2)
grid on

% rltool
