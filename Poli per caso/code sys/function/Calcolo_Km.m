function Km = Calcolo_Km(simout, segnale, theta)
% Calcolo della costante elettromagnetica Km
% acc_filt: Accelerazione filtrata (output del filtro passa-banda)
% I: Corrente misurata dal current sense
% m: Massa della sfera (costante)
% g: Accelerazione gravitazionale (costante)


tempo = segnale(1, :);        % Estrai gli istanti di tempo 
posizione =segnale(2,:);
% corrente = segnale(3,:);

acc = simout.acc;
speed = simout.speed;
corrente = simout.corrente;
g = 9.81;

% Calcolo di Km
y0 = theta(4, 1);
m = theta(3, 1);

Km = zeros(1, length(tempo));
for i = 1:length(tempo)
    Km(1,i) = m*(g+acc(i))*(y0 - (posizione(i)))^2/corrente(i)^2;
end

% Seleziona un intervallo di visualizzazione
t0 = 1.1;
tf = 1.3;

ind0 = floor(t0/0.002)+1;
indf = floor(tf/0.002)+1;

% Plot delle figure nel intervallo
figure;
plot(tempo(1, ind0:indf), Km(1, ind0:indf));
title('Stima di Km nel tempo');
xlabel('Tempo [s]');
ylabel('Km [unità]');
grid on;


figure()
plot(tempo(1, ind0:indf), acc(ind0:indf, 1)')
title('Accellerazione');
xlabel('Tempo [s]');
ylabel('acc [m/s^2]');
grid on
figure()
plot(tempo(1, ind0:indf), speed(ind0:indf, 1)')
title('Velocità');
xlabel('Tempo [s]');
ylabel('Vel [m/s]')
grid on

figure()
plot(tempo(1, ind0:indf), posizione(1, ind0:indf))
title('Posizione');
xlabel('Tempo [s]');
ylabel('Pos [m]')
grid on