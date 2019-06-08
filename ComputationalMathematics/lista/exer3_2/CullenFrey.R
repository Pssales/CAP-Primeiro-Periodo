library(fitdistrplus)
library(rio) #Package
#Setting directory of the file
setwd("C:/Users/Camila/Desktop/CourseAppliedComputing/ComputationalMathematics/lista/exer3_2")

#Choosing the file 
MyData <- read.csv(file="C:/Users/Camila/Desktop/CourseAppliedComputing/ComputationalMathematics/lista/exer3_2/teste.csv", header=FALSE, sep=";")

#trace("descdist",edit=TRUE)

plotdist(MyData$V1, histo = TRUE, demp = TRUE) #empirical density and cumulative distribuition

#descdist(MyData$V30, boot = 1000) #Cullen and Frey graph

#summary statistics
a <- MyData$V1
fw <- fitdist(a, "weibull")
fy <- fitdist(MyData$V1, "gamma")
fw <- fitdist(MyData$V1, "lnorm")
fw <- fitdist(MyData$V1, "beta")

summary(fy)

summary(fw)

# output
# min:  1.92   max:  1.99 
# median:  1.97 
# mean:  1.96145 
# estimated sd:  0.01857749 
# estimated skewness:  -0.6130511 
# estimated kurtosis:  2.290615 

