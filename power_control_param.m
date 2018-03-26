clear all 

 

% Virtual-Flux-Based Direct Power Control of Three-Phase PWM Rectifiers 
% Table II %%%%%%%%%%%mode 1 %%%%%%%%%%%%%%%%%%

% A New DPC for Three-phase PWM rectifier with unity power factor operation
%%%%%%%%%% MODE 2 %%%%%%%%%%%%%%    


mode = 2 ; 


switch mode
    case 1
        fs = 60e3 ; % Sampling frequency
        Ts = 1/fs ; % sampling period
        
        L = 0.127e-3 ; % Inductor of the source
        R = 8e-3 ; % Resistance of the source
        C = 1e-3 ; % DC-link capacitor
        RL = 100 ; % Load resistance
        fsw = 4e3 ; % Switching frequency
        RMS = 230 ; % Phase voltage V
        U = 230*sqrt(2) ; % Amplitude voltage
        f=50 ; % Source voltage frequency
        w=2*pi*f ; % source voltage pulsation
        Udcref = 500 ; % DC_link voltage (V)
        
        Hp = 4e5 ; 
        Hq = 4e5 ;
    case 2
        
        Ts = 1e-5 ; % sampling period
        fs = 1/Ts ; % sampling period
        
        L = 10e-3 ; % Inductor of the source
        R = 0.3 ; % Resistance of the source
        C = 2e-3 ; % DC-link capacitor
        RL = 80 ; % Load resistance
        fsw = 4e3 ; % Switching frequency
        
        U = 311 ; % Amplitude voltage
        RMS = U / sqrt(2)  ; % Phase voltage V
        f=50 ; % Source voltage frequency
        w=2*pi*f ; % source voltage pulsation
        Udcref = 500 ; % DC_link voltage (V) 
        Hp = 2000 ; 
        Hq = 2000 ;
        
end
 









global sp10 sp11 sp00 sp01  


l= load('sp10.mat') ; 
sp10=l.sp10 ; 

l= load('sp11.mat') ; 
sp11=l.sp11;


l= load('sp00.mat') ; 
sp00=l.sp00 ;


l= load('sp01.mat') ; 
sp01=l.sp01 ;


