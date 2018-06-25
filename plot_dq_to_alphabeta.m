function plot_dq_to_alphabeta(alpha,beta,d,q)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
figure 
ax1 = subplot(2,1,1) ; 
plot(d)
hold on 
plot(q) 
ylabel('dq')
% axis([0 inf -40000 40000])
ax2 = subplot(2,1,2) ; 
plot(alpha)
hold on 
plot(beta)
ylabel('alphabeta')
% axis([0 inf -4000 4000])

linkaxes([ax1,ax2],'x') ; 

end

