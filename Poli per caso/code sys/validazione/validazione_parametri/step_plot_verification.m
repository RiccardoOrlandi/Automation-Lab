clear all
close all
clc

%per Windows 
run('..\..\Model_Parameter.m')

add_data('..\..\data\Step Test\Step Test without ball');
add_data('..\..\data\Step Test\Step Test with ball');
add_data('..\..\data\Step Test\18_03_2025_v2\without ball');
add_data('..\..\data\Step Test\18_03_2025_v2\with ball');
add_data('..\..\data\Step Test\18_03_2024\without_ball');
add_data('..\..\data\Step Test\18_03_2024\with_ball');

%per Mac
% run('../../Model_Parameter.m')
% 
% add_data('../../data/Step Test/Step Test without ball');
% add_data('../../data/Step Test/Step Test with ball');
% add_data('../../data/Step Test/18_03_2025_v2/without ball');
% add_data('../../data/Step Test/18_03_2025_v2/with ball');
% add_data('../../data/Step Test/18_03_2024/without_ball');
% add_data('../../data/Step Test/18_03_2024/with_ball');

%% mostrare diversi plot
tend = 2;
N = tend/0.002;

delay = 1/0.002;
N2 = N-delay;
%% Plot per 15 V
t = 0:0.002:(N-1)*0.002;
modello = zeros(1, N2);
u = 15;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(-(Rtot/Lc)*t(i)));
end

figure()
plot(t, Test_15V(3, 1:N))
hold on
plot(t, Test_15V_v(3, 1:N))
plot(t, Test_wb_15V(3, 1:N))
plot(t, Test_wb_15V_v(3, 1:N))
plot(t, Test_with_15V_v2(3, 1:N))
plot(t, Test_without_15V_v2(3, 1:N))
plot(t(delay+1:end), modello(1, 1:N2))
grid on
title('Current (15V)')
legend('Test 15V', 'Test 15V v', 'Test wb 15V', 'Test wb 15V v', 'Test with 15V v2', 'Test without 15V v2', 'modello')
hold off

%% Plot per 18 V
t = 0:0.002:(N-1)*0.002;
modello= zeros(1, N2);
u = 18;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
plot(t, Test_18V(3, 1:N))
hold on
plot(t, Test_18V_v(3, 1:N))
plot(t, Test_wb_18V(3, 1:N))
plot(t, Test_wb_18V_v(3, 1:N))
plot(t, Test_with_18V_v2(3, 1:N))
plot(t, Test_without_18V_v2(3, 1:N))
plot(t(delay+1:end), modello(1, 1:N2))
grid on
title('Current (18V)')
legend('Test 18V','Test 18V v', 'Test wb 18V', 'Test wb 18V v', 'Test with 18V v2', 'Test without 18V v2', 'modello')
hold off

%% Plot per 21 V
t = 0:0.002:(N-1)*0.002;
modello= zeros(1, N2);
u = 21;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
plot(t, Test_21V(3, 1:N))
hold on
plot(t, Test_21V_v(3, 1:N))
plot(t, Test_wb_21V(3, 1:N))
plot(t, Test_wb_21V_v(3, 1:N))
plot(t, Test_with_21V_v2(3, 1:N))
plot(t, Test_without_21V_v2(3, 1:N))

plot(t(delay+1:end), modello(1, 1:N2))
grid on
title('Current (21V)')
legend('Test 21V','Test 21V v', 'Test wb 21V', 'Test wb 21V v', 'Test with 21V v2', 'Test without 21V v2', 'modello')
hold off

%% Plot per 23 V
t = 0:0.002:(N-1)*0.002;
modello= zeros(1, N2);
u = 23;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
plot(t, Test_23V(3, 1:N))
hold on
plot(t, Test_23V_v(3, 1:N))
plot(t, Test_wb_23V(3, 1:N))
plot(t, Test_wb_23V_v(3, 1:N))
plot(t, Test_with_23V_v2(3, 1:N))
plot(t, Test_without_23V_v2(3, 1:N))
plot(t(delay+1:end), modello(1, 1:N2))
grid on
title('Current (23V)')
legend('Test 23V','Test 23V v', 'Test wb 23V', 'Test wb 23V v', 'Test with 23V v2', 'Test without 23V v2', 'modello')
hold off

%% subplot 
t = 0:0.002:(N-1)*0.002;
modello3 = zeros(1, N2);
u = 3;
for i = 1:length(modello)
    modello3(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
subplot(3, 2, 1)
plot(t, Test_wb_3V(3, 1:N))
hold on
plot(t, Test_3V(3, 1:N))
plot(t(delay+1:end), modello3(1, 1:N2))
legend('Test wb 3V', 'Test 3V', 'modello3')
grid on
hold off


u = 6;
modello6 = zeros(1, N2);
for i = 1:length(modello)
    modello6(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

subplot(3, 2, 2)
plot(t, Test_6V(3, 1:N))
hold on
plot(t, Test_wb_6V(3, 1:N))
plot(t(delay+1:end), modello6(1, 1:N2))
legend('Test 6V', 'Test wb 6V', 'modello6')
grid on
hold off


u = 9;
modello9 = zeros(1, N2);
for i = 1:length(modello)
    modello9(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 3)
plot(t, Test_wb_9V(3, 1:N))
hold on
plot(t, Test_9V(3, 1:N))
plot(t(delay+1:end), modello9(1, 1:N2))
legend('Test wb 9V', 'Test 9V', 'modello9')
grid on
hold off

u = 12;
modello12 = zeros(1, N2);
for i = 1:length(modello)
    modello12(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 4)
plot(t, Test_12V(3, 1:N))
hold on
plot(t, Test_wb_12V(3, 1:N))
plot(t(delay+1:end), modello12(1, 1:N2))
legend('Test 12V', 'Test wb 12V', 'modello12')
grid on
hold off

u = 16;
modello16 = zeros(1, N2);
for i = 1:length(modello)
    modello16(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 5)
plot(t, Test_with_16V(3, 1:N))
hold on
plot(t, Test_without_16V(3, 1:N))
plot(t(delay+1:end), modello16(1, 1:N2))
legend('Test with 16V', 'Test without 16V', 'modello16')
grid on
hold off



u = 19;
modello19 = zeros(1, N2);
for i = 1:length(modello)
    modello19(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 6)
plot(t, Test_19V(3, 1:N))
hold on
plot(t, Test_without_19V(3, 1:N))
plot(t, Test_with_19V(3, 1:N))
plot(t(delay+1:end), modello19(1, 1:N2))
legend('Test 19V', 'Test without 19V', 'Test with 19V', 'modello19')
grid on
hold off


%% subplot 2
t = 0:0.002:(N-1)*0.002;
modello3 = zeros(1, N2);
u =22.5;
for i = 1:length(modello)
    modello3(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
subplot(3, 2, 1)
plot(t, Test_22_5V(3, 1:N))
hold on
plot(t, Test_with_22_5V(3, 1:N))
plot(t, Test_without_22_5(3, 1:N))
plot(t(delay+1:end), modello3(1, 1:N2))
legend('Test 22 5V', 'Test with 22 5V','Test without 22 5',  'modello22.5')
grid on
hold off

u = 21.5;
modello6 = zeros(1, N2);
for i = 1:length(modello)
    modello6(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

subplot(3, 2, 2)
plot(t, Test_with_21_5V(3, 1:N))
hold on
plot(t, Test_without_21_5(3, 1:N))
plot(t(delay+1:end), modello6(1, 1:N2))
legend('Test with 21 5V', 'Test without 21 5', 'modello6')
grid on
hold off
% 
% 

u = 20.5;
modello9 = zeros(1, N2);
for i = 1:length(modello)
    modello9(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 3)
plot(t, Test_20_5V(3, 1:N))
hold on

plot(t(delay+1:end), modello9(1, 1:N2))
legend('Test 20 5V', 'modello20.5')
grid on
hold off




u = 20;
modello12 = zeros(1, N2);
for i = 1:length(modello)
    modello12(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 4)
plot(t, Test_20V(3, 1:N))
hold on
plot(t(delay+1:end), modello12(1, 1:N2))
legend('Test 20V', 'modello20')
grid on
hold off

u = 21.3;
modello16 = zeros(1, N2);
for i = 1:length(modello)
    modello16(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 5)
plot(t, Test_21_3V(3, 1:N))
hold on

plot(t(delay+1:end), modello16(1, 1:N2))
legend('Test 21 3V', 'modello21.3')
grid on
hold off


u = 21.9;
modello19 = zeros(1, N2);
for i = 1:length(modello)
    modello19(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 6)

hold on
plot(t, Test_21_9V(3, 1:N))
plot(t(delay+1:end), modello19(1, 1:N2))
legend('Test 21 9V', 'modello21.9')
grid on
hold off








