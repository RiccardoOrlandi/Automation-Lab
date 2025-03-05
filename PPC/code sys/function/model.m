function [xdot, y]= model(t, x, u, theta)

% x: column vector of 3 components [3x1]
%       x = [position, current, speed]'
%
% theta: column vector of 6 components [6x1]
%       theta = [k_aero, k_mag, m, y0, Rtot, Lc]'          
%       


k_aero = theta(1, 1);
k_mag = theta(2, 1);
m = theta(3, 1);
y0 = theta(4, 1);
Rtot= theta(5,1);
Lc= theta(6,1);

g = 9.81;

x1 = x(1, 1);
x2 = x(2, 1);
x3 = x(3, 1);





% % tentativo di inserire constraint sulla posizione che non puo essere
% % negativa
% if x1<=0 && x3>0
%     xdot1 = x3;
% 
% 
% elseif x1<=0 && x3<0
%     xdot1 = 0;
%     x3 = 0;
% 
% else
%     xdot1 = x3;
% end
% 
% xdot2 = -(Rtot/Lc)*x2 + (1/Lc)*u;
% xdot3 = - k_aero/m + k_mag/m*(x2/(y0-x1))^2 - g;



xdot1 = x3;
xdot2 = -(Rtot/Lc)*x2 + (1/Lc)*u;
xdot3 = + k_aero*x3/m + k_mag/m*(x2/(y0-x1))^2 - g;



xdot = zeros(3, 1);
xdot(1, 1) = xdot1;
xdot(2, 1) = xdot2;
xdot(3, 1) = xdot3;

y = zeros(2,1);
y(1, 1) = x1;
y(2, 1) = x2;


