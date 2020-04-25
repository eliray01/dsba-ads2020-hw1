import matplotlib.pyplot as plt
import numpy as np
import csv
with open("C:\\Users\\fahre_000\\dsba-ads2020-hw1\\data\\output.csv") as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    next(csv_reader)
    Length = []
    GSM = []
    DAC = []
    Karatsuba = []
    for line in csv_reader:
        Length.append(float(line[0]))
        GSM.append(float(line[1]))
        DAC.append(float(line[2]))
        Karatsuba.append(float(line[3]))
        print (line)
GSM = sorted(GSM)
DAC = sorted(DAC)
Karatsuba = sorted(Karatsuba)
Length = sorted(Length)
plt.plot(Length, GSM, 'r')
plt.plot(Length, DAC,'k')
plt.plot(Length, Karatsuba,'b')
plt.legend(['GSM', 'DAC', 'Karatsuba'], loc='best')
plt.xlabel("Lenght")
plt.ylabel("Time")
plt.title('Working time of Algorithms')
plt.show()