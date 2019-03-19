import loader
import regression
import pandas as pd

ITERS = 1200
lr = 0.01

trainer = loader.TrainLoader()
x = trainer.data
y = trainer.label
data, mean, std = regression.z_score_scaling(x)
the = regression.regression(data, y, regression.logistic_h, ITERS, lr, lbd=5, log=True, logInterval=200, cost=regression.logistic_cost)

tester = loader.TestLoader()
test_data, _, _ = regression.z_score_scaling(tester.data, mean, std)

print(the)
trainer_res = regression.logistic_h(regression.z_score_scaling(trainer.data, mean, std)[0], the)
trainer_res = [1 if e > 0.5 else 0 for e in trainer_res]
accurate = 0
for i in range(len(trainer_res)):
    if trainer_res[i] == y[i]:
        accurate += 1

print(accurate / len(y))

test_res = regression.logistic_h(test_data, the)
test_res = [[i+892, 1 if test_res[i] > 0.5 else 0]  for i in range(len(test_res))]
pd.DataFrame(test_res).to_csv('regression_result.csv', header=['PassengerId', 'Survived'], index=False)

