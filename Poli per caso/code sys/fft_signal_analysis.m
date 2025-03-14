clc
close all
clear

addpath('function');
run('Model_Parameter');
OS = 'Windows';


if strcmp(OS, 'Windows')
    add_data('\data\Step Test\Step Test with ball');
else
    add_data('/data/Step Test/Step Test with ball');
end



%data =load('C:\Users\riccardoorlandi\Desktop\univerita\5anno\2semsetre\AUTOMATION_LABORATORY\git_Automation-Lab\Poli per caso\code sys\data\Step Test\Step Test with ball\Test_21,3V.mat');
%load('C:\Users\Student\Desktop\Automation-Lab-main\Automation-Lab-main\PPC\data\Step Test\Step Test with ball\Test_21V.mat');

segnale = Test_21V;
%variabili = fieldnames(data);
%nomeVariabile = variabili{1};
%segnale = data.(nomeVariabile);

offset = 0.0236;
k_b = 2.686e-3;

% Caricamento del segnale
tempo = segnale(1, :);        % Estrai gli istanti di tempo 
posizione = (segnale(2,:)+offset)*k_b;
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
% figure;
% plot(f, P);
% title('Spettro del segnale di posizione');
% xlabel('Frequenza (Hz)');
% ylabel('Ampiezza');
% xlim([0, fs/2]);          % Mostra solo frequenze positive
% grid on;

simIn = 'passband_filter_2023b';
load_system(simIn)

stoptime = segnale(1, end);
set_param(simIn, 'StopTime', num2str(stoptime));
simout = sim(simIn);


m = 0.0657; % kg
km = Calcolo_Km(simout.acc, 0.0657, 9.81, tempo, posizione, corrente, theta);

% s = tf('s');
% sys = s / (s + 3);
% figure();
% bode(sys);
ind0 = floor(1/0.002)+1;
indf = floor(2/0.002)+1;

acc = simout.acc;
speed = simout.speed;
figure()
plot(tempo(1, ind0:indf), acc(ind0:indf, 1)')
figure()
plot(tempo(1, ind0:indf), speed(ind0:indf, 1)')
