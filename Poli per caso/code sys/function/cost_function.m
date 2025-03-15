function cost = cost_function(x, V0, test)

R = x(1, 1);
L = x(2, 1);
tempo = test(1, :);
modello = zeros(1, length(tempo));
cost = 0;

for i = 1:length(tempo)
    modello(1, i) = V0/R*(1-exp(1)^(-(R/L)*tempo(1, i)));
    add_cost = (modello(1, i)-test(3, i))^2;
    cost = cost + add_cost;
end