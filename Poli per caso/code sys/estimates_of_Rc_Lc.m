clear; clc;
close all;

% Resistenza del current sense
Rs = 1; % Ohm

addpath('function');
add_data('/data/Step Test/Step Test without ball');

% Calcolo dell'offset (assumo sia la media del segnale a 0V)
offset = mean(Test_wb_0V(3, :));

% Estrazione dei dati e rimozione dell'offset
t1 = Test_wb_3V(1,:);
t2 = Test_wb_6V(1,:);
t3 = Test_wb_9V(1,:);
t4 = Test_wb_12V(1,:);
t5 = Test_wb_15V(1,:);
t6 = Test_wb_18V(1,:);
t7 = Test_wb_21V(1,:);
t8 = Test_wb_23V(1,:);

C1 = Test_wb_3V(3,:) - offset;
C2 = Test_wb_6V(3,:) - offset;
C3 = Test_wb_9V(3,:) - offset;
C4 = Test_wb_12V(3,:) - offset;
C5 = Test_wb_15V(3,:) - offset;
C6 = Test_wb_18V(3,:) - offset;
C7 = Test_wb_21V(3,:) - offset;
C8 = Test_wb_23V(3,:) - offset;

% Applico un filtro Savitzky-Golay per ridurre il rumore
C1_smooth = sgolayfilt(C1, 3, 11);
C2_smooth = sgolayfilt(C2, 3, 11);
C3_smooth = sgolayfilt(C3, 3, 11);
C4_smooth = sgolayfilt(C4, 3, 11);
C5_smooth = sgolayfilt(C5, 3, 11);
C6_smooth = sgolayfilt(C6, 3, 11);
C7_smooth = sgolayfilt(C7, 3, 11);
C8_smooth = sgolayfilt(C8, 3, 11);

% Plot dei segnali filtrati
figure;
hold on;
xlabel('Tempo (s)');
ylabel('Corrente (A)');
title('Fit delle risposte a gradino per diverse tensioni');
plot(t1, C1_smooth, 'DisplayName', 'Misura 3V');
plot(t2, C2_smooth, 'DisplayName', 'Misura 6V');
plot(t3, C3_smooth, 'DisplayName', 'Misura 9V');
plot(t4, C4_smooth, 'DisplayName', 'Misura 12V');
plot(t5, C5_smooth, 'DisplayName', 'Misura 15V');
plot(t6, C6_smooth, 'DisplayName', 'Misura 18V');
plot(t7, C7_smooth, 'DisplayName', 'Misura 21V');
plot(t8, C8_smooth, 'DisplayName', 'Misura 23V');
legend show;
hold off;

% Stima di R, L e tau
R_estimates = zeros(1, 8);
L_estimates = zeros(1, 8);
taus = zeros(1, 8);
voltages = [3, 6, 9, 12, 15, 18, 21, 23];
current_data = {C1_smooth, C2_smooth, C3_smooth, C4_smooth, C5_smooth, C6_smooth, C7_smooth, C8_smooth};
time_data = {t1, t2, t3, t4, t5, t6, t7, t8};

for i = 1:8
    t = time_data{i};
    C = current_data{i};
    
    % Trovo il valore finale della corrente come valore medio degli ultimi dati
    I_final = mean(C(end-50:end));
    
    % Trovo il valore iniziale (dovrebbe essere zero o molto vicino a zero)
    I_initial = C(1);
    
    % Calcolo la costante di tempo tau
    idx_rise = find(C > 0.632 * I_final, 1);  % Indice dove la corrente raggiunge il 63.2% del valore finale
    taus(i) = t(idx_rise)-1; %%%%NON MOLTO SICURO
    
    % Stima di R e L
    R_estimates(i) = (voltages(i) - I_final * Rs) / I_final;
    L_estimates(i) = taus(i) * (R_estimates(i) + Rs);
end

% Mostro i risultati stimati
disp('Stime della Resistenza R (Ohm):');
disp(R_estimates);

disp('Stime dell''Induttanza L (H):');
disp(L_estimates);

disp('Costanti di tempo Tau (s):');
disp(taus);

R_mean = mean([R_estimates(6), R_estimates(7)]);
L_mean = mean([L_estimates(6), L_estimates(7)]);
