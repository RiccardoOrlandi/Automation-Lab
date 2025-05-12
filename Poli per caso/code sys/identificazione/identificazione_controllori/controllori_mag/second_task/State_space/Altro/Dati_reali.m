clear
clc
close all

add_data_volt('..\..\..\..\..\..\data\LQ')

test = LQ_v5;

figure()
plot(test(1, :), test(2,:))
grid on
figure()
plot(test(1, :), test(3,:))
grid on