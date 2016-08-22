% Entrada
a = 0;
b = 2;
M = 1;
cant_simulaciones = 10000;

% Genero los valores de X y de Y
longitud_uniforme_x = b - a;
X = rand(1, cant_simulaciones) * longitud_uniforme_x;
Y = rand(1, cant_simulaciones) * M;

% Aplico la funcion e ^ (- x ^2) y comparo con Y
f_X = exp(-(X .^ 2));
A = Y <= f_X;

% Calculo la probabilidad y finalmente el valor de la integral
probabilidad = sum(A) / cant_simulaciones;
integral = probabilidad * longitud_uniforme_x * M
