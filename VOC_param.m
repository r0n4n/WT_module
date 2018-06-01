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
Udcref = 120 ; % DC_link voltage (V)
Hp = 0 ;
Hq = 0 ;
fs = 100000 ; % sampling period
Ts = 1/fs ; % sampling period
fsw = 10e3 ; % Switching frequency
Tsw = Ts * 10 ;
fsw_diviser = 5 ;
alphai = 0.9*(2*pi*fs/10)  ; %(3.12 equation) 
U_Kp = 1  ;
U_Ki = 1 ; 

Id_Kp = alphai*L ;
Id_Ki = alphai*R ; % 100000

Iq_Kp = Id_Kp ;
Iq_Ki = Id_Ki ; % 1000000

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%% constant conversion %%%%%%%%%%%%%%%%
radps2rpm = 30/pi ; % rad/s to tr/min
rpm2radps = pi/30 ; % tr/min ro rad/s
wm2we = p ; % mecanical velocity to electrical velocity
radps2hz = 1/(2*pi) ; % rad/s to Hz 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

