function [amp, deg] = validation(test, volt, omega)


t = test(1,:);
input = 0.07*volt*sin(rad*t);


figure()
plot(t, input)
hold on
grid on
plot(t, test(3,:))

hold off

amp = input('Inserisci modulo: ')
delay = input('Inserisci fase: ')

amp = 20*log10(amp/10);
deg = -abs(delay*omega*180/pi);

figure(1)
subplot(2,1,1)
hold on;
plot(30, amp, 'rx', 'MarkerSize', 7, 'LineWidth', 1);  % Aggiungi la "X"
hold off;

figure(1)
subplot(2,1,2)
hold on
plot(30, deg, 'rx', 'MarkerSize', 7, 'LineWidth', 1);
hold off