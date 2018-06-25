function plot_alphabeta_to_dq(alpha,beta,d,q )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

max1 = 5000 ; 


figure 
ax1 = subplot(2,1,1) ; 
plot(alpha)
hold on 
plot(beta)
ylabel('alphabeta')

% axis([0 inf -4000 4000])
ax2 = subplot(2,1,2) ; 
plot(d)
hold on 
plot(q) 
ylabel('dq')

% axis([0 inf -600 max1])

linkaxes([ax1,ax2],'x') ; 
end

