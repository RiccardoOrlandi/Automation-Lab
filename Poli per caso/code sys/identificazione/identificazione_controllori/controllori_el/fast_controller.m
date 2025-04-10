clc
clear
close all

%%
%per Windows
run('..\..\..\Model_Parameter.m')

%per Mac
%run('../../../Model_Parameter.m')

%% controllore del circuito elettrico

s = tf('s');
polo = Rtot/Lc;
tau = 1/polo;
sys = tf(1, [Lc Rtot]);

Vref = 15;
%% primo test: wc=130rad;pm=80,
kp = 46.0161;
ki = 2117.9265;
kd = 0;

% kp = 199.4;
% ki = 4572.3;
% kd = 0;

controller = kp + ki/s+ kd*s;

sys_cl = feedback(controller*sys, 1);

rlocus(sys_cl);

figure()
step(sys_cl)
hold on
step(sys)
grid on
legend('cl', 'ol')
hold off

figure()
bode(sys)
hold on
grid on
bode(controller*sys)

poli = eig(sys_cl)
over = exp(-0.99*pi/sqrt(1-0.99^2));
margin(controller*sys)


%% Plot delle uscite
out = sim('controller_electric.slx');

back = out.back;
clamp = out.clamp;
no_sat = out.no_sat;
ref = out.ref;
sat = out.sat;
t = out.tout;

figure()

plot(t,back,'LineWidth',1.5)
grid on
xlim([0,0.15])
% ylim([-0.8,1.2])
title('Electric Controller','FontSize',14,'Interpreter','latex')
xlabel('Time [s]','FontSize',14,'Interpreter','latex')
ylabel('volt','FontSize',14,'Interpreter','latex')
hold on

plot(t,clamp,'LineWidth',1.5)
plot(t,no_sat,'LineWidth',1.5)
plot(t,ref,'LineWidth',1.5)
plot(t,sat,'LineWidth',1.5)

legend('back calculation','clamping','no sat','reference','sat','FontSize',14,'Interpreter','latex')