clc
clear
close all

%%
%per Windows
%run('..\..\..\Model_Parameter.m')

%per Mac
run('../../../Model_Parameter.m')

%% Modello elettrico

s = tf('s');
Gel = tf(1, [Lc Rtot]);
%% Controllore 1
%%
kp = 46.0161;
ki = 2117.9265;
controller_el1 = kp + ki/s;

%% Controllore 2
%%
kp2 = 29.924;
ki2 = 37.79*29.924;
controller_el2 = kp2 + ki2/s;

%% Controllore 3
%%
kp3 = 67.02;
ki3 = 1400;
controller_el3 = kp3 + ki3/s;
%% Controllore 4
 C=28.913*(s+34.87)/s;
%% Plot delle uscite
%%
Vref = 12;
stop_sim = 0.2;

sim_controller = 'controller_electric';
load_system(sim_controller);
set_param(sim_controller, 'StopTime', num2str(stop_sim));
out = sim(sim_controller);

%primo controllore
back = out.back;
clamp = out.clamp;
no_sat = out.no_sat;
ref = out.ref;
sat = out.sat;
t = out.tout;

u_back = out.u_back;
u_clamp = out.u_clamp;
u_no_sat = out.u_no_sat;
u_sat = out.u_sat;

% secondo controllore
back2 = out.back2;
clamp2 = out.clamp2;
no_sat2 = out.no_sat2;
sat2 = out.sat2;

u_back2 = out.u_back2;
u_clamp2 = out.u_clamp2;
u_no_sat2 = out.u_no_sat2;
u_sat2 = out.u_sat2;


figure()
%controllore 1
subplot(2, 2, 1)
plot(t,back,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,ref(1)*1.2])
title('Controller ver1','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('volt','FontSize',14,'Interpreter','latex')
hold on

plot(t,clamp,'LineWidth',1.5)
plot(t,no_sat,'LineWidth',1.5)
plot(t,ref,'LineWidth',1.5)
plot(t,sat,'LineWidth',1.5)

legend('back calculation','clamping','no sat','reference','sat','FontSize',14,'Interpreter','latex')

subplot(2, 2, 3)
plot(t,u_back,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,70])
title('Control Variable ver1','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('volt','FontSize',14,'Interpreter','latex')
hold on

plot(t,u_clamp,'LineWidth',1.5)
plot(t,u_no_sat,'LineWidth',1.5)
plot(t,u_sat,'LineWidth',1.5)

legend('back calculation','clamping','no sat','sat','FontSize',14,'Interpreter','latex')

%secondo Controllore
subplot(2, 2, 2)
plot(t,back2,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,ref(1)*1.2])
title('Controller ver2','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('volt','FontSize',14,'Interpreter','latex')
hold on

plot(t,clamp2,'LineWidth',1.5)
plot(t,no_sat2,'LineWidth',1.5)
plot(t,ref,'LineWidth',1.5)
plot(t,sat2,'LineWidth',1.5)

legend('back calculation','clamping','no sat','reference','sat','FontSize',14,'Interpreter','latex')

subplot(2, 2, 4)
plot(t,u_back2,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,70])
title('Control Variable ver2','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('volt','FontSize',14,'Interpreter','latex')
hold on

plot(t,u_clamp2,'LineWidth',1.5)
plot(t,u_no_sat2,'LineWidth',1.5)
plot(t,u_sat2,'LineWidth',1.5)

legend('back calculation','clamping','no sat','sat','FontSize',14,'Interpreter','latex')
%%
figure()
%controllore 1
subplot(2, 1, 1)
plot(t,back,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,ref(1)*1.3])
title('Output','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('Current [A]','FontSize',14,'Interpreter','latex')
hold on

plot(t,clamp,'LineWidth',1.5)
plot(t,no_sat,'LineWidth',1.5)
plot(t,ref,'LineWidth',1.5)
plot(t,sat,'LineWidth',1.5)

legend('Back-Calculation','Clamping','No Saturation','Reference','Saturation','FontSize',14,'Interpreter','latex')
subplot(2, 1, 2)
plot(t,u_back,'LineWidth',1.5)
grid on
xlim([0,0.15])
ylim([0,70])
title('Control Variable','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('Tension [V]','FontSize',14,'Interpreter','latex')
hold on

plot(t,u_clamp,'LineWidth',1.5)
plot(t,u_no_sat,'LineWidth',1.5)
plot(t,u_sat,'LineWidth',1.5)

legend('Back-Calculation','Clamping','No Saturation','Saturation','FontSize',14,'Interpreter','latex')