clear all
close all
clc

%per Windows 
% run('..\..\Model_Parameter.m')
%addpath('..\..\function\') 
% add_data('..\..\data\Step Test\Step Test without ball');
% add_data('..\..\data\Step Test\Step Test with ball');
% add_data('..\..\data\Step Test\18_03_2025_v2\without ball');
% add_data('..\..\data\Step Test\18_03_2025_v2\with ball');
% add_data('..\..\data\Step Test\18_03_2024\without_ball');
% add_data('..\..\data\Step Test\18_03_2024\with_ball');

%per Mac
run('../../Model_Parameter.m')
addpath('../../function/')
add_data('../../data/Step Test/Step Test without ball');
add_data('../../data/Step Test/Step Test with ball');
add_data('../../data/Step Test/18_03_2025_v2/without ball');
add_data('../../data/Step Test/18_03_2025_v2/with ball');
add_data('../../data/Step Test/18_03_2024/without_ball');
add_data('../../data/Step Test/18_03_2024/with_ball');

%% mostrare diversi plot
tin = 0.9;
tend = 1.3;

Nin = floor(tin/0.002);
N = tend/0.002-1;

delay = round((1-tin)/0.002, 0);
N2 = N-delay;
t = 0:0.002:(N-Nin)*0.002;
%% Plot per 15 V

modello = zeros(1, length(t));
u = 15;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(-(Rtot/Lc)*t(i)));
end

figure()
plot_Latex(t, Test_15V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);
hold on
plot_Latex(t, Test_15V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);

plot_Latex(t, Test_wb_15V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);
plot_Latex(t, Test_wb_15V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);
plot_Latex(t, Test_with_15V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);
plot_Latex(t, Test_without_15V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);
plot_Latex(t(delay+2:end), modello(1, 1:length(t)-delay-1), 'Time [s]', 'Current [A]', 'Test (15 V)', [0, 1.8]);

grid on
legend('Test 1', 'Test 2', 'Test 3', 'Test 4', 'Test 5', 'Test 6', 'Model')
hold off

%% Plot per 18 V
modello = zeros(1, length(t));
u = 18;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
figure()
plot_Latex(t, Test_18V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
hold on
plot_Latex(t, Test_18V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
plot_Latex(t, Test_wb_18V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
plot_Latex(t, Test_wb_18V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
plot_Latex(t, Test_with_18V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
plot_Latex(t, Test_without_18V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2]);
plot_Latex(t(delay+2:end), modello(1, 1:length(t)-delay-1), 'Time [s]', 'Current [A]', 'Test (18 V)', [0, 2.1]);
hold off
% figure()
% plot(t, Test_18V(3, 1:N))
% hold on
% plot(t, Test_18V_v(3, 1:N))
% plot(t, Test_wb_18V(3, 1:N))
% plot(t, Test_wb_18V_v(3, 1:N))
% plot(t, Test_with_18V_v2(3, 1:N))
% plot(t, Test_without_18V_v2(3, 1:N))
% plot(t(delay+1:end), modello(1, 1:N2))
grid on
legend('Test 1','Test 2', 'Test 3', 'Test 4', 'Test 5', 'Test 6', 'Model')
hold off

%% Plot per 21 V
modello = zeros(1, length(t));
u = 21;
for i = 1:length(modello)
    modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
figure()
plot_Latex(t, Test_21V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);
hold on
plot_Latex(t, Test_21V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);
plot_Latex(t, Test_wb_21V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);
plot_Latex(t, Test_wb_21V_v(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);
plot_Latex(t, Test_with_21V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);
plot_Latex(t, Test_without_21V_v2(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.3]);

plot_Latex(t(delay+2:end), modello(1, 1:length(t)-delay-1), 'Time [s]', 'Current [A]', 'Test (21 V)', [0, 2.5]);
hold off 
grid on

% figure()
% plot(t, Test_21V(3, 1:N))
% hold on
% plot(t, Test_21V_v(3, 1:N))
% plot(t, Test_wb_21V(3, 1:N))
% plot(t, Test_wb_21V_v(3, 1:N))
% plot(t, Test_with_21V_v2(3, 1:N))
% plot(t, Test_without_21V_v2(3, 1:N))
% 
% plot(t(delay+1:end), modello(1, 1:N2))
% grid on

legend('Test 1','Test 2', 'Test 3', 'Test 4', 'Test 5', 'Test 6', 'Model')

% %% Plot per 23 V
% t = 0:0.002:(N-1)*0.002;
% modello= zeros(1, N2);
% u = 23;
% for i = 1:length(modello)
%     modello(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
% end
% 
% figure()
% plot(t, Test_23V(3, Nin:N))
% hold on
% plot(t, Test_23V_v(3, Nin:N))
% plot(t, Test_wb_23V(3, Nin:N))
% plot(t, Test_wb_23V_v(3, Nin:N))
% plot(t, Test_with_23V_v2(3, Nin:N))
% plot(t, Test_without_23V_v2(3, Nin:N))
% plot(t(delay+1:end), modello(1, 1:N2))
% grid on
% title('Current (23V)')
% legend('Test 23V','Test 23V v', 'Test wb 23V', 'Test wb 23V v', 'Test with 23V v2', 'Test without 23V v2', 'modello')
% hold off

%% subplot 
modello3 = zeros(1, length(t));
u = 3;
for i = 1:length(modello3)
    modello3(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

figure()
subplot(3, 2, 1)
plot_Latex(t, Test_wb_3V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (3 V)', [0, 0.4]);
% plot(t, Test_wb_3V(3, Nin:N))
hold on
plot_Latex(t, Test_3V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (3 V)', [0, 0.4]);
% plot(t, Test_3V(3, Nin:N))
plot_Latex(t(delay+2:end), modello3(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (3 V)', [0, 0.4]);
% plot(t(delay+2:end), modello3(1, 1:length(t)-delay-1))
legend('Test 1', 'Test 2', 'Model')
grid on
hold off


u = 6;
modello6 = zeros(1, length(t));
for i = 1:length(modello)
    modello6(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

subplot(3, 2, 2)
plot_Latex(t, Test_6V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
% plot(t, Test_6V(3, 1:N))
hold on
plot_Latex(t, Test_wb_6V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
% plot(t, Test_wb_6V(3, 1:N))
plot_Latex(t(delay+2:end), modello6(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (6 V)', [0, 0.7]);
% plot(t(delay+1:end), modello6(1, 1:N2))
legend('Test 1', 'Test 2', 'Model')
grid on
hold off


u = 9;
modello9 = zeros(1, length(t));
for i = 1:length(modello)
    modello9(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end

subplot(3, 2, 3)
plot_Latex(t, Test_wb_9V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
hold on
plot_Latex(t, Test_9V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 1.1]);
plot_Latex(t(delay+2:end), modello9(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (9 V)', [0, 1.1]);
legend('Test 1', 'Test 2', 'Model')
grid on
hold off

u = 12;
modello12 = zeros(1, length(t));
for i = 1:length(modello)
    modello12(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 4)
plot_Latex(t, Test_12V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
hold on
plot_Latex(t, Test_wb_12V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 1.1]);
plot_Latex(t(delay+2:end), modello12(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (12 V)', [0, 1.5]);
legend('Test 1', 'Test 2', 'Model')
grid on
hold off


u = 16;
modello16 = zeros(1, length(t));
for i = 1:length(modello)
    modello16(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 5)
plot_Latex(t, Test_with_16V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
hold on
plot_Latex(t, Test_without_16V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 1.1]);
plot_Latex(t(delay+2:end), modello16(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (16 V)', [0, 2]);
legend('Test 1', 'Test 2', 'Model')
grid on
hold off

u = 19;
modello19 = zeros(1, length(t));
for i = 1:length(modello)
    modello19(1, i) = u/Rtot*(1-exp(1)^(-(Rtot/Lc)*t(i)));
end
subplot(3, 2, 6)
plot_Latex(t, Test_19V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 0.7]);
hold on
plot_Latex(t, Test_without_19V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 1.1]);
plot_Latex(t, Test_with_19V(3, Nin:N), 'Time [s]', 'Current [A]', 'Test (6 V)', [0, 1.1]);
plot_Latex(t(delay+2:end), modello19(1, 1:length(t)-delay-1), '[s]', '[A]', 'Test (19 V)', [0, 2.2]);
legend('Test 1', 'Test 2','Test 3', 'Model')
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








