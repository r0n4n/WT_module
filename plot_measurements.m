function plot_measurements( va,vb,vc,ia, ib )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
figure 

ax1 = subplot(2,1,1) ; 
plot(va) 
hold on 
plot(vb)
hold on 
plot(vc) 
ylabel('ul')
% axis([0 inf -40 40])

ax2 = subplot(2,1,2) ; 
plot(ia)
hold on 
plot(ib) 
ylabel('il') 
% axis([0 inf -40 40]) 
linkaxes([ax1,ax2],'x') ; 

end

