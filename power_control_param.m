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
L = 8e-3 ; % Inductor of the source
R = 0.1 ; % Resistance of the source
C = 2350e-6 ; % DC-link capacitor
RL =120  ; % Load resistance
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%% Udcref controller %%%%%%%%%%%%%%%%%%%%
Udcref = 100 ; % DC_link voltage (V)
Hp = 0 ;
Hq = 0 ;
fs = 100000 ; % sampling period
Ts = 1/fs ; % sampling period
fsw = 4e3 ; % Switching frequency
Tsw = Ts * 10 ;
fsw_diviser = 5 ;
P = 0.1  ;
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


switch_table_mode = 3 ;

switch switch_table_mode
    case 1
        [ spq10, spq11, spq00, spq01] = switch_table_init1() ;
        
        
    case 2
        [ spq10, spq11, spq00, spq01] = switch_table_init2() ;
    case 3
        [ spq10, spq11, spq00, spq01] = switch_table_init3() ;
end

%% 
scale_time = 0.2 ; 
y_min = -1 ; 
y_max = 11 ; 