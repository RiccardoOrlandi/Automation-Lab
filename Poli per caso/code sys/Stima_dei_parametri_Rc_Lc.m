clc
close all
clear

addpath('function');
add_data('\data\Step Test\Step Test with ball')

%Conversion of experimental values into MatLab variables
t1 = Test_3V(1,:);
t2 = Test_6V(1,:);
t3 = Test_9V(1,:);
t4 = Test_12V(1,:);
t5 = Test_15V(1,:);
C1 = Test_3V(3,:) + 0.016;
C2 = Test_6V(3,:) + 0.016;
C3 = Test_9V(3,:) + 0.016;
C4 = Test_12V(3,:) + 0.016;
C5 = Test_15V(3,:) + 0.016;
%% average of the asintotic value and evaluation of the transient 
mean_C1 = mean(C1(1001:end));
mean_C2 = mean(C2(1001:end));
mean_C3 = mean(C3(1001:end));
mean_C4 = mean(C4(1001:end));
mean_C5 = mean(C5(1001:end));
% Computation of the settling time
% caratteristica del circuito
C1_upper = 1.02 * mean_C1; %upper bound
C1_lower = 0.98 * mean_C1; %lower bound 

t_settling_C1_index = find(C1 >= C1_lower & C1 <= C1_upper, 1, 'first');
t_settling_C1 = t1(t_settling_C1_index) - 1;
tau_C1 = t_settling_C1/4; 

%stessa cosa per il secondo test
C2_upper = 1.02 * mean_C2;
C2_lower = 0.98 * mean_C2;

t_settling_C2_index = find(C2 >= C2_lower & C2 <= C2_upper, 1, 'first');
t_settling_C2 = t2(t_settling_C2_index) - 1;
tau_C2 = t_settling_C2/4;

fprintf('Costante di tempo caratteristica del transitorio considerando 3 V in input: %.3f s\nCostante di tempo caratteristica del transitorio considerando 6V in input: %.3f s\n', tau_C1, tau_C2);

%stessa cosa per il terzo test: 9V
C3_upper = 1.02 * mean_C3;
C3_lower = 0.98 * mean_C3;

t_settling_C3_index = find(C3 >= C3_lower & C3 <= C3_upper, 1, 'first');
t_settling_C3 = t3(t_settling_C3_index) - 1;
tau_C3 = t_settling_C3/4;

%stessa cosa per il quarto test: 12V
C4_upper = 1.02 * mean_C4;
C4_lower = 0.98 * mean_C4;

t_settling_C4_index = find(C4 >= C4_lower & C4 <= C4_upper, 1, 'first');
t_settling_C4 = t4(t_settling_C4_index) - 1;
tau_C4 = t_settling_C4/4;

%stessa cosa per il quinto test: 15V
C5_upper = 1.02 * mean_C5;
C5_lower = 0.98 * mean_C5;

t_settling_C5_index = find(C5 >= C5_lower & C5 <= C5_upper, 1, 'first');
t_settling_C5 = t5(t_settling_C5_index) - 1;
tau_C5 = t_settling_C5/4;

fprintf('Costante di tempo caratteristica del transitorio considerando 9 V in input: %.3f s\nCostante di tempo caratteristica del transitorio considerando 12V in input: %.3f s\n', tau_C3, tau_C4);
fprintf('Costante di tempo caratteristica del transitorio considerando 15V in input: %.3f s\n',tau_C5);
%% Ricavo le resistenze sui due esperimenti per valutarne la correttezza; tramite la legge  KVL 
% nota a priori poichè nostro input
V_in_1 = 3; 
V_in_2 = 6;
V_in_3 = 9;
V_in_4 = 12;
V_in_5 = 15;
% resistenza del sensore
Rs = 1;
%tensione misurata dal current sense resistor
Vs_1 = Rs * mean_C1;
Vs_2 = Rs * mean_C2;
Vs_3 = Rs * mean_C3;
Vs_4 = Rs * mean_C4;
Vs_5 = Rs * mean_C5;
Rc_1 = (V_in_1 - Vs_1)/mean_C1;
Rc_2 = (V_in_2 - Vs_2)/mean_C2;
Rc_3 = (V_in_3 - Vs_3)/mean_C3;
Rc_4 = (V_in_4 - Vs_4)/mean_C4;
Rc_5 = (V_in_5 - Vs_5)/mean_C5;
fprintf('Resistenza esperimento 3V: %.2f Ω\n Resistenza esperimento 6V : %.2f Ω\n', Rc_1,Rc_2);
fprintf('Resistenza esperimento 9V: %.2f Ω\n Resistenza esperimento 12V : %.2f Ω\n', Rc_3,Rc_4);
fprintf('Resistenza esperimento 15V: %.2f Ω\n',Rc_5);

%% Calcolo dell'Induttanza Valutata nel caso in cui la pallina non interferisca col campo magnetico
% La ricavo tramite il transitorio dato che la sua espressione è data da
% tau = L/R

Lc_1 = tau_C1 * (Rc_1+Rs);
Lc_2 = tau_C2 * (Rc_2+Rs);
Lc_3 = tau_C3 * (Rc_3+Rs);
Lc_4 = tau_C4 * (Rc_4+Rs);
Lc_5 = tau_C5 * (Rc_5+Rs);

fprintf('Induttanza esperimento 3V: %.2f H\n Induttanza esperimento 6V : %.2f H\n', Lc_1,Lc_2);
fprintf('Induttanza esperimento 9V: %.2f H\n Induttanza esperimento 12V : %.2f H\n', Lc_3,Lc_4);
fprintf('Induttanza esperimento 15V: %.2f H\n', Lc_5);

Lc_vect = [Lc_1, Lc_2, Lc_3, Lc_4, Lc_5];
Lc = mean(Lc_vect);
Rc_vect = [Rc_1, Rc_2, Rc_3, Rc_4, Rc_5];
Rc = mean(Rc_vect);

fprintf('Induttanza Lc : %.4f H\n Resistenza Rc: %.2f Ohm\n', Lc,Rc);

% % Parametri del solenoide
% mu_0 = 4*pi*10^-7;  % permeabilità del vuoto in H/m
% mu_r = 1;  % Permeabilità relativa (1 per vuoto, valore diverso per materiali ferromagnetici)
% N = 2450;  % Numero di spire
% A = pi*0.008^2;  % Area della sezione trasversale in m^2 (esempio: 1 cm^2)
% l = 0.0825;  % Lunghezza del solenoide in metri (esempio: 50 cm)
% 
% % Calcolare l'induttanza
% L = (mu_0 * mu_r * N^2 * A) / l;
% 
% % Visualizzare il risultato
% fprintf('L induttanza stimata è: %.4e H\n', L);

test = Test_21V; %scegli il test
volt= 21; %metti i volt del test
Rtot= Rc+Rs;
plot(test(1, :), test(3, :))
hold on
plot(test(1, :), volt/Rtot*ones(1, length(test)))
