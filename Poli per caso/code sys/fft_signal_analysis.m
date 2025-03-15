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

segnale = Test_21_9V;
%variabili = fieldnames(data);
%nomeVariabile = variabili{1};
%segnale = data.(nomeVariabile);



% Caricamento del segnale
tempo = segnale(1, :);        % Estrai gli istanti di tempo 
posizione = segnale(2,:);
corrente = segnale(3,:);
input = [tempo',posizione'];
input2 = [tempo',corrente'];
% Calcolo della frequenza di campionamento
dt = mean(diff(tempo));  % Intervallo di campionamento medio
fs = 1/dt;               % Frequenza di campionamento

polo = Rtot/Lc;

% costruisco il filtro
filter = tf(polo*10, [1 polo*10]);
filter_d = c2d(filter, 0.002, 'Turstin');
[num, den] = tfdata(filter_d);
num = num{1};
den = den{1};
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
km = Calcolo_Km(simout, 0.0657, 9.81, tempo, posizione, simout.corrente, theta);

% s = tf('s');
% sys = s / (s + 3);
% figure();
% bode(sys);

