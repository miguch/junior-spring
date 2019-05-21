from matplotlib.pyplot import plot
import matplotlib.pyplot as plt

train_time = [45245, 26807, 18994, 15709, 14189, 12669, 12023, 12220, 11807, 10991, 10343, 10894]
test_time = [42, 25, 19, 16, 15, 16, 15, 16, 20, 16, 15, 15]

train_speedup = [train_time[0] / e for e in train_time]
test_speedup = [test_time[0] / e for e in test_time]

expected = [e for e in range(1, len(train_time)+1)]
x = expected
plot(x, expected, label='perfect', color='red')
plot(x, train_speedup, label='observed', color='blue')
plt.title("Train time speedup")
plt.legend(loc='upper left', borderaxespad=0.)
plt.show()

plot(x, expected, label='perfect', color='red')
plot(x, test_speedup, label='observed', color='blue')
plt.title("Test time speedup")
plt.legend(loc='upper left', borderaxespad=0.)
plt.show()
