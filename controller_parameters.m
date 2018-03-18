
close all; clear all; clc
%***********************************************************************
% GRID / BREAKER / COMMAND
%***********************************************************************
grid_f = 50;
w = 2*pi*grid_f; % Line frequency
Urms = 400; % Line-to-line RMS voltage
Vrms = 400/sqrt(3); % Line-to-ground RMS voltage
Eg = Vrms*sqrt(2) % Phase-to-ground voltage amplitude
Rg = 1e-3; % 1e-2
Lg = 1e-5; % 1e-4
%BREAKER
Rb_open = 1e5; %ATTENTION VALUE
Rb_close = 0.01;
Cb = 1e-9 ; %Cac - ATTENTION VALUE (NEED DESIGN FILTER, avoid resonnance frequency)
%STEP breaker SW1 command : 0/1
breaker_step_time = 0.005; %Close switch at...
breaker_initial_value = 0;
breaker_final_value = 1; %Or more than 0
%IGBTs ON/OFF SIGNAL (To activate switching)
IGBTONOFF_step_time = 0.01;
IGBTONOFF_initial_value = 0;
IGBTONOFF_final_value = 1;
%***********************************************************************
% CARRIER BASED PWM PARAMETERS
%***********************************************************************
Carrier_amp = 1; % Triangular wave Amplitude
Carrier_f = 10e3; % Triangular wave frequency = Fsw
Tc = 1/Carrier_f; % Triangular wave period
%***********************************************************************
% CONVERTER PARAMETERS
%***********************************************************************
R = 0.05; % Line Resistance
L = 3e-3; % Line inductance
C = 2200e-6; % DC bus capacitor
Fsw = Carrier_f; % Converter switching frequency = Triangular wave f
Rload = 150; % Output load, Pout about 800W
Rload_temp = 1e5; % Temporary output load to avoid discharge of C
Vdc_ref = 700; % Output voltage reference
initial_condition_integrator = Vdc_ref; % IC model integrator
%***********************************************************************
% CONTROLLER PARAMETERS
%***********************************************************************
Ts = 0.5*Tc; % Sample time, half of triangular wave period, Fs = 2*Fc
Fs = 1/Ts;
%ESTIMATED PARAMETERS
R_hat = R;
L_hat = L;
C_hat = C; % probably, C_hat = C OK
Vpcc_hat = Eg ; % Ph-to-gnd - Possible for stiff grid, otherwise, Vpcc < Eg
%CURRENT PI Regulator (thesis, state-variable W=Vdc^2)
alphaI = Fs/10*2*pi; % Bandwidth in rad/s
Kpi = alphaI*L_hat
Kii = alphaI*R_hat
%VOLTAGE PI Regulator (thesis, state-variable W=Vdc^2)
alphaV = Fs/100*2*pi; % Bandwidth in rad/s
Kpv = alphaV*C_hat/(3*Vpcc_hat)
Kiv = 0.01
%SATURATION (TO MODIFY, depends on rectifier limit)
Isaturation_upper_limit = 50; %saturation on Iref, V PI controller
Isaturation_lower_limit = -50;
%FEEDFOWARD Ed_hat/Eq_hat FILTER
alphaf_ff = alphaI/10;
%***********************************************************************
% PLL PARAMETERS
%***********************************************************************
%Gain gamma1&2 : calculated in simulink (we assume Ed_hat and Eq_hat can change)
Fbandwidth_pll = 20; %bandwidth in Hz
rho_pll = 2*pi*Fbandwidth_pll; %bandwidth in rad/s
gam1 = (rho_pll^2)/Vpcc_hat
gam2 = 2*rho_pll/Vpcc_hat
%***********************************************************************
% TESTS
%***********************************************************************
%INPUT STEP
input_step_time = 0.025;
input_step_value = 100;