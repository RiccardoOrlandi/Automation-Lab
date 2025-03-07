%% Electric Model

sys_el = tf(1, [Lc, Rtot]);
bode(sys_el)
grid on
polo = Rtot/Lc;
freq_max = 100;
f = 1:freq_max; % Vettore di frequenze lineare
[H, w] = bode(sys_el, f); % Calcolo del modulo e della fase
H=reshape(H, [1,freq_max]);
figure()
%plot(f, 20*log10(abs(H))); % Grafico del modulo su scala logaritmica
plot(f, 10*abs(H)); % Grafico del modulo su scala lineare
grid on
figure()
plot(f, angle(H)*180/pi); % Grafico della fase su scala lineare
grid on;
xlabel('Frequenza [rad/s]');
ylabel('Ampiezza [lineare] e Fase [°]');
legend('Ampiezza', 'Fase');