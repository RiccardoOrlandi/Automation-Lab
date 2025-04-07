clc
close all
clear

% -----------------------------------------------------------------------------
%% Questo script calcola km usando i filtri per il calcolo della accellerazione
%% ----------------------------------------------------------------------------




OS = 'Windows';


if strcmp(OS, 'Windows')
    addpath('..\function');
    run('..\Model_Parameter');
    add_data('..\data\Step Test\Step Test with ball');
    add_data('..\data\Step Test\18_03_2024\with_ball');
    add_data('..\data\Step Test\18_03_2025_v2\with ball');
else
    addpath('../function');
    run('../Model_Parameter');
    add_data('../data/Step Test/Step Test with ball');
end

%% Scelta del test in esame
segnale = Test_with_21_5V;

%% Costruisco filtri
% costruisco il filtro per la corrente
polo = Rtot/Lc;
filter = tf(polo*100, [1 polo*100]);

filter_d = c2d(filter, 0.002, 'Turstin');
[num, den] = tfdata(filter_d);
num = num{1};
den = den{1};

% costruisco il filtro la derivata posizione
filter2 = tf([700, 0], [1 700]);
filter2_d = c2d(filter2, 0.002, 'Turstin');
[num2, den2] = tfdata(filter2_d);
num2 = num2{1};
den2 = den2{1};

%% Simulazione e calcolo km

simIn = 'passband_filter_2023b'; % nome del file simulink usato per i filtri
load_system(simIn)

stoptime = segnale(1, end);
set_param(simIn, 'StopTime', num2str(stoptime));
simout = sim(simIn);

km = Calcolo_Km(simout, segnale, theta);

