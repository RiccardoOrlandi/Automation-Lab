function cost = identification(k_mag, x0, u, Tend, theta, test, Ts_sim)
% identification - This function computes the least square error to
%   compute and estimation on k_mag
%
%   Syntax
%       cost = identification(k_mag, x0, u, Tend, theta, test, Ts_sim)
%
%   Input Arguments
%       k_mag - 
%       x0 - 
%       u - 
%       Tend - 
%       theta - 
%       test - 
%       Ts_sim -
%
%   Output Arguments
%       cost - 

theta(2,1) = k_mag;


Ts = test(1, 2) - test (1, 1); % computation of the sampling time of the sensor


[ ~, ~, sim] = FFD(Ts_sim, Tend, x0, u, theta); % simulation of the model
step = floor(Ts/Ts_sim);
sim = sim(:, 1:step:end); % alignment in case the salmplig time of the simulation is different from the one of the sensor
if length(test)<length(sim)
    N = length(test);
elseif length(test)>length(sim)
    N = length(sim);
end
% Least Square Error Evaluation
cost=0;
for i=1:1:N
    cost_add = (test(2, i) - sim(2, i))^2;
    cost = cost + cost_add;
end
