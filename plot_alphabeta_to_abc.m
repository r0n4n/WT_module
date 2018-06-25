function plot_alphabeta_to_abc(a,b,c,alpha,beta )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
max1= 400 ; 
figure 
ax1 = subplot(2,1,1) ; 
plot(alpha)
hold on 
plot(beta)
ylabel('alphabeta')
% axis([0 250 -400 400])

ax2 = subplot(2,1,2) ;
plot(a) 
hold on
plot(b)
hold on 
plot(c) 
ylabel('abc') 
% axis([0 250 -max1 max1])

linkaxes([ax1,ax2],'x') ; 
end

