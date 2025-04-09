function plot_Latex(x, y, x_label, y_label, Title)

figure()
plot(x,y,'LineWidth',1.5)
grid on
% xlim([0,300])
% ylim([-0.8,1.2])
title(Title,'FontSize',14,'Interpreter','latex')
xlabel(x_label,'FontSize',14,'Interpreter','latex')
ylabel(y_label,'FontSize',14,'Interpreter','latex')
% legend('q1','q2','q3','q4','FontSize',14,'Interpreter','latex')
end