function plot_data(test, data_plot, t0, tend)
ts = 0.002;
offset = 0.0236;
k_b = 2.686e-3;

%k_b = 0.0044;


%ind0 = floor(t0/ts)+1;
ind0 = 1;
ind_end = floor(tend/ts)+1;
length = floor(abs(t0-tend)/ts)+1;

time = zeros(1, length);
position = zeros(1, length);
current = zeros(1, length);

%i = 1;
for ind = ind0:1:ind_end
    time(1, ind) = test(1, ind);
    position(1, ind) = (test(2, ind)+offset)*k_b;
    current(1, ind) = test(3, ind);
    
    %i = i+1;
end

if strcmp(data_plot, 'current')
    plot(time, current)
    grid on
elseif strcmp(data_plot, 'position')
    plot(time, position)
    grid on
else
    figure()
    plot(time, current)
    grid on
    title('Current')

    figure()
    plot(time, position)
    title('Position')
    grid on

end