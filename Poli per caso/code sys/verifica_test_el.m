clc
clear
close all

addpath('function')
add_data('\data\Step Test\Step Test with ball');
add_data('\data\Step Test\Step Test without ball');
add_data('\data\Step Test\18_03_2024\without_ball');
add_data('\data\Step Test\18_03_2024\with_ball');

figure()
plot(Test_15V(1, :), Test_15V(3, :))
hold on
plot(Test_wb_15V(1, :), Test_wb_15V(3, :))
plot(Test_wb_15V_v(1, :), Test_wb_15V_v(3, :))
plot(Test_15V_v(1, :), Test_15V_v(3, :))
title('15 V')
legend('with', 'without', 'new wb', 'new ball')
grid on
hold off 

figure()
plot(Test_18V(1, :), Test_18V(3, :))
hold on
plot(Test_wb_18V(1, :), Test_wb_18V(3, :))
plot(Test_wb_18V_v(1, :), Test_wb_18V_v(3, :))
plot(Test_18V_v(1, :), Test_18V_v(3, :))
title('18 V')
legend('with', 'without', 'new wb', 'new ball')
grid on
hold off

figure()
hold on
plot(Test_21V(1, :), Test_21V(3, :))
plot(Test_wb_21V(1, :), Test_wb_21V(3, :))
plot(Test_wb_21V_v(1, :), Test_wb_21V_v(3, :))
plot(Test_21V_v(1, :), Test_21V_v(3, :))
title('21 V')
legend('with', 'without', 'new wb', 'new ball')
grid on
hold off


figure()
hold on
plot(Test_23V(1, :), Test_23V(3, :))
plot(Test_wb_23V(1, :), Test_wb_23V(3, :))
plot(Test_wb_23V_v(1, :), Test_wb_23V_v(3, :))
plot(Test_23V_v(1, :), Test_23V_v(3, :))
title('23 V')
legend('with', 'without', 'new wb', 'new ball')
grid on
hold off
