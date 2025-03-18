clear all
close all
clc
add_data_volt('/data/Step Test/Step Test without ball');
add_data_volt('/data/Step Test/Step Test with ball');
offset_posizione_volt = mean(Test_0V(2,:));
offset_corrente_volt = mean(Test_wb_0V(3,:));


Kb =0.0086/ mean(Test_21V(2,(end-50):end)-offset_corrente_volt);