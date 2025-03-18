clc
clear
close all

%% controllore del circuito elettrico
run('Model_Parameter.m')
s = tf('s');
polo = Rtot/Lc;
tau=1/polo;
sys = tf(1, [Lc Rtot]);
% ki= 3.48e+03;
% kp = 60.5;

% kp = C.kp;
% ki = C.ki;
% kd = C.kd;


kp = 40;
ki = 20;
kd = 0;
controller = kp + ki/s+ kd*s;

% controller = 10*(Lc*s + Rtot)/(s*(s+500));
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

