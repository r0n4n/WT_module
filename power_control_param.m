clear all
clc

%%%%%%%% source voltage %%%%%%%%%%%%%%%% 
U = 311 ; % Amplitude voltage
RMS = U / sqrt(2)  ; % Phase voltage V
f=50 ; % Source voltage frequency
w=2*pi*f ; % source voltage pulsation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%% Modélisation et commande d’une génératrice
%%% Synchrone à aimants permanents dédiée
%%% à la conversion de l’énergie éolienne
%Rs = 1.137 ;
%Ls = 2.7e-3 ;
fluxeff =  0.15 ;
Ka = fluxeff ;
p = 4 ;  % nombre de paires de pôles
L = 10e-2 ; % Inductor of the source
R = 0 ; % Resistance of the source
C = 2e-2 ; % DC-link capacitor
RL = 80 ; % Load resistance
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%% Udcref controller %%%%%%%%%%%%%%%%%%%%
Udcref = 10 ; % DC_link voltage (V)
Hp = 20 ;
Hq = 0 ;
fs = 10000 ; % sampling period
Ts = 1/fs ; % sampling period
fsw = 4e3 ; % Switching frequency
Tsw = Ts * 10 ;
fsw_diviser = 0 ;
P = 1  ;
I = 0.1 ; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%% constant conversion %%%%%%%%%%%%%%%%
radps2rpm = 30/pi ; % rad/s to tr/min
rpm2radps = pi/30 ; % tr/min ro rad/s
wm2we = p ; % mecanical velocity to electrical velocity
radps2hz = 1/(2*pi) ; % rad/s to Hz 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Select switch table

% mode 1  :  http://bluebox.ippt.pan.pl/~bulletin/(54-3)287.pdf
% mode 2 : http://sci-hub.tw/http://ieeexplore.ieee.org/document/673716/


switch_table_mode = 1 ;

switch switch_table_mode
    case 1
        [ spq10, spq11, spq00, spq01] = switch_table_init1() ;
        buffer = spq10(length(),:) ; 
        for i=1: 
        
    case 2
         [ spq10, spq11, spq00, spq01] = switch_table_init2() ;
end
