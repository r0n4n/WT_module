function plot_controller(ref,measurement,out)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
max = 800 ; 
max1 = 1000 ; 
figure 
ax1 = subplot(2,1,1) ;
plot(ref-measurement)
ylabel('error')
% axis([0 inf -max max])
ax2 = subplot(2,1,2) ; 
plot(out)
 
ylabel('out')

% axis([0 inf -max1 max1])

linkaxes([ax1,ax2],'x') ; 
end

