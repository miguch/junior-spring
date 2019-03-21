import numpy as np

def getDistance(x, centroid):
    # Euclidean Distance
    return np.linalg.norm(x - centroid, ord=2, axis=1).reshape(x.shape[0], 1)

def getMinDistance(x, centroids):
    dist = np.full((x.shape[0], 1), np.inf)
    for c in centroids:
        curr_dist = getDistance(x, c)
        dist = np.min(np.hstack((curr_dist, dist)), axis=1).reshape(x.shape[0], 1)
    return dist

def initCentroids(x, k):
    centroids = []
    # pick the first value (from the shuffled x) as the initial mean for the first cluster
    centroids.append(x[0])
    # Select centroids for the rest of the clusters by randomly choose the instances that 
    # are most likely the farest from any of the existing centroids.
    for i in range(k - 1):
        dists = getMinDistance(x, centroids)
        newCentroid = dists.argmax()
        centroids.append(x[newCentroid])
    return centroids

def run_kmeans(x, centroids):
    reCalc = True
    dist_cluster = np.array([[np.inf, -1]] * x.shape[0])
    iters = 0
    while reCalc:
        iters += 1
        # No need to recalculate if there is no update in an iteration
        reCalc = False
        curr_dist_cluster = np.array([[np.inf, -1]] * x.shape[0])
        # find current cluster
        for i in range(len(centroids)):
            curr_dist = getDistance(x, centroids[i])
            for j in range(x.shape[0]):
                if curr_dist_cluster[j][0] > curr_dist[j][0]:
                    curr_dist_cluster[j] = [curr_dist[j][0], i]
        # check if there is an update
        for j in range(x.shape[0]):
            if dist_cluster[j][1] != curr_dist_cluster[j][1]:
                reCalc = True
        dist_cluster = curr_dist_cluster
        # Recalculate the centroids    
        centroidSum = np.array([[0 for j in range(x.shape[1])] for i in range(len(centroids))], dtype=np.float64)
        centroidCount = [0 for i in range(len(centroids))]
        for j in range(x.shape[0]):
            centroidSum[int(dist_cluster[j][1])] += x[j]
            centroidCount[int(dist_cluster[j][1])] += 1
        for i in range(len(centroids)):
            centroids[i] = centroidSum[i] / centroidCount[i]
    return centroids, dist_cluster, iters

def get_cluster(x, centroids):
    curr_dist_cluster = np.array([[np.inf, -1]] * x.shape[0])
    # find current cluster
    for i in range(len(centroids)):
        curr_dist = getDistance(x, centroids[i])
        for j in range(x.shape[0]):
            if curr_dist_cluster[j][0] > curr_dist[j][0]:
                curr_dist_cluster[j] = [curr_dist[j][0], i]
    return curr_dist_cluster[:, 1]

def kmeans(x, k, showIter=False):
    centroids = initCentroids(x, k)
    centroids, dist_cluster, iters = run_kmeans(x, centroids)
    if showIter:
        print("Iterated: %d" % iters)
    return dist_cluster[:, 1], centroids
    