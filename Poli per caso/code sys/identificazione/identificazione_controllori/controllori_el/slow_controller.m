clc
clear
close all

%%
%per Windows
% run('..\..\..\Model_Parameter.m')

%per Mac
run('../../../Model_Parameter.m')

%% controllore del circuito elettrico

s = tf('s');
polo = Rtot/Lc;
tau = 1/polo;
sys = tf(1, [Lc Rtot]);

% rltool(sys);
%% primo test: wc=130rad;pm=80,
kp = 0.15;
ki = 104;
kd = 0;
controller = kp + ki/s+ kd*s;

sys_cl = feedback(controller*sys, 1);
eig(sys_cl)

% figure()
% step(sys_cl)
% hold on
% step(sys)
% grid on
% legend('closed_loop', 'open_loop')
% hold off
% 
% figure()
% hold on
% bode(sys*controller);
% margin(sys*controller);
% legend('L(s) funzione ad anello');
% grid on 
% hold off
% 
% figure()
% hold on
% bode(sys)
% legend('Open_loop');
% grid on
% margin(sys)
% hold off
% 
% figure()
% hold on
% bode(sys_cl)
% legend('Closed_loop');
% grid on
% eig(sys_cl)
% 
% margin(sys_cl)
% hold off
[y, t] = step(sys_cl);
plot_Latex(t, y, 'Time [s]', 'Current [A]', 'Step Response', [0 1.2]);