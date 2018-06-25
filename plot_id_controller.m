function plot_id_controller(id_ref,id,id_out)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
figure 
ax1 = subplot(2,1,1) ; 
plot(id_ref-id)
ylabel('id_error')
axis([0 inf -5000 5000])
ax2 = subplot(2,1,2) ; 
plot(id_out)
 
ylabel('id_out')

axis([0 inf -5000 5000])

linkaxes([ax1,ax2],'x') ; 
end

