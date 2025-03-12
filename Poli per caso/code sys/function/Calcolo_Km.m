function Km = Calcolo_Km(acc,s m, g,tempo, posizione, corrente)
% Calcolo della costante elettromagnetica Km
% acc_filt: Accelerazione filtrata (output del filtro passa-banda)
% I: Corrente misurata dal current sense
% m: Massa della sfera (costante)
% g: Accelerazione gravitazionale (costante)

% Calcolo di Km
Km = zeros(1, length(tempo));
for i:length(tempo)
    Km(1,i) = -m*(acc(i)-g)*(9e-3 - posizione(i))^2/corrente(i)^2;
end