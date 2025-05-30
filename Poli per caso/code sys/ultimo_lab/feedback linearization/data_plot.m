clc
clear
close all


run('..\..\Model_Parameter.m')
add_data_volt('Data')


% FEEDBACK LINEARIZATION delle 9:55
figure()
start = 800;
t = f_lin_step_4_5mm(1, :);
ref = [0*ones(1, floor(2/0.002)) 0.004*ones(1, floor(9.8/0.002)) 0.005*ones(1, floor((t(end)-11.8+2*0.002)/0.002))];
t = f_lin_step_4_5mm(1, start:end)-start*0.002+0.002;
y = f_lin_step_4_5mm(2, start:end);

plot_Latex(t, y, 'Time [s]', 'Position [m]', 'Feedback Linearization', [-0.001, 0.008])

hold on
plot_Latex(t, ref(1, start:end), 'Time [s]', 'Position [m]', 'Feedback Linearization', [-0.001, 0.008])
xlim([0, t(end)])
legend('Ball', 'Reference')
hold off

% BUONO senza RLS MA C'E ALTRO 9:38
% figure()
% plot(f_lin_step_3_4_6mm(1, :), f_lin_step_3_4_6mm(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('f_lin_step_3_4_6mm')

% BRUTTINO ma fatto alle 10 con RLS
% figure()
% plot(f_lin_RLS_step_3_4mm(1, :), f_lin_RLS_step_3_4mm(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('f_lin_RLS_step_3_4mm')

% FEEDBACK LINEARIZATION CON RLS
figure()
t_end = floor(20/0.002);
plot_Latex(f_lin_RLS_step_3_4_5mm(1, 1:t_end), f_lin_RLS_step_3_4_5mm(2, 1:t_end), 'Time [s]', 'Position [m]', 'Feedback Linearization', [-0.001, 0.008])
t = f_lin_RLS_step_3_4_5mm(1, 1:t_end);
ref = [0*ones(1, floor(2/0.002)) ...
    0.003*ones(1, floor(7.7/0.002)) ...
    0.004*ones(1, floor(5.58/0.002)) ...
    0.005*ones(1, floor((t(end)-15.28+2*0.002)/0.002))];
hold on
plot_Latex(t, ref(1, 1:t_end), 'Time [s]', 'Position [m]', 'Feedback Linearization RLS', [-0.001, 0.008])
legend('Ball', 'Reference')
hold off

% TEST COMPLESSO INTERESSANTE PER LA STIMA
figure()
plot_Latex(f_lin_RLS_step4_4sin20_05_5sin20_4step_3_2(1, :), f_lin_RLS_step4_4sin20_05_5sin20_4step_3_2(2, :),...
    'Time [s]', 'Position [m]', 'Feedback Linearization', [-0.001, 0.008])
t = f_lin_RLS_step4_4sin20_05_5sin20_4step_3_2(1, :);
load('ref_complesso.mat')
ref = out.test_complesso_stima(1:length(t), :)';
hold on
plot_Latex(t, ref, 'Time [s]', 'Position [m]', 'Adaptive Feedback Linearization', [-0.001, 0.008])
legend('Ball', 'Reference')
hold off

% STIMA DI R
figure()
t_end = floor(20/0.002);
t = f_lin_RLS_step4_4sin20_05_5sin20_4step_3_2(1, 1:t_end);
load('R_est.mat')
R = R_est(1:length(t), 1)';
plot_Latex(t, R,...
    'Time [s]', 'Position [m]', 'Feedback Linearization', [5, 12])
hold on
ref = Rtot*ones(1, length(t));
plot_Latex(t, ref, 'Time [s]', 'Resistance [ohm]', 'R estimation', [5, 12])
legend('R estimation', 'R model')
hold off



figure()
plot(f_lin_RLS_4mm(1, :), f_lin_RLS_4mm(2, :))
grid on
ylim([-0.001, 0.013])
title('f_lin_RLS_4mm')

% BRUTTO
% figure()
% plot(data_23_May_2025_12_59_02(1, :), data_23_May_2025_12_59_02(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('data_23_May_2025_12_59_02')

% CHISSA COSA è SUCCESSO
% figure()
% plot(data_23_May_2025_12_33_11(1, :), data_23_May_2025_12_33_11(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('data_23_May_2025_12_33_11')

% BRUTTO
% figure()
% plot(data_23_May_2025_12_31_30(1, :), data_23_May_2025_12_31_30(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('data_23_May_2025_12_31_30')


% BUONINO ma sempre senza RLS credo
% figure()
% plot(data_23_May_2025_10_10_42(1, :), data_23_May_2025_10_10_42(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('data_23_May_2025_10_10_42')

% BRUTTINO
% figure()
% plot(data_23_May_2025_10_06_47(1, :), data_23_May_2025_10_06_47(2, :))
% grid on
% ylim([-0.001, 0.013])
% title('data_23_May_2025_10_06_47')