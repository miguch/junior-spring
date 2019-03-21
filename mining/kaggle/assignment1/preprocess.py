import numpy as np

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
