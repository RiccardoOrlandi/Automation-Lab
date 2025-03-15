function Km = Calcolo_Km(simout,m, g,tempo, posizione, corrente, theta)
% Calcolo della costante elettromagnetica Km
% acc_filt: Accelerazione filtrata (output del filtro passa-banda)
% I: Corrente misurata dal current sense
% m: Massa della sfera (costante)
% g: Accelerazione gravitazionale (costante)

acc = simout.acc;
speed = simout.speed;

% Calcolo di Km
y0 = theta(4,1);
% offset = 0.0236;
% k_b = 2.686e-3;
Km = zeros(1, length(tempo));
for i = 1:length(tempo)
    Km(1,i) = m*(acc(i)+g)*(y0 - (posizione(i)))^2/corrente(i)^2;
end

% Selezione dei dati tra 1 e 2 secondi
% indice_selezionati = tempo >= 1.15 & tempo <= 1.25;
% tempo_selezionato = tempo(indice_selezionati);
% Km_selezionato = Km(indice_selezionati);

% % Visualizzazione dei risultati
% figure;
% plot(tempo_selezionato, Km_selezionato);
% title('Stima di Km nel tempo');
% xlabel('Tempo [s]');
% ylabel('Km [unità]');
% grid on;
t0 = 1.18;
tf = 1.3;
ind0 = floor(t0/0.002)+1;
indf = floor(tf/0.002)+1;

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