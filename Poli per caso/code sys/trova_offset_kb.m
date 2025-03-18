clear all
close all
clc
add_data_volt('/data/Step Test/Step Test without ball');
offset_posizione_volt = mean(Test_wb_0V(2,:));
offset_corrente_volt = mean(Test_wb_0V(3,:));

add_data_volt('/data/Step Test/Step Test with ball');
Kb = 0.0086 / (mean([Test_21V(2,(end-50):end), Test_21_3V(2,(end-50):end), Test_21_6V(2,(end-50):end), Test_21_9V(2,(end-50):end), Test_20V(2,(end-50):end), Test_20_5V(2,(end-50):end)], 'all') - offset_corrente_volt);
