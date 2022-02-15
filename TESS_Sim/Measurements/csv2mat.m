csv_data = csvread('VoltSpeed_2.csv');
save('meas.mat','csv_data');
clear csv_data;
load('meas.mat')


