clear
close all
clc

%%
%per Windows
addpath('..\..\..\..\..\function');

run('..\..\..\..\..\Model_Parameter.m') % In questa funzione sono contenuti tutti i paramentri del modello

x0 = 0;

sys = lin_MPC(x0, theta);

Ts = 0.002;
mpcobj = mpc(sys, Ts);
mpcobj.PredictionHorizon = 10;
mpcobj.ManipulatedVariables(1).Min = 0;
mpcobj.ManipulatedVariables(1).Max = 23;
mpcobj.OutputVariables(1).Min = 0;
mpcobj.OutputVariables(1).Max = 0.012;
xmpc = mpcstate(mpcobj);
