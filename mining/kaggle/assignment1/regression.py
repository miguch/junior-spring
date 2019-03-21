import numpy as np

def logistic_cost(hx, y):
    return -np.mean((y * np.log(hx) + (1 - y) * np.log(1.00000001 - hx)))

def linear_cost(hx, y):
    return np.mean((hx - y) ** 2) / 2

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

linear_h = lambda x, theta : np.column_stack((np.ones(shape=x.shape[0]), x)).dot(theta)
logistic_h = lambda x, theta : 1/(1+np.exp(-(np.column_stack((np.ones(shape=x.shape[0]), x))).dot(theta)))

def regression(x, target, h, iters, lr, lbd=0.1, log=False, logInterval=100, init=None, cost=logistic_cost):
    samples, features = x.shape
    #xb: x with bias
    xb = np.column_stack((np.ones(shape=(x.shape[0])), x))
    features += 1
#     theta = np.zeros(shape=(features, 1)) if init is None else init
    theta = np.random.rand(features, 1) if init is None else init
    for i in range(iters):
        grad = np.zeros(shape=theta.shape)
        err = h(x, theta).reshape(samples, 1) - target
        for j in range(features):
            grad[j] = lr * np.sum(err * xb[:, j].reshape(samples,1)) / samples
            if j != 0:
                grad[j] += lr * lbd * theta[j] / samples
        theta -= grad
        if i % logInterval == 0 and log:
            print(cost(h(x, theta), target))
    return theta

