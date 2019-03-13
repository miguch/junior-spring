import loader
import torch
import torch.nn as nn
import torch.nn.functional as F
import pandas as pd

device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')

tl = loader.TestLoader()
test_data = torch.tensor(tl.data).to(device)

class Network(nn.Module):
    def __init__(self):
        super(Network, self).__init__()
        self.layer1 = nn.Linear(7, 35)
        self.out = nn.Linear(35, 2)

    def forward(self, x):
        o1 = F.relu(self.layer1(x))
        return F.softmax(self.out(o1), dim=1)

net = Network().to(device)
net.load_state_dict(torch.load('network.pt', map_location='cuda:0' if torch.cuda.is_available() else 'cpu'))

_, li = torch.max(net(test_data.float()), 1)
print(li)
result = [[i+892, li[i].item()] for i in range(len(li))]
print(result)
pd.DataFrame(result).to_csv('result.csv', header=['PassengerId', 'Survived'], index=False)