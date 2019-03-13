import pandas as pd
import numpy as np

train_path = 'data/train.csv'
test_path = 'data/test.csv'

SEX = {'male': 0, 'female': 1}
EMBARK = {'C': 1, 'Q': -1./3, 'S': 1./3}

class Passenger:
    def __init__(self, pclass, sex, age, SibSp, Parch, fare, embarked):
        self.pclass =  pclass
        self.sex = SEX[sex]
        if age != age:
            self.age = -1
        else:
            self.age = age
        self.SibSp = SibSp
        self.Parch = Parch
        if fare != fare:
            self.fare = -1
        else:
            self.fare = fare
        if embarked != embarked: #nan
            self.embarked = -1.
        else:
            self.embarked = EMBARK[embarked]
    
    def numpy(self):
        return np.array([self.pclass, self.sex, self.age, self.SibSp, self.Parch, self.fare, self.embarked], np.float64)

class TrainLoader:
    def __init__(self):
        raw = pd.read_csv(train_path)
        passengers = []
        survived = []
        for row in raw.values:
            passenger = Passenger(row[2], row[4], row[5], row[6], row[7], row[9], row[11])
            passengers.append(passenger.numpy())
            survived.append(row[1])
        self.data = np.array(passengers, np.float64)
        self.data = (self.data - self.data.mean(axis=0)) / (self.data.std(axis=0))
        self.label = np.array(survived)


class TestLoader:
    def __init__(self):
        raw = pd.read_csv(test_path)
        passengers = []
        for row in raw.values:
            passenger = Passenger(row[1], row[3], row[4], row[5], row[6], row[8], row[10])
            passengers.append(passenger.numpy())
        self.data = np.array(passengers, np.float64)
        self.data = (self.data - self.data.mean(axis=0)) / (self.data.std(axis=0))

