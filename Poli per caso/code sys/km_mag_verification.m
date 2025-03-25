clear all
close all
clc

run('Model_Parameter.m')

addpath('function')
add_data('\data\Step Test\Step Test with ball');
add_data('\data\Step Test\18_03_2025_v2\with ball');
add_data('\data\Step Test\18_03_2024\with_ball');

%% mostrare diversi plot
Ts = 0.002;
x0 = [0 0 0]';
Tend = 2;
N = Tend/0.002;

delay = 1/0.002;
N2 = N-delay;

%% Plot per 21 V
t = 0:0.002:(N-1)*0.002;
u = 21;
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

figure()
plot(t, Test_21V(2, 1:N))
hold on
plot(t, Test_21V_v(2, 1:N))
plot(t, Test_with_21V_v2(2, 1:N))

plot(t(delay+1:end), y(2, 1:N2))
grid on
title('Position (21V)')
legend('Test 21V','Test 21V v', 'Test with 21V v2', 'modello')
hold off

%% Plot per 23 V

t = 0:0.002:(N-1)*0.002;
u = 23;
[tvec, x, y] = FFD(Ts, Tend-1, x0, u, theta);

figure()
plot(t, Test_23V(2, 1:N))
hold on
plot(t, Test_23V_v(2, 1:N))
plot(t, Test_with_23V_v2(2, 1:N))
plot(t(delay+1:end), y(2, 1:N2))
grid on
title('Position (23V)')
legend('Test 23V','Test 23V v', 'Test with 23V v2', 'modello')
hold off



%% subplot 2
t = 0:0.002:(N-1)*0.002;
modello3 = zeros(1, N2);
u =22.5;
[tvec, x, y] = FFD(Ts, Tend, x0, u, theta);

figure()
subplot(3, 1, 1)
plot(t, Test_22_5V(2, 1:N))
hold on
plot(t, Test_with_22_5V(2, 1:N))
plot(t(delay+1:end), y(2, 1:N2))
legend('Test 22 5V', 'Test with 22 5V',  'modello22.5')
grid on
hold off

u = 21.5;
modello6 = zeros(1, N2);
[tvec, x, y] = FFD(Ts, Tend, x0, u, theta);

subplot(3, 1, 2)
plot(t, Test_with_21_5V(2, 1:N))
hold on
plot(t(delay+1:end), y(2, 1:N2))
legend('Test with 21 5V', 'modello21.5')
grid on
hold off



u = 21.9;
modello19 = zeros(1, N2);
[tvec, x, y] = FFD(Ts, Tend, x0, u, theta);
subplot(3, 1, 3)

hold on
plot(t, Test_21_9V(2, 1:N))
plot(t(delay+1:end), y(2, 1:N2))
legend('Test 21 9V', 'modello21.9')
grid on
hold off
