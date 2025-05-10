clear 
clc 
close all

%%
%per Windows 
% addpath('..\..\..\..\..\function')
% run('..\..\..\..\..\Model_Parameter.m')
%per Mac
addpath('../../../../../function')
run('../../../../../Model_Parameter.m')
Upper_bound_V = 23;
Lower_bound_V = 0;
x1 = 0.003;
n = 3;
m = 1; 
p = 2;

[G, A, B, C, D] = lin(x1, theta);
%%
%The system is unstable and it has no zeros but the number of input is
%lower than the number of output so it cannot be enlarged
%We are interested in the position so we "reduce" the number of outputs
C1 = [1 0 0];
D1 = 0;
%% System enlargment
A_tilde = [ A,      zeros(n, 1);
            -C1,     zeros(1, 1)];
B_tilde = [ B;
            0 ];

x_max = diag([0.0012, 3, 1000, 0.1]);
u_max = 23;
Q_n = diag([0.001, 0.1, 1, 0.01]);
R_n = 10;

Q_lq = diag( (1 ./ x_max).^2 ) .* Q_n;
R_lq = diag( (1 ./ u_max).^2 ) .* R_n;

if rank(ctrb(A_tilde, B_tilde)) == 4
    disp('Il sistema allargato è completamente controllabile');
else 
    disp('Sistema non controllabile');
end

if rank(ctrb(A_tilde, sqrt(Q_lq))) == 4
    disp('Il sistema allargato è completamente osservabile');
else 
    disp('Sistema non osservabile');
end

Ken = lqr(A_tilde + 5*eye(4), B_tilde, Q_lq, R_lq);

Ken_x = Ken(:, 1:n);
Ken_eta = Ken(:, n+1:end);

