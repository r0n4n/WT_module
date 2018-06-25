function plot_theta_estimation(alpha,beta,theta )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

max = 4000; 
max1 = 40000 ; 

figure 
ax1 = subplot(2,1,1) ; 
plot(alpha)
hold on 
plot(beta)
ylabel('alphabeta')
axis([0 inf -max max])

ax2 = subplot(2,1,2) ; 
plot(theta)
ylabel('theta')
axis([0 inf -max1 max1])

linkaxes([ax1,ax2],'x') ; 
end

