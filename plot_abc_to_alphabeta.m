function plot_abc_to_alphabeta(a,b,c,alpha,beta )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
figure 

ax1 = subplot(2,1,1) ; 
plot(a) 
hold on
plot(b)
hold on 
plot(c) 
ylabel('abc') 
legend('a','b','c')
% axis([0 250 -4000 4000])
ax2 = subplot(2,1,2) ;
plot(alpha)
hold on 
plot(beta)
ylabel('alphabeta') 
% axis([0 250 -4000 4000])

linkaxes([ax1,ax2],'x') ; 
end

