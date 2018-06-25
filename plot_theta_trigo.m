function plot_theta_trigo(theta,cos_theta,sin_theta)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
figure 
ax1 = subplot(3,1,1) ; 
plot(theta)
ylabel('theta')
axis([0 inf -5 5])

ax2 = subplot(3,1,2) ; 
plot(cos_theta)
ylabel('cos_theta')
axis([0 inf -100 100])

ax3 = subplot(3,1,3) ; 
plot(sin_theta)
ylabel('sin_theta')
axis([0 inf -100 100])

linkaxes([ax1,ax2,ax3],'x') ; 
end

