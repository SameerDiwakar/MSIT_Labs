A = [1 2 3; 3 4 5; 5 6 7];
B = [5 6 7; 7 8 9; 3 5 8];

add = A + B;
disp("Matrix Addition:");
disp(add);

sub = A - B;
disp("Matrix Subtraction:");
disp(sub);

mul = A * B;
disp("Matrix Multiplication:");
disp(mul);

trans = A';
disp("Transpose of Matrix A:");
disp(trans);

detA = det(A);
detB = det(B);
disp("Determinant of Matrix A:");
disp(detA);
disp("Determinant of Matrix B:");
disp(detB);
