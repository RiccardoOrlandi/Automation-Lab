function [amp, deg] = prova(amp, delay, omega)

amp=amp/10;
amp_dB = 20*log10(amp);
deg = -abs(delay*omega*180/pi);

figure(1)
subplot(2,1,1)
hold on;
plot(omega, amp_dB, 'rx', 'MarkerSize', 7, 'LineWidth', 1);  % Aggiungi la "X"
hold off;

figure(1)
subplot(2,1,2)
hold on
plot(omega, deg, 'rx', 'MarkerSize', 7, 'LineWidth', 1);
hold off