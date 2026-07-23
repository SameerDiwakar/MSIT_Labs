clc;
clear;

A = 35 
B = 34 

add = A + B
disp("Addition")


sub = A - B
disp("Subtraction")


mul = A * B
disp("Multiplication")


div = A/B
disp("Division")


fac = factorial(5)
disp("Factorial of 5")


disp("Sin of 60")
disp(sin(60))

sq = sqrt(A + B)
disp("Square Root of A and B is")
disp(sq)

cb = (A+B)^3
disp("Cube of A and B is")
disp(cb)

//values = [10 20 30 40];
//labels = ["A" "B" "C" "D"];
//pie(values, labels);

//x = [1 2 3 4];
//y = [5 7 3 6];
//bar(x, y);  
//barh(x, y);  

/*theta = 0:0.1:20*%pi;   // angle values
r = theta;              // radius grows with angle
x = r .* cos(theta);
y = r .* sin(theta);
plot(x, y);*/

// Define spherical coordinates
theta = linspace(0, 2*%pi, 100);
phi   = linspace(0, %pi, 100);
[TH,PH] = ndgrid(theta, phi);

// Star radius function (spikes)
R = 1 + 0.3*sin(5*TH).*sin(5*PH);

// Convert to Cartesian coordinates
X = R .* sin(PH).*cos(TH);
Y = R .* sin(PH).*sin(TH);
Z = R .* cos(PH);

// Plot 3D star surface
clf;
plot3d(X, Y, Z, flag=[2,4,1]);   // smooth shaded surface
xtitle("3D Star Visualization");








