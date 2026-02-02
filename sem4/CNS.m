%unit impulse
clc;
clear all;
close all;

t = -2:1:2;
y = [zeros(1,2),ones(1,1),zeros(1,2)]'

subplot(2,2,1);
stem(t,y);
Ylabel('Amplitude');
Xlabel('(a)n')
subplot(2,2,2)
plot(t,y);

%unit step sequence [u(n) 2u (n2n)]
n = input('Enter the value');
t = 0:1:n-1
y = ones(0,1);

subplot(2,2,1);
stem(t,y);
Ylabel('Amplitude');
Xlabel('(a)n')
subplot(2,2,2)
plot(t,y);

%generation of ramp
n = input('Enter length of ramp');
t = 0:n-1

subplot(2,2,3);
stem(t,t);
Ylabel('Amplitude');
Xlabel('(a)n')
sept(2,2,4);
plot(t,t);

%exponential
n = input('Enter  ramp seq');
t = 0:n-2;
a= input('Enter the 'a' value');

subplot(2,2,4);
stem(t,y2);
Ylabel('Amplitude');
Xlabel('(a)n')

%sine signals
t = 0:0.1:pi;
y = sin(2*pi*t);
figure(2);
subplot(2,1,1);
plot(t,y);
ylabel('Amplitude');
xlabel('(a)'n);

%cosine sequence
t = 0:0.1:pi;
y = cos(2*pi*t);
figure(2);
subplot(2,1,2);
plot(t,y);
ylabel('Amplitude');
xlabel('(b)'n);

