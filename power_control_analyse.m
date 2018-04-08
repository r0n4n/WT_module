%%%%%%%%%%%%%%%%%%% INDIVIDUAL PLOT%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% active power 
plot(p(:,1),p(:,2)) ;
title('Active power') 

%% active power 
plot(q(:,1),q(:,2)) ;
title('Reactive power') 

%% Udc 
plot(Udc_plot(:,1),Udc_plot(:,2)) ; 

%% binary_world dp

plot(binary_word.time,binary_word.signals(1).values)  ; 
axis([0 inf -0.5 1.5])
title('dp') 

%% binary_world dq 
plot(binary_word.time,binary_word.signals(2).values)  ; 
axis([0 inf -0.5 1.5])
title('dq') 

%% binary_world sector 
plot(binary_word.time,binary_word.signals(3).values)  ; 
title('Sector') 

%% error p 

plot(err_p(:,1),err_p(:,2)) ;
title('Error p') 

%% error q 

plot(err_q(:,1),err_q(:,2)) ;
title('Error q') 

%% Udc 

plot(Udc(:,1),Udc(:,2)) ;
axis([0 0.04 -20 40])
title('Udc') 
%% Uabc
plot(Uabc(:,1),Uabc(:,2)) ;
hold on 
plot(Uabc(:,1),Uabc(:,3)) ;
hold on 
plot(Uabc(:,1),Uabc(:,4)) ;
axis([0 0.04 -20 20])
title('Uabc') 

%% Iabc
plot(Iabc(:,1),Iabc(:,2)) ;
axis([0 0.04 -20 20])
hold on 
plot(Iabc(:,1),Iabc(:,3)) ;
hold on 
plot(Iabc(:,1),Iabc(:,4)) ;
axis([0 0.04 inf 6])
title('Iabc') 

%%%%%%%%%%%%%%%%%%% SUPLOT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
subplot(2,1,1)
plot(Udc_plot(:,1),Udc_plot(:,2)) ;
subplot(2,1,2) 
plot(err_p(:,1),err_p(:,2)) ;
title('Error p') 

%%
subplot(2,1,1)
plot(Udc_plot(:,1),Udc_plot(:,2)) ;
subplot(2,1,2) 
plot(err_q(:,1),err_q(:,2)) ;
title('Error q')

%% 
subplot(2,1,1) 
plot(err_q(:,1),err_q(:,2)) ;
title('Error q') 
subplot(2,1,2) 
plot(binary_word.time,binary_word.signals(2).values)  ; 
axis([0 inf -0.5 1.5])
title('dq') 


