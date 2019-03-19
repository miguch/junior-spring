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
    theta = np.zeros(shape=(features, 1)) if init is None else init
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

def z_score_scaling(x, mean_val=None, std_val=None):
    res = np.zeros(shape=x.shape)
    if mean_val is None:
        mean_val = np.mean(x, axis=0)
    if std_val is None:
        std_val = np.std(x, axis=0)
    for i in range(len(mean_val)):
        res[:, i] = (x[:, i] - mean_val[i]) / std_val[i]
    return (res, mean_val, std_val)

def min_max_scaling(x):
    min_val = np.min(x, axis=0)
    max_val = np.max(x, axis=0)
    res = np.zeros(shape=x.shape)
    for i in range(len(min_val)):
        res[:, i] = (x[:, i] - min_val[i]) / (max_val[i] - min_val[i])
    return res
