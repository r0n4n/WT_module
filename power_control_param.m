clear all



%Virtual-Flux-Based Direct Power Control of Three-Phase PWM Rectifiers
%Table II %%%%%%%%%%%mode 1 %%%%%%%%%%%%%%%%%%

%A New DPC for Three-phase PWM rectifier with unity power factor operation
%%%%%%%%% MODE 2 %%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%% MODE 3 %%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%% WT_MODEL %%%%%%%%%%


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
        
        Ts = 1e-3 ; % sampling period
        fs = 1/Ts ; % sampling period
        
        L = 10e-2 ; % Inductor of the source
        R = 0.3 ; % Resistance of the source
        C = 2e-2 ; % DC-link capacitor
        RL = 80 ; % Load resistance
        fsw = 4e3 ; % Switching frequency
        Tsw = Ts * 10 ; 
        
        U = 311 ; % Amplitude voltage
        RMS = U / sqrt(2)  ; % Phase voltage V
        f=50 ; % Source voltage frequency
        w=2*pi*f ; % source voltage pulsation
        Udcref = 10 ; % DC_link voltage (V)
        Hp = 20 ;
        Hq = 0 ;
        p = 4 ;  % nombre de paires de pôles 
         %%%%%%%%%%%% Modélisation et commande d’une génératrice
            %%% Synchrone à aimants permanents dédiée
            %%% à la conversion de l’énergie éolienne
        Rs = 1.137 ; 
        Ls = 2.7e-3 ; 
        fluxeff =  0.15 ; 
        Ka = fluxeff ;  
    case 3
        
        Ts = 1e-5 ; % sampling period
        fs = 1/Ts ; % sampling period
        
        %%%%%%%%%%%% Modélisation et commande d’une génératrice
            %%% Synchrone à aimants permanents dédiée
            %%% à la conversion de l’énergie éolienne
        Rs = 1.137 ; 
        Ls = 2.7e-3 ; 
        fluxeff =  0.15 ; 
        Ka = fluxeff ;  
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        L = 470e-2; % Inductor of the source
        R = 0.10 ; % Resistance of the source
        %L= Ls ; 
        %R = Rs ; 
        %C = 940e-6 ; % DC-link capacitor
        %RL = 80 ; % Load resistance
        %fsw = 4e3 ; % Switching frequency
        
        U = 311 ; % Amplitude voltage
        RMS = U / sqrt(2)  ; % Phase voltage V
        f=50 ; % Source voltage frequency
        w=2*pi*f ; % source voltage pulsation
        Udcref = 500 ; % DC_link voltage (V)
        p = 4 ;  % nombre de paires de pôles  
        Hp = 10 ;
        Hq = 10 ;
        
end

radps2rpm = 30/pi ; % rad/s to tr/min 
rpm2radps = pi/30 ; % tr/min ro rad/s
wm2we = p ; % mecanical velocity to electrical velocity 
radps2hz = 1/(2*pi) ; % rad/s to Hz

%% Select switch table 

% mode 1  : http://sci-hub.tw/http://ieeexplore.ieee.org/document/673716/ 
% mode 2 : http://bluebox.ippt.pan.pl/~bulletin/(54-3)287.pdf 

switch_table_mode =1  ; 


switch switch_table_mode
    case 1
%        
%         l= load('sp10.mat') ;
%         spq10=l.sp10 ;
%         l= load('sp11.mat') ;
%         spq11=l.sp11;
%         
%         l= load('sp00.mat') ;
%         spq00=l.sp00 ;
%         
%         l= load('sp01.mat') ;
%         spq01=l.sp01 ;
        [ spq10, spq11, spq00, spq01] = switch_table_init1() ; 
    case 2
        [ spq10, spq11, spq00, spq01] = switch_table_init1() ; 
end


%%


