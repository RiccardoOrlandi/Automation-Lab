close all
clc

addpath('function');


%data =load('C:\Users\riccardoorlandi\Desktop\univerita\5anno\2semsetre\AUTOMATION_LABORATORY\git_Automation-Lab\Poli per caso\code sys\data\Step Test\Step Test with ball\Test_21,3V.mat');
%load('C:\Users\Student\Desktop\Automation-Lab-main\Automation-Lab-main\PPC\data\Step Test\Step Test with ball\Test_21V.mat');
data = load("Test_23V.mat")
variabili = fieldnames(data);
nomeVariabile = variabili{1};
segnale = data.(nomeVariabile);


% Caricamento del segnale
tempo = segnale(1, :);        % Estrai gli istanti di tempo
posizione = segnale(2, :);     % Estrai la posizione
corrente = segnale(3,:);
input = [tempo',posizione'];
% Calcolo della frequenza di campionamento
dt = mean(diff(tempo));  % Intervallo di campionamento medio
fs = 1/dt;               % Frequenza di campionamento

% Calcolo della FFT
N = length(posizione);   % Numero di punti nel segnale
Y = fft(posizione);       % Trasformata di Fourier del segnale
f = (0:N-1)*(fs/N);       % Vettore delle frequenze

% Prendi solo la parte positiva dello spettro
P = abs(Y/N);             % Spettro normalizzato
f = f(1:floor(N/2));             % Frequenze positive
P = P(1:floor(N/2));             % Spettro positivo

% Plot dello spettro
figure;
plot(f, P);
title('Spettro del segnale di posizione');
xlabel('Frequenza (Hz)');
ylabel('Ampiezza');
xlim([0, fs/2]);          % Mostra solo frequenze positive
grid on;

m = 0.0657; % kg
km = Calcolo_Km(out.acc, 0.0657, 9.81, tempo, posizione, corrente);
figure
plot(tempo, km);

sym s 
sys = tf(s, s + 3);
figure();
bode(sys);
