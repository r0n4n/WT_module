function plot_theta_omega( theta, omega , last_theta )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
max = 40000 ; 
max1 = 200 ;

figure 
ax1 = subplot(2,1,1) ; 
plot(theta)
ylabel('theta')

% axis([0 inf -max max])
ax2 = subplot(2,1,2) ; 
plot(omega)

ylabel('omega')

% axis([0 inf -max1 max1])
linkaxes([ax1,ax2],'x') ; 
end

