clear all
close all
clc

%per Windows
run('..\..\..\Model_Parameter.m')
addpath('..\..\..\function')
add_data_volt('..\..\..\data\Step Test\Step Test without ball');
add_data_volt('..\..\..\data\Step Test\18_03_2024\without_ball');
add_data_volt('..\..\..\data\Step Test\18_03_2025_v2\without ball');
add_data_volt('..\..\..\data\Step Test\Step Test with ball');
add_data_volt('..\..\..\data\Step Test\18_03_2025_v2\with ball');
add_data_volt('..\..\..\data\Step Test\18_03_2024\with_ball');
add_data_volt('..\..\..\data\Step Test\Step Test with ball');
add_data_volt('..\..\..\data\Step Test\18_03_2025_v2\with ball');
add_data_volt('..\..\..\data\Step Test\18_03_2024\with_ball');

%per Mac
%run('../../../Model_Parameter.m')
%addpath('../../../function')
% add_data_volt('../../../data/Step Test/Step Test without ball');
% add_data_volt('../../../data/Step Test/18_03_2024/without_ball');
% add_data_volt('../../../data/Step Test/18_03_2025_v2/without ball');
% add_data_volt('../../../data/Step Test/Step Test with ball');
% add_data_volt('../../../data/Step Test/18_03_2025_v2/with ball');
% add_data_volt('../../../data/Step Test/18_03_2024/with_ball');
% add_data_volt('../../../data/Step Test/Step Test with ball');
% add_data_volt('../../../data/Step Test/18_03_2025_v2/with ball');
% add_data_volt('../../../data/Step Test/18_03_2024/with_ball');


%% OFFSET CORRENTE
% Calcolo offset misura di corrente (valori senza palla e quando tensione
% nulla (primo secondo di ogni test, ovvero primi 500 dati)

offset_corrente_volt1 = mean([Test_wb_0V(3,1:500), Test_wb_12V(3,1:500), Test_wb_15V(3,1:500), Test_wb_18V(3,1:500), Test_wb_21V(3,1:500), Test_wb_23V(3,1:500), ...
    Test_wb_3V(3,1:500), Test_wb_6V(3,1:500), Test_wb_9V(3,1:500)], 'all');



offset_corrente_volt2 = mean([Test_without_22_5(3,1:500), Test_without_21_5(3,1:500), Test_without_19V(3,1:500), Test_without_16V(3,1:500), Test_wb_23V_v(3,1:500), Test_wb_21V_v(3,1:500), ...
    Test_wb_18V_v(3,1:500), Test_wb_15V_v(3,1:500)], 'all');



offset_corrente_volt3 = mean([Test_without_23V_v2(3,1:500), Test_without_21V_v2(3,1:500), Test_without_18V_v2(3,1:500), Test_without_15V_v2(3,1:500)], 'all');

offset_corrente = mean([offset_corrente_volt1, offset_corrente_volt2, offset_corrente_volt3]);
%% OFFSET POSIZIONE


% Calcolo offset sensore di posizione (con la pallina e per i test dove non si alza)

offset_posizione_volt1 = mean([Test_0V(2,:), Test_12V(2,:), Test_15V(2,:), Test_18V(2,:), Test_19V(2,:), Test_20_5V(2,:), Test_20V(2,:),...
    Test_3V(2,:), Test_6V(2,:), Test_9V(2,:)], 'all');


offset_posizione_volt2 = mean([Test_with_18V_v2(2,:), Test_with_15V_v2(2,:)], 'all');


offset_posizione_volt3 = mean([Test_with_19V(2,:), Test_with_16V(2,:), Test_18V_v(2,:), Test_15V_v(2,:)], 'all');

offset_posizione = mean([offset_posizione_volt1, offset_posizione_volt2, offset_posizione_volt3]);

%% Calcolo Kb della posizione
% Calcolo di kb in modo che quando tocchi il fondo sia a 0.012 m

media_21V = mean(Test_21V(2,(end-500):end));
media_21_3V = mean(Test_21_3V(2,(end-500):end));
media_21_6V = mean(Test_21_6V(2,(end-500):end));
media_21_9V = mean(Test_21_9V(2,(end-500):end));
media_22_5V = mean(Test_22_5V(2,(end-500):end));
media_23V = mean(Test_23V(2,(end-500):end));

media1 = mean([media_21V, media_21_3V, media_21_6V, media_21_9V, media_22_5V, media_23V]);


media_23V_v2 = mean(Test_with_23V_v2(2,(end-500):end));
media_21V_v2 = mean(Test_with_21V_v2(2,(end-500):end));

media2 = mean([media_23V_v2, media_21V_v2]);

media_22_5V = mean(Test_with_22_5V(2,(end-500):end));
media_21_5V = mean(Test_with_21_5V(2,(end-500):end));
media_23V_v = mean(Test_23V_v(2,(end-500):end));
media_21V_v = mean(Test_21V_v(2,(end-500):end));

media3 = mean([media_22_5V, media_21_5V,media_23V_v , media_21V_v]);



media = mean([media1, media2, media3]);

Kb = y0 /  (media - offset_posizione);
