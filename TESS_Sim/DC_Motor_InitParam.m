Resistance=3.25;
Te = 0.000485;
Inductance= Resistance*Te;
Inertia=9.89e-06;%0.0204;
Friction=0;%0.4206;
bEMFConstant=0.0081;%7.5E-03;
TorqueConstant=bEMFConstant;
ElectricalTimeConstant = Inductance/Resistance;
MechanicalTimeConstant = 0.0434;

%Transfer function coeficient

RiseTime = 0.16;
Wn = 1.6*pi/RiseTime;
Damp = 0.9;
Gain = 10300/8.8;
Num = Wn^2*Gain;
Den_b = 2*Damp*Wn; 
Den_c = Wn^2; 
P=0.00368;
I=0.0406;
