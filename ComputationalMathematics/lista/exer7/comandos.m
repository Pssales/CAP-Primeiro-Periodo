serie = dlmread('..\series\S3.txt', ' ')
%serie = dlmread('..\series\S7.txt', ' ')
%serie = dlmread('..\series\S8.txt', ' ')

scmin=16;

scmax=4096;

scres=19;

exponents=linspace(log2(scmin),log2(scmax),scres);

scale=round(2.^exponents);

q=linspace(-5,5,101);

m=1;

[Hq1,tq1,alpha1,falpha1,Fq1]=MFDFA1(serie,scale,q,m,1);
