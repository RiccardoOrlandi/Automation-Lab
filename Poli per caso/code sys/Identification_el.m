clc
close all
clear

%%
run('Model_Parameter.m');
addpath('function');
add_data('\data\Step Test\Step Test without ball');


result = '';
R_id = 0;
L_id = 0;
%x0 = [Rtot; Lc];
x0 = [10; 0.4];

%%
test =  Test_wb_3V(:,501:end);
V0 = 3;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_6V(:,501:end);
V0 = 6;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_9V(:,501:end);
V0 = 9;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_12V(:,501:end);
V0 = 12;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_15V(:,501:end);
V0 = 15;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_18V(:,501:end);
V0 = 18;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];
%%
test =  Test_wb_21V(:,501:end);
V0 = 21;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];

%%
test =  Test_wb_23V(:,501:end);
V0 = 23;
xstar = identification_el(x0, test, V0);
R_id = [R_id; xstar(1, 1)];
L_id = [L_id; xstar(2, 1)];
result = [result, num2str(V0), '    ', num2str(xstar(1, 1)), '        ', num2str(xstar(2, 1)), newline];
%%
clc
R_mean = mean(R_id(2:end, :));
L_mean = mean(L_id(2:end, :)); 
disp('Volt  Rtot         Lc');
disp(result);

disp(['R media: ' num2str(R_mean), newline, 'L media: ', num2str(L_mean)])