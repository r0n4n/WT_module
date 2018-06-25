function signal = remove_error( signal )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

% correct_signal = zeros(1,length(signal)) ;

for i=2:length(signal) 
    if (signal(i)>32768 || signal(i)< -32768 )
         signal(i) = signal( i-1) ;
%     else 
%         correct_signal(i) =  signal( i) ;
    end
end
 
end 