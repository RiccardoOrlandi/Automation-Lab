clc
clear
close all

%%
run('Model_Parameter.m')

%% controllore del circuito elettrico

s = tf('s');
polo = Rtot/Lc;
tau = 1/polo;
sys = tf(1, [Lc Rtot]);

%% primo test: wc=130rad;pm=80,
kp = 46.0161;
ki = 2117.9265;
kd = 0;
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

eig(sys_cl)

margin(controller*sys)
