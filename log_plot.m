clc
close all
% model_name = 'serial_5_channels.slx' ; 
model_name = 'serial_interface1.slx' ; 

% sim(model_name) ;


%% measurements 
code = 0 ; 
sim(model_name) ;
va = ScopeData.signals.values(1,:) ; 
vb = ScopeData1.signals.values(1,:) ; 
vc = ScopeData2.signals.values(1,:) ; 
ia = ScopeData3.signals.values(1,:) ; 
ib = ScopeData4.signals.values(1,:) ; 

va = remove_error(va) ; 
vb = remove_error(vb) ;
vc = remove_error(vc) ;
ia = remove_error(ia) ;
ib = remove_error(ib) ;
plot_measurements( va,vb,vc,ia, ib )

%% 
code = 12 ; 


%% plot_abc_to_alphabeta
clc
close all
code = 1 ;
% code = 4 ; % il 
sim(model_name) ;

a = ScopeData.signals.values(1,:) ; 
b = ScopeData1.signals.values(1,:) ; 
c = ScopeData2.signals.values(1,:) ; 
alpha = ScopeData3.signals.values(1,:) ; 
beta = ScopeData4.signals.values(1,:) ;
a = remove_error(a) ; 
b = remove_error(b) ;
c = remove_error(c) ;
alpha = remove_error(alpha) ;
beta = remove_error(beta) ;

plot_abc_to_alphabeta(a,b,c,alpha,beta)

%% plot_theta_estimation

alpha = ScopeData.signals.values(1,:) ; 
beta = ScopeData1.signals.values(1,:) ;
theta =  ScopeData4.signals.values(1,:) ;
plot_theta_estimation(alpha,beta,theta )

%% theta _ omega

code = 2 ;
sim(model_name) ;
theta = ScopeData.signals.values(1,:) ; 
omega = ScopeData1.signals.values(1,:) ; 
last_theta =  ScopeData2.signals.values(1,:) ; 
theta= remove_error(theta) ; 
omega= remove_error(omega) ; 
plot_theta_omega( theta, omega,last_theta  ) 


%% plot_theta_trigo

theta = ScopeData.signals.values(1,:) ;  
cos_theta = ScopeData1.signals.values(1,:) ; 
sin_theta =  ScopeData2.signals.values(1,:) ; 

plot_theta_trigo(theta,cos_theta,sin_theta)


%% plot_alphabeta_to_dq
code = 3 ; 
% code = 5 ; % iL
sim(model_name) ;
alpha = ScopeData.signals.values(1,:) ; 
beta = ScopeData1.signals.values(1,:) ;
d = ScopeData2.signals.values(1,:) ;
q = ScopeData3.signals.values(1,:) ;

q = remove_error(q) ; 
d = remove_error(d) ; 
alpha = remove_error(alpha) ; 
beta = remove_error(beta) ; 
plot_alphabeta_to_dq(alpha,beta,d,q ) 


%% plot_controller 

% code = 6 ; %  id 
code = 7 ;  % iq 
sim(model_name) ;

ref = ScopeData.signals.values(1,:) ; 
measurement = ScopeData1.signals.values(1,:) ;
out = ScopeData2.signals.values(1,:) ;

out = remove_error(out) ;
ref = remove_error(ref) ;
measurement = remove_error(measurement) ;
plot_controller(ref,measurement,out)


%% plot_dq_to_alphabeta

code = 10 ;  
sim(model_name) ;

d = ScopeData.signals.values(1,:) ;
q = ScopeData1.signals.values(1,:) ;
alpha = ScopeData2.signals.values(1,:) ; 
beta = ScopeData3.signals.values(1,:) ;
q = remove_error(q) ; 
d = remove_error(d) ; 
alpha = remove_error(alpha) ; 
beta = remove_error(beta) ; 

plot_dq_to_alphabeta(alpha,beta,d,q)

%% plot_alphabeta_to_abc
code = 11 ; 
sim(model_name) ;

alpha = ScopeData.signals.values(1,:) ; 
beta = ScopeData1.signals.values(1,:) ;
a = ScopeData2.signals.values(1,:) ; 
b = ScopeData3.signals.values(1,:) ; 
c = ScopeData4.signals.values(1,:) ; 
a = remove_error(a) ; 
b = remove_error(b) ;
c = remove_error(c) ;
alpha = remove_error(alpha) ;
beta = remove_error(beta) ;
plot_alphabeta_to_abc(a,b,c,alpha,beta )



%%










figure
%subplot(2,1,1)
plot(ScopeData.signals.values(1,:))
%subplot(2,1,2)
%%
 hold on 
 plot(ScopeData1.signals.values(1,:))
%%
%figure
hold on 
% subplot(2,1,1)
plot(ScopeData2.signals.values(1,:))

%%
% figure
% subplot(2,1,2)    
 hold on 
plot(ScopeData3.signals.values(1,:))

%%
% subplot(2,1,2)
hold on
% figure 
plot(ScopeData4.signals.values(1,:))

%%
figure
plot(ScopeData.signals.values(1,:))
hold on 
plot(ScopeData4.signals.values(1,:))


%% 
figure
subplot(2,1,1)
plot((8000-ScopeData.signals.values(1,:))*0.5)
hold on 
plot(ScopeData2.signals.values(1,:))
subplot(2,1,2)
plot(((8000-ScopeData.signals.values(1,:)))-ScopeData2.signals.values(1,:))

%% figure
figure
plot((8000-ScopeData.signals.values(1,:)))
hold on 
plot(ScopeData3.signals.values(1,:))

%%
figure 
subplot(2,1,1)
plot(ScopeData2.signals.values(1,:))
subplot(2,1,2)
plot(ScopeData3.signals.values(1,:))