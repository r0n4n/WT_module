close all
sim('Serial1.slx') ; 

%%
figure
hold on
plot(ScopeData.signals.values(1,:))
hold on
plot(ScopeData1.signals.values(1,:))
hold on 
plot(ScopeData2.signals.values(1,:),'*')


%%
figure
plot(ScopeData3.signals.values(1,:),'*')
hold on 
plot(ScopeData4.signals.values(1,:))
