import pandas
from pandas.plotting import scatter_matrix
from sklearn import model_selection
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
import serial
import numpy as np
from matplotlib import pyplot as plt
from time import time


url = "database1test.csv"
names = ['wrist','first-finger', 'second finger', 'third finger', 'fourth finger', 'fifth finger','first Contact sensor','2nd Contact sensor','3rd Contact sensor','4th Contact sensor','5th Contact sensor','6th Contact sensor','7th Contact sensor','8th Contact sensor','9th Contact sensor','10th Contact sensor','name']
dataset = pandas.read_csv(url, names=names)

# Split-out validation dataset
array = dataset.values
X = array[:,0:16]
Y = array[:,16]
validation_size = 0.20
seed = 7
X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X, Y, test_size=validation_size, random_state=seed)


# Make predictions on validation dataset
knn = KNeighborsClassifier()
knn.fit(X_train, Y_train)
predictions = knn.predict(X_validation)
print(accuracy_score(Y_validation, predictions))

#Ragib vai,I included this part to take the input directly from serial

serial_port = '/dev/cu.usbmodem14101';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
i=0
ser = serial.Serial(serial_port, baud_rate)
while True:
    line = ser.readline();
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    b=line.split(" ")
    c = [int(x) for x in b]
    if i==5:
        print (c)
        break
    i=i+1

####

#predictions = knn.predict([[270,227,264,250,180,50,1000,500,500,1000,1000]])
#predictions = knn.predict([[330,260,270,290,230,490,990,530,495,515,1050]])
predictions = knn.predict([c])
print(predictions)
