%per Windows 
addpath('..\..\..\..\function')
addpath('..\..\..\..\identificazione\identificazione_controllori\controllori_mag\second_task\State_space')
run('..\..\..\..\Model_Parameter.m')
add_data_volt('..\..\..\..\data\LQ\no_obs')

%per Mac
% addpath('../../../../function')
%addpath('../../../../identificazione/identificazione_controllori/controllori_mag/second_task/State_space')
% run('../../../../Model_Parameter.m')
% add_data_volt('../../../../data/LQ/no_obs')

%% No obs

T_end = LQ_Step_3mm(1,end);
out = sim("controllo_SS_no_obs2023b.slx");
index = T_end/0.002;
figure()
plot(LQ_Step_3mm(1,1:index), out.pos_sim(1:index)');
hold on
plot(LQ_Step_3mm(1,1:index), LQ_Step_3mm(2,1:index));
title('Time validation LQ without observer');
legend('Simulated position', 'Measured position');
hold off