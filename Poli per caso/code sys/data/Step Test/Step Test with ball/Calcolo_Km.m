function Km = Calcolo_Km(acc,m, g,tempo, posizione, corrente)
% Calcolo della costante elettromagnetica Km
% acc_filt: Accelerazione filtrata (output del filtro passa-banda)
% I: Corrente misurata dal current sense
% m: Massa della sfera (costante)
% g: Accelerazione gravitazionale (costante)

% Calcolo di Km
offset = 0.0236;
k_b = 2.686e-3;
Km = zeros(1, length(tempo));
for i = 581:1312
    Km(1,i) = -m*(acc(i)-g)*(0.0086 - (posizione(i)+offset)*k_b)^2/corrente(i)^2;
end