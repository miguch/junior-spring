from matplotlib.pyplot import plot
import matplotlib.pyplot as plt

lr = []
r2 = []
print("Input data, end with 'end':")
while True:
    val = input()
    if val == "end":
        break
    if not val:
        continue
    num = float(val[4:])
    if val[:2] == 'lr':
        lr.append(num)
    if val[:2] == 'r2':
        r2.append(num)

x = [e for e in range(1, len(lr)+1)]
plot(x, lr, color='red')
plt.title(input("title:"))
plt.show()

x = [e for e in range(1, len(r2)+1)]
plot(x, r2, color='red')
plt.title(input("title:"))
plt.show()

