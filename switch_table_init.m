

spq10 =zeros(12,3) ; 
spq11 =zeros(12,3) ; 
spq00 =zeros(12,3) ; 
spq01 =zeros(12,3) ; 

% init the voltage vectors  
V0=[0 0 0] ; 
V1=[1 0 0] ; 
V2=[1 1 0] ; 
V3=[0 1 0] ; 
V4=[0 1 1] ; 
V5=[0 0 1] ; 
V6=[1 0 1] ; 
V7=[1 1 1] ; 


spq10(1,:) = V6 ;  
spq10(2,:) = V1 ; 
spq10(3,:) = V1 ; 
spq10(4,:) = V2 ; 
spq10(5,:) = V2 ; 
spq10(6,:) = V3 ; 
spq10(7,:) = V3 ; 
spq10(8,:) = V4 ; 
spq10(9,:) = V4 ; 
spq10(10,:) = V5 ; 
spq10(11,:) = V5 ; 
spq10(12,:) = V6 ;

spq11(1,:) = V7 ;  
spq11(2,:) = V7 ; 
spq11(3,:) = V0 ; 
spq11(4,:) = V0 ; 
spq11(5,:) = V7 ; 
spq11(6,:) = V7 ; 
spq11(7,:) = V0 ; 
spq11(8,:) = V0 ; 
spq11(9,:) = V7 ; 
spq11(10,:) = V7 ; 
spq11(11,:) = V0 ; 
spq11(12,:) = V0 ; 

spq00(1,:) = V1 ;  
spq00(2,:) = V2 ; 
spq00(3,:) = V2 ; 
spq00(4,:) = V3 ; 
spq00(5,:) = V3 ; 
spq00(6,:) = V4 ; 
spq00(7,:) = V4 ; 
spq00(8,:) = V5 ; 
spq00(9,:) = V5 ; 
spq00(10,:) = V6 ; 
spq00(11,:) = V6 ; 
spq00(12,:) = V1 ; 

spq01(1,:) = V2 ;  
spq01(2,:) = V2 ; 
spq01(3,:) = V3 ; 
spq01(4,:) = V3 ; 
spq01(5,:) = V4 ; 
spq01(6,:) = V4 ; 
spq01(7,:) = V5 ; 
spq01(8,:) = V5 ; 
spq01(9,:) = V6 ; 
spq01(10,:) = V6 ; 
spq01(11,:) = V1 ; 
spq01(12,:) = V1 ; 


