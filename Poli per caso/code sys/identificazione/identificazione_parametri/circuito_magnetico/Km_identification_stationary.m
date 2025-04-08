clear all 
close all

%per Windows
addpath('..\..\..\function')
add_data('..\..\..\data/Step test/04_04_2025');
run('..\..\..\Model_Parameter.m')

%per Mac
addpath('../../../function')
add_data('../../../data/Step test/04_04_2025');
run('../../../Model_Parameter.m')

%% T21_3V
data = T21_3V;

tmin = 1;  % secondi
tmax = 7;  % secondi
Ts = 0.002;  % tempo di campionamento

imin = tmin/Ts + 1;
imax = tmax / Ts;

% correzione automatica se imax supera la lunghezza dei dati
if imax > size(data, 2)
    imax = size(data, 2);
end

t = data(1,imin:imax); 
xb = data(2,imin:imax); 
ic = data(3,imin:imax); 

Km_est = m*g*xb.^2 ./ ic.^2; 
Km_mean1 = mean(Km_est);

%% T21_5V


% correzione automatica se imax supera la lunghezza dei dati
if imax > size(data, 2)
    imax = size(data, 2);
end

t = data(1,imin:imax); 
xb = data(2,imin:imax); 
ic = data(3,imin:imax); 

Km_est = m*g*xb.^2 ./ ic.^2; 
Km_mean2 = mean(Km_est);

%% T21_6V
data = T21_6V;


% correzione automatica se imax supera la lunghezza dei dati
if imax > size(data, 2)
    imax = size(data, 2);
end

t = data(1,imin:imax); 
xb = data(2,imin:imax); 
ic = data(3,imin:imax); 

Km_est = m*g*xb.^2 ./ ic.^2; 
Km_mean3 = mean(Km_est);


%% T22_5V
data = T22_5V;

% correzione automatica se imax supera la lunghezza dei dati
if imax > size(data, 2)
    imax = size(data, 2);
end

t = data(1,imin:imax); 
xb = data(2,imin:imax); 
ic = data(3,imin:imax); 

Km_est = m*g*xb.^2 ./ ic.^2; 
Km_mean4 = mean(Km_est);

%% T22V
data = T22V;
% correzione automatica se imax supera la lunghezza dei dati
if imax > size(data, 2)
    imax = size(data, 2);
end

t = data(1,imin:imax); 
xb = data(2,imin:imax); 
ic = data(3,imin:imax); 

Km_est = m*g*xb.^2 ./ ic.^2; 
Km_mean5 = mean(Km_est);

%clear Km_mean1 Km_mean2 Km_mean3 Km_mean4 Km_mean5
%%
Km_mean = mean([Km_mean1, Km_mean2, Km_mean3, Km_mean4, Km_mean5]);

