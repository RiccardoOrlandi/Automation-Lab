close all
clear all
%%

addpath('function')
run('Model_Parameter.m')
u=21.6;
Ts=0.002;
Tend=10;
x0 =[0,0,0];
[tvec, x, y] = ModelOde(Ts, Tend, x0, u, theta);
plotModel(tvec, [tvec; x(1,:); x(2,:)]); % se usi la funzione di plot precedente
