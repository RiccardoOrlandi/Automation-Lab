%per Windows 
addpath('..\..\..\..\function')
addpath('..\..\..\..\identificazione\identificazione_controllori\controllori_mag\second_task\State_space')
run('..\..\..\..\Model_Parameter.m')
add_data_volt('..\..\..\..\data\PP\no_obs')
add_data_volt('..\..\..\..\data\PP\obs')

%per Mac
% addpath('../../../../function')
%addpath('../../../../identificazione/identificazione_controllori/controllori_mag/second_task/State_space')
% run('../../../../Model_Parameter.m')
% add_data_volt('../../../../data/PP/no_obs')
% add_data_volt('../../../../data/PP/obs')

%% No obs

T_end = Step_4mm_Sine_0_5mm_1radS_filtro_vel_pos_cur(1,end);
out = sim("controllo_SS_no_obs2023b.slx");
index = 27/0.002;
figure()
plot(Step_4mm_Sine_0_5mm_1radS_filtro_vel_pos_cur(1,1:index), out.pos_sim(1:index)');
hold on
plot(Step_4mm_Sine_0_5mm_1radS_filtro_vel_pos_cur(1,1:index), Step_4mm_Sine_0_5mm_1radS_filtro_vel_pos_cur(2,1:index));
title('Time validation Pole placement without observer');
legend('Simulated position', 'Measured position');
hold off

%% Obs

T_end_2 = Obs_PP_Step_3mm_6mm_5mm_polo5(1, end);
%out2 = sim("controllo_SS2023b.slx");
index2 = 40/0.002;
figure()
plot(Obs_PP_Step_3mm_6mm_5mm_polo5(1,1:index2), out2.pos_sim_obs(1:index2)');
hold on
plot(Obs_PP_Step_3mm_6mm_5mm_polo5(1,1:index2), Obs_PP_Step_3mm_6mm_5mm_polo5(2,1:index2));
title('Time validation Pole placement with observer');
legend('Simulated position', 'Measured position');
hold off

